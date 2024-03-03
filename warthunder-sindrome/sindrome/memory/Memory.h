#pragma once
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

class Memory
{
public:
	Memory(const std::string process_name)
	{
		try
		{
			process_id = get_process_id(process_name);
			process_handle = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, process_id);
			base_address = get_module_base_address(process_id, process_name);
		}
		catch (const char* message)
		{
			std::cout << message << std::endl;
		}
		catch (...)
		{
			std::cout << "[!] Some error in memory class!" << std::endl;
		}
		
	}

	~Memory()
	{
		CloseHandle(process_handle);
	}

	template <typename T>
	inline auto read(const std::uintptr_t address) -> const T
	{
		static T buffer;
		ReadProcessMemory(process_handle, reinterpret_cast<LPCVOID>(address), reinterpret_cast<LPVOID>(&buffer), sizeof(T), nullptr);
			
		return buffer;
	}

	template <typename T>
	inline auto write(const std::uintptr_t address,const T buffer) -> void
	{
		WriteProcessMemory(process_handle, reinterpret_cast<LPVOID>(address), reinterpret_cast<LPCVOID>(&buffer), sizeof(T), nullptr);
	}
	
	std::uintptr_t base_address{};

private:

	auto get_module_base_address(std::uint32_t process_id, const std::string module_name) -> const std::uintptr_t
	{
		std::uintptr_t module_base_address{ 0 };
		HANDLE snapshot_handle = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, process_id);

		if (snapshot_handle != INVALID_HANDLE_VALUE)
		{
			MODULEENTRY32 module_entry;
			module_entry.dwSize = sizeof(module_entry);
			if (Module32First(snapshot_handle, &module_entry))
			{
				do
				{
					if (!strcmp(module_entry.szModule, module_name.c_str()))
					{
						module_base_address = (std::uintptr_t)module_entry.modBaseAddr;
						break;
					}
				} while (Module32Next(snapshot_handle, &module_entry));
			}
		}

		if (snapshot_handle != INVALID_HANDLE_VALUE)
			CloseHandle(snapshot_handle);

		if (module_base_address == 0)
			throw "[!] Failed to process module base";

		return module_base_address;
	}

	auto get_process_id(const std::string process_name) -> const std::uint32_t
	{
		PROCESSENTRY32 process_entry{};
		process_entry.dwSize = sizeof(PROCESSENTRY32);

		HANDLE snapshot_handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		std::uint32_t process_id{0};
		if (Process32First(snapshot_handle, &process_entry))
		{
			do {
				if (!strcmp(process_entry.szExeFile, process_name.c_str())) {
					process_id = process_entry.th32ProcessID;
					break;
				}
					
			} while (Process32Next(snapshot_handle, &process_entry));
		}

		if (snapshot_handle != INVALID_HANDLE_VALUE)
			CloseHandle(snapshot_handle);

		if (process_id == 0)
			throw "[!] Failed to find process id";

		return process_id;
	}

	
	std::uint32_t process_id;
	HANDLE process_handle;
}; inline Memory* memory;

