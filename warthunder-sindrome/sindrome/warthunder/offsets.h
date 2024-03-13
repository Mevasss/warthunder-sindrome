#pragma once
#include <cstdint>


namespace offsets
{
	constexpr uintptr_t PlayerList = 0x4C874D8; //"on_create_replicated_entity_es" dont update // E8 ? ? ? ? 48 C7 05 ? ? ? ? ? ? ? ? 48 8D 05 ? ? ? ? 48 89 44 24 ? 48 8D 05 ? ? ? ? 48 89 44 24 ? 48 8D 44 24 ? 48 89 44 24 ? 8B 15 ? ? ? ? C7 44 24 ? ? ? ? ? 48 8D 0D ? ? ? ? 4C 8D 44 24 ? 45 31 C9 v1=
	constexpr uintptr_t CGame = 0x4D45A38;  // "DelayedActionCB @\n\t..\\..\\skyquake\\prog\\technics/warShip.cpp(615):"  0x2000 // 48 89 5C 24 ? EB 20 0F 1F 80 00 00 00 00 0x140000000
	constexpr uintptr_t LocalPlayer = 0x4DC0420; // 0x18  "managePilotControl" 403 str v39 // 0F B6 41 08 88 44 24 3A 48 8D 05 ? ? ? ? 48 89 44 24 ? 89 AC 24 ? ? ? ? 89 9C 24 ? ? ? ? 89 BC 24 ? ? ? ? 44 89 A4 24 ? ? ? ? 44 89 BC 24 ? ? ? ? 44 89 B4 24 ? ? ? ? 48 8D 74 24 ? 48 89 F1 E8 ? ? ? ? 48 89 F1 B2 FF E8 ? ? ? ? 48 8D 05 ? ? ? ? 48 89 44 24 ? 83 7C 24 ? ? 79 10 48 8B 54 24 ? 48 8B 4C 24 ? 48 8B 01 FF 50 40 90 48 81 C4 ? ? ? ? if (lp)
	constexpr uintptr_t ViewMatrix = 0x4DB2030; // "scene" F3 0F 11 4B ? F3 0F 11 43 ? F3 0F 11 63 ? F3 0F 11 5B ? F3 0F 11 53 ? F3 0F 11 6B ? 8B 2D ? ? ? ? 85 ED 74 17 C7 05 ? ? ? ? ? ? ? ? 8B 0D ? ? ? ? 31 D2 E8 ? ? ? ? 83 3D ? ? ? ? ? 0F 9C 44 24 ? 4C 8D 0D ? ? ? ? 48 89 D9 48 89 FA 41 B8 ? ? ? ? E8 ? ? ? ? 89 C7 v40 = sub(xmm)
	constexpr uintptr_t CHud = 0x4D3BF38; // 4BF6F78 "loadMod - can't init modifications playerId %d, name = %s" E8 ? ? ? ? 49 8B 95 ? ? ? ? 48 85 D2 0F 84 ? ? ? ? 48 8B 8A ? ? ? ? 8B 81 ? ? ? ? 85 C0 0F 8E ? ? ? ? 48 8B A9 ? ? ? ? 48 8B 6D 38 80 BD ? ? ? ? ? 0F 84 ? ? ? ? 48 8B 2D ? ? ? ? v75 = 
	constexpr uintptr_t Projectiles = 0x4C05FF8;
	namespace chud
	{
		constexpr uintptr_t can_select_unit = 0x20; // bool
		constexpr uintptr_t arcade_crosshair = 0x2A8; //bool
		constexpr uintptr_t aircraft_distance = 0x2AA; //bool
		constexpr uintptr_t ground_to_air_prediction = 0x2B0; //bool TO FALSE ???
		constexpr uintptr_t tank_esp = 0x1DC;  // int_8_t to 2 or bitfield 7 bit to 1 other - 0
	}
	namespace cgame
	{
		//constexpr uintptr_t unitlist1 = 0x330;
		//constexpr uintptr_t unitcount1 = 0x338;

		//constexpr uintptr_t unitlist2 = 0x340;
		//constexpr uintptr_t unitcount2 = 0x350; // int32_t

		constexpr uintptr_t unitlist3 = 0x328;
		constexpr uintptr_t unitcount3 = 0x338;

		constexpr uintptr_t prediction_sys_ptr = 0x448;

		constexpr uintptr_t camera = 0x638; // 

	}
	namespace prediction_sys
	{
		constexpr uintptr_t selected_unit = 0x628;
		constexpr uintptr_t selected_unit_prediction = 0x2050;
	}
	namespace player
	{
		constexpr uintptr_t player_unit = 0x700;
		constexpr uintptr_t GuiState = 0x1270 + 0x8; // gui
		constexpr uintptr_t name = 0xB8;
	}
	namespace unit_info
	{
		constexpr uintptr_t tank_info = 0x8;
		constexpr uintptr_t tank_info2 = 0x40;
		constexpr uintptr_t bombsight = 0x3F1;
		constexpr uintptr_t unit_type = 0x38;
	}
	namespace vehicle_info
	{
		constexpr uintptr_t vehicle_name = 0x0;
	}
	namespace ccamera
	{
		constexpr uintptr_t camera_position = 0x68;
		constexpr uintptr_t camera_viewmatrix = 0x1E8;
	}

	namespace unit
	{
		constexpr uintptr_t position = 0xBB0; // 0xBB0
		constexpr uintptr_t boundsmin = 0x310;//0x02F0 + 0x20;
		constexpr uintptr_t boundsmax = 0x31C;//0x02FC + 0x20;
		constexpr uintptr_t rotation_matrix = 0xB8C; // Matrix3x3
		constexpr uintptr_t unit_info = 0x1370;
		//constexpr uintptr_t team = 0x1048;
		constexpr uintptr_t reload_progress = 0x960; // int8_t 
		constexpr uintptr_t unit_state = 0x12F8; //int16_t 
		constexpr uintptr_t player_ptr = 0x1308;
		constexpr uintptr_t damagemodelinfo = 0x1368 + 0x20 + 0x68;
		constexpr uintptr_t team_num = 0x1360; // uint8_t
	}
}