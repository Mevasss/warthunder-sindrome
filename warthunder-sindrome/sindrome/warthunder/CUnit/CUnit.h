#pragma once
#include <cstdint>
#include "../Structs/Structs.h"
#include "../CUnitInfo/CUnitInfo.h"

class CPlayer; // FUCKING C++ MODULES IDK HOW THIS WORKS I'M IN 8 CLASS HELP ME

class CUnit
{
public:
	CUnit(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	const uintptr_t operator=(const std::uintptr_t base_address) {
		 return this->base_address = base_address;
	}

	const bool operator==(CUnit unit) {
		return this->base_address == unit.base_address;
	}

	const bool operator==(CUnit* unit) {
		return this->base_address == unit->base_address;
	}


	auto position() -> const Vector3;
	auto is_valid() -> const bool;
	auto unit_info() -> CUnitInfo;
	auto boundsmin() -> const Vector3;
	auto boundsmax() -> const Vector3;
	auto rotation_matrix() -> const Matrix3x3;
	auto reload_progress() -> const std::uint8_t;
	auto team_num() -> const std::uint8_t;
	auto team_num(const std::uint8_t team_num) -> void;
	auto player() -> CPlayer;
	auto unit_state() -> const std::uint16_t;
	auto is_alive() -> const bool;

private:
	std::uintptr_t base_address;
};


