#include "CTankInfo.h"
#include "../../memory/Memory.h"
#include "../offsets.h"

auto CTankInfo::is_valid() -> const bool
{
	return this->base_address != 0;
}

auto CTankInfo::tank_name() -> std::string
{
	return memory->read_string(this->base_address + offsets::tank_info2::tank_name,24);
}
