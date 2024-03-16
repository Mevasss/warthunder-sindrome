#pragma once
#include <cstdint>

class CHud
{
public:
	auto get_instance() -> const bool;
	auto penetration_crosshair(const bool enabled) -> void;
	auto penetration_crosshair() -> const bool;
	auto can_select_unit(const bool enabled) -> void;
	auto can_select_unit() -> const bool;
	auto aircraft_selection(const bool enabled) -> void;
	auto aircraft_selection() -> const bool;
	auto ground_to_air_prediction(const bool enabled) -> void;
	auto ground_to_air_prediction() -> const bool;
	auto vehicle_names(const bool enabled) -> void;
	auto vehicle_names() -> const bool;
private:
	std::uintptr_t base_address;
};

