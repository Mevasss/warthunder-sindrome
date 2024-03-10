#pragma once
#include <cstdint>
#include "../Structs/Structs.h"

class CCamera
{
public:
	CCamera(const std::uintptr_t base_address = 0) : base_address(base_address) {}

	const std::uintptr_t operator=(const std::uintptr_t base_address) {
		return this->base_address = base_address;
	}

	auto is_valid() -> const bool;
	auto view_matrix() -> const ViewMatrix;
	auto position() -> const Vector3;

private:
	std::uintptr_t base_address;
};

