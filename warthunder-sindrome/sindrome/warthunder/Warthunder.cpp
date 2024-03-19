#include "Warthunder.h"
#include "../memory/Memory.h"
#include "offsets.h"

auto Warthunder::view_matrix() -> const ViewMatrix
{
	return memory->read<ViewMatrix>(memory->base_address + offsets::ViewMatrix);
}
auto Warthunder::rangle() -> const RAngle
{
	return memory->read<RAngle>(memory->base_address + offsets::YawOffset);
}
auto Warthunder::rangle(const RAngle angle) -> void
{
	memory->write<RAngle>(memory->base_address + offsets::YawOffset, angle);
}

