#include "CUnit.h"

#include "../../memory/Memory.h"
#include "../offsets.h"
#include "../CPlayer/CPlayer.h"

auto CUnit::position() -> const Vector3
{
	return memory->read<Vector3>(this->base_address + offsets::unit::position);
}

auto CUnit::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CUnit::unit_info() -> CUnitInfo
{
	return CUnitInfo(memory->read<std::uintptr_t>(this->base_address + offsets::unit::unit_info));
}

auto CUnit::boundsmin() -> const Vector3
{
	return memory->read<Vector3>(this->base_address + offsets::unit::boundsmin);
}

auto CUnit::boundsmax() -> const Vector3
{
	return memory->read<Vector3>(this->base_address + offsets::unit::boundsmax);
}

auto CUnit::rotation_matrix() -> const Matrix3x3
{
	return memory->read<Matrix3x3>(this->base_address + offsets::unit::rotation_matrix);
}

auto CUnit::reload_progress() -> const std::uint8_t
{
	return memory->read<std::uint8_t>(this->base_address + offsets::unit::reload_progress);
}

auto CUnit::team_num() -> const std::uint8_t
{
	return memory->read<std::uint8_t>(this->base_address + offsets::unit::team_num);
}

auto CUnit::team_num(const std::uint8_t team_num) -> void
{
	memory->write<std::uint8_t>(this->base_address + offsets::unit::team_num, team_num);
}

auto CUnit::player() -> CPlayer
{
	return CPlayer(memory->read<std::uintptr_t>(this->base_address + offsets::unit::player_ptr));
}

auto CUnit::unit_state() -> const std::uint16_t
{
	return memory->read<std::uint16_t>(this->base_address + offsets::unit::unit_state);
}

auto CUnit::is_alive() -> const bool
{
	auto unit_state_ = unit_state();
	return is_valid() && unit_state_ != 2 && unit_state_ != 4 && player().gui_state() == GuiState::ALIVE && memory->read<float>(this->base_address + offsets::unit::position) != 0.f;
}
