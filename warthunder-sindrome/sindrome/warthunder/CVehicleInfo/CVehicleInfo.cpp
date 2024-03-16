#include "CVehicleInfo.h"
#include "../../memory/Memory.h"
#include "../offsets.h"

auto CVehicleInfo::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CVehicleInfo::vehice_name() -> std::string
{
	return memory->read_string(this->base_address + offsets::_CVehiceInfo::vehicle_name);
}

