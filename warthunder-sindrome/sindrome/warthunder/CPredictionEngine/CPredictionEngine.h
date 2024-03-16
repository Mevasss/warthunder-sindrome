#pragma once
#include <cstdint>
#include "../CUnit/CUnit.h"

class CPredictionEngine
{
public:
	CPredictionEngine(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	const std::uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}

	const bool operator==(CPredictionEngine engine) {
		return this->base_address == engine.base_address;
	}

	const bool operator==(CPredictionEngine* engine) {
		return this->base_address == engine->base_address;
	}

	auto is_valid() -> const bool;

	// DO NOT USE IF NO SELECTED UNIT
	auto selected_unit() -> CUnit; 

	//the predicted position relative to the player's position
	auto predicted_position() -> const Vector3; 
	auto is_unit_selected() -> const bool;
	
private:
	std::uintptr_t base_address;
};

