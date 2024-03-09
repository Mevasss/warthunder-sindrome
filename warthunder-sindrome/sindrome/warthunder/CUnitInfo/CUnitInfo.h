#pragma once
#include <cstdint>
#include <string>
#include "../CVehicleInfo/CVehicleInfo.h"

class CUnitInfo
{
public:
	CUnitInfo(const std::uintptr_t base_address = 0) : base_address(base_address) { }

	const uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}
	auto bombsight_local(const bool enabled) -> void;
	auto is_valid() -> const bool;
	auto unit_type() -> std::string;
	auto vehicle_info() -> CVehicleInfo;
	auto is_plane() -> const bool;
	auto is_dummy() -> const bool;
private:
	std::uintptr_t base_address;
};

