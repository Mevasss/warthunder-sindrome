#include "CVehicleInfo.h"
#include "../../memory/Memory.h"
#include "../offsets.h"

auto CVehicleInfo::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CVehicleInfo::tank_name() -> std::string
{
	return memory->read_string(this->base_address + offsets::tank_info2::tank_name);
}
