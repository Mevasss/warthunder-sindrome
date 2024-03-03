#include "CHud.h"
#include "../../memory/Memory.h"
#include "../offsets.h"

auto CHud::get_instance() -> const bool
{
	return (this->base_address = memory->read<std::uintptr_t>(memory->base_address + offsets::CHud)) != 0;
}

auto CHud::penetration_crosshair(const bool enabled) -> void
{
	memory->write<bool>(this->base_address + offsets::chud::arcade_crosshair, enabled);
}

auto CHud::can_select_unit(const bool enabled) -> void
{
	memory->write<bool>(this->base_address + offsets::chud::can_select_unit, enabled);
}

auto CHud::aircraft_selection(const bool enabled) -> void
{
	memory->write<bool>(this->base_address + offsets::chud::aircraft_distance, enabled);
}

auto CHud::ground_to_air_prediction(const bool enabled) -> void
{
	memory->write<bool>(this->base_address + offsets::chud::ground_to_air_prediction, !enabled); // false to true???
}
