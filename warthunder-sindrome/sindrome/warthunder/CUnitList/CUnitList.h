#pragma once
#include <cstdint>
#include "../CUnit/CUnit.h"

class CUnitList
{
public:
	CUnitList(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	const std::uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}

	auto is_valid() -> const bool;
	auto unit(const std::uint16_t idx) -> CUnit;

private:
	std::uintptr_t base_address;
};

