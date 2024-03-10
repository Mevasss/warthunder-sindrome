#include "CCamera.h"
#include "../../memory/Memory.h"
#include "../offsets.h"

auto CCamera::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CCamera::view_matrix() -> const ViewMatrix
{
	return memory->read<ViewMatrix>(this->base_address + offsets::ccamera::camera_viewmatrix);
}

auto CCamera::position() -> const Vector3
{
	return memory->read<Vector3>(this->base_address + offsets::ccamera::camera_position);
}
