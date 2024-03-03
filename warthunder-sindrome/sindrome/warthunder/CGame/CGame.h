#pragma once
#include <cstdint>
#include "../CUnit/CUnit.h"
#include "../CUnitList/CUnitList.h"

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
	
private:
	std::uintptr_t base_address;
};

