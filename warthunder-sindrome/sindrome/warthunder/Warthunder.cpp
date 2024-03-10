#include "Warthunder.h"
#include "../memory/Memory.h"
#include "offsets.h"

const ViewMatrix Warthunder::view_matrix()
{
	return memory->read<ViewMatrix>(memory->base_address + offsets::ViewMatrix);
}
