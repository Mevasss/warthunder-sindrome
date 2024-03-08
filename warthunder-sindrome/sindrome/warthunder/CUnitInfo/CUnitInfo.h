#pragma once
#include <cstdint>
#include <string>
#include "../CVehicleInfo/CVehicleInfo.h"

class CUnitInfo
{
public:
	CUnitInfo(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	const uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}
	auto bombsight_local(const bool enabled) -> void;
	auto is_valid() -> const bool;
	auto tank_info() -> CVehicleInfo;
private:
	std::uintptr_t base_address;
};

