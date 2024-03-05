#pragma once
#include <cstdint>
#include <string>

class CTankInfo
{
public:
	CTankInfo(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	const uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}
	auto is_valid() -> const bool;
	auto tank_name() -> std::string;
private:
	std::uintptr_t base_address;
};

