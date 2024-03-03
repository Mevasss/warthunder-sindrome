#pragma once
#include <cstdint>
#include "../Structs/Structs.h"
#include "../CUnit/CUnit.h"


class CPlayer
{
public:

	CPlayer(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}

	auto unit() -> CUnit;
	static auto get_local() -> const std::uintptr_t;
	auto is_valid() -> const bool;
	auto gui_state() -> const GuiState;
private:
	std::uintptr_t base_address;
};

