#include "CGame.h"
#include "../../memory/Memory.h"
#include "../offsets.h"

auto CGame::get_instance() -> const bool
{
	return (this->base_address = memory->read<std::uintptr_t>(memory->base_address + offsets::CGame)) != 0;
}

auto CGame::get_unit_list() -> CUnitList
{
	return CUnitList(memory->read<std::uintptr_t>(this->base_address + offsets::cgame::unitlist1));
}
auto CGame::get_unit_count() -> const std::uint32_t
{
	return memory->read<std::uint32_t>(this->base_address + offsets::cgame::unitcount1);
}
auto CGame::get_unit_list2() -> CUnitList
{
	return CUnitList(memory->read<std::uintptr_t>(this->base_address + offsets::cgame::unitlist2));
}
auto CGame::get_unit_count2() -> const std::uint32_t
{
	return memory->read<std::uint32_t>(this->base_address + offsets::cgame::unitcount2);
}
auto CGame::get_unit_list3() -> CUnitList
{
	return CUnitList(memory->read<std::uintptr_t>(this->base_address + offsets::cgame::unitlist3));
}
auto CGame::get_unit_count3() -> const std::uint32_t
{
	return memory->read<std::uint32_t>(this->base_address + offsets::cgame::unitcount3);
}

auto CGame::local_camera() -> CCamera
{
	return CCamera(memory->read<std::uintptr_t>(this->base_address + offsets::cgame::camera));
}




