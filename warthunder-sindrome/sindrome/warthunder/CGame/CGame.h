#pragma once
#include <cstdint>
#include "../CUnit/CUnit.h"
#include "../CUnitList/CUnitList.h"
#include "../CCamera/CCamera.h"

class CGame
{
public:
	auto get_instance() -> const bool;

	auto get_unit_list() -> CUnitList;
	auto get_unit_count() -> const std::uint32_t;

	auto get_unit_list2() -> CUnitList;
	auto get_unit_count2() -> const std::uint32_t;

	auto get_unit_list3() -> CUnitList;
	auto get_unit_count3() -> const std::uint32_t;

	auto local_camera() -> CCamera;
	
private:
	std::uintptr_t base_address;
};

