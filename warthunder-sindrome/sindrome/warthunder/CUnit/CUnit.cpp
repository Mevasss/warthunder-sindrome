#include "CUnit.h"

#include "../../memory/Memory.h"
#include "../offsets.h"
#include "../CPlayer/CPlayer.h"

auto CUnit::position() -> const Vector3
{
	return memory->read<Vector3>(this->base_address + offsets::_CUnit::position);
}

auto CUnit::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CUnit::unit_info() -> CUnitInfo
{
	return CUnitInfo(memory->read<std::uintptr_t>(this->base_address + offsets::_CUnit::unit_info));
}

auto CUnit::boundsmin() -> const Vector3
{
	return memory->read<Vector3>(this->base_address + offsets::_CUnit::boundsmin);
}

auto CUnit::boundsmax() -> const Vector3
{
	return memory->read<Vector3>(this->base_address + offsets::_CUnit::boundsmax);
}

auto CUnit::rotation_matrix() -> const Matrix3x3
{
	return memory->read<Matrix3x3>(this->base_address + offsets::_CUnit::rotation_matrix);
}

auto CUnit::reload_progress() -> const std::uint8_t
{
	return memory->read<std::uint8_t>(this->base_address + offsets::_CUnit::reload_progress);
}

auto CUnit::team_num() -> const std::uint8_t
{
	return memory->read<std::uint8_t>(this->base_address + offsets::_CUnit::team_num);
}

auto CUnit::team_num(const std::uint8_t team_num) -> void
{
	memory->write<std::uint8_t>(this->base_address + offsets::_CUnit::team_num, team_num);
}

auto CUnit::player() -> CPlayer
{
	return CPlayer(memory->read<std::uintptr_t>(this->base_address + offsets::_CUnit::player_ptr));
}

auto CUnit::unit_state() -> const std::uint16_t
{
	return memory->read<std::uint16_t>(this->base_address + offsets::_CUnit::unit_state);
}

auto CUnit::is_alive() -> const bool
{
	return unit_state() != 2 && player().is_valid() ? player().gui_state() == GuiState::ALIVE : true;
}

auto CUnit::is_bot() -> const bool
{
	return !this->player().is_valid();
}
