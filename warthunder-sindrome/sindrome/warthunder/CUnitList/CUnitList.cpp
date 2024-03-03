#include "CUnitList.h"
#include "../../memory/Memory.h"
#include "../offsets.h"

auto CUnitList::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CUnitList::unit(const std::uint16_t idx) -> CUnit
{
	return CUnit(memory->read<std::uintptr_t>(this->base_address + 0x8 * idx));
}
