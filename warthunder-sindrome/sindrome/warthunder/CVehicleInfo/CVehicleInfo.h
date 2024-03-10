#pragma once
#include <cstdint>
#include <string>

class CVehicleInfo
{
public:
	CVehicleInfo(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	const std::uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}
	auto is_valid() -> const bool;
	auto vehice_name() -> std::string;
private:
	std::uintptr_t base_address;
};

