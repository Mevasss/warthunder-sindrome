#pragma once
#include <cstdint>

class CHud
{
public:
	auto get_instance() -> const bool;
	auto penetration_crosshair(const bool enabled) -> void;
	auto can_select_unit(const bool enabled) -> void;
	auto aircraft_selection(const bool enabled) -> void;
	auto ground_to_air_prediction(const bool enabled) -> void;
	auto vehicle_names(const bool enabled) -> void;
private:
	std::uintptr_t base_address;
};

