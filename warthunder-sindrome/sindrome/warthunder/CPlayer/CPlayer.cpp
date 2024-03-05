#include "CPlayer.h"
#include "../../memory/Memory.h"
#include "../offsets.h"
#include <list>

auto CPlayer::unit() -> CUnit
{
	return CUnit(memory->read<std::uintptr_t>(base_address + offsets::player::player_unit));
}

auto CPlayer::get_local() -> const std::uintptr_t
{
	return memory->read<std::uintptr_t>(memory->base_address + offsets::LocalPlayer);
}

auto CPlayer::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CPlayer::gui_state() -> const GuiState
{
	return GuiState(memory->read<uint8_t>(this->base_address + offsets::player::GuiState));
}

auto CPlayer::name() -> std::string
{
	return memory->read_string(this->base_address + offsets::player::name);
}


