#pragma once
#include <cstdint>


namespace offsets
{
	//48 8B 05 ? ? ? ? F2 0F 10 4F 08
	constexpr uintptr_t CGame = 0x4D46A88;
	//48 8B 05 ? ? ? ? 48 85 C0 74 EA
	constexpr uintptr_t LocalPlayer = 0x4DC1470;
	//4C 8D 2D ? ? ? ? 4C 8D 25 ? ? ? ? EB 39 
	constexpr uintptr_t ViewMatrix = 0x4DB3070;
	//48 8B 05 ?? ?? ?? ?? 0F B6 88 A9 00 00 00
	constexpr uintptr_t CHud = 0x4D3CF38;
	//F3 0F 10 35 ?? ?? ?? ?? F3 44 0F 10 15 ?? ?? ?? ?? F3 0F 10 05
	constexpr uintptr_t YawOffset = 0x4D40248;

	namespace _CHud
	{
		constexpr uintptr_t can_select_unit = 0x20; // bool
		constexpr uintptr_t arcade_crosshair = 0x2A8; //bool
		constexpr uintptr_t aircraft_distance = 0x2AA; //bool
		constexpr uintptr_t ground_to_air_prediction = 0x2B0; //bool TO FALSE ???
		constexpr uintptr_t air_to_air_prediction = 0x29D;
		constexpr uintptr_t tank_esp = 0x1DC;  // int_8_t to 2 or bitfield 7 bit to 1 other - 0
	}
	namespace _CGame
	{
		constexpr uintptr_t unit_list3 = 0x328;
		constexpr uintptr_t unit_count3 = 0x338;
		constexpr uintptr_t prediction_engine_ptr = 0x418;
		constexpr uintptr_t local_camera = 0x608;

	}
	namespace _CPredictionEngine
	{
		constexpr uintptr_t selected_unit = 0x628;
		constexpr uintptr_t selected_unit_prediction = 0x2058;
	}
	namespace _CPlayer
	{
		constexpr uintptr_t player_unit = 0x700;
		constexpr uintptr_t gui_state = 0x500; // gui
		constexpr uintptr_t name = 0xB8;
	}
	namespace _CUnitInfo
	{
		constexpr uintptr_t tank_info = 0x8;
		constexpr uintptr_t tank_info2 = 0x28;
		constexpr uintptr_t bombsight = 0x3F1;
		constexpr uintptr_t unit_type = 0x38;
	}
	namespace _CVehiceInfo
	{
		constexpr uintptr_t vehicle_name = 0x0;
	}
	namespace _CCamera
	{
		constexpr uintptr_t camera_position = 0x68;
		constexpr uintptr_t camera_viewmatrix = 0x1E8;
	}

	namespace _CUnit
	{
		constexpr uintptr_t position = 0xBB0; // 0xBB0
		constexpr uintptr_t boundsmin = 0x310;//0x02F0 + 0x20;
		constexpr uintptr_t boundsmax = 0x31C;//0x02FC + 0x20;
		constexpr uintptr_t rotation_matrix = 0xB8C; // Matrix3x3
		constexpr uintptr_t unit_info = 0x1358;
		constexpr uintptr_t reload_progress = 0x960; // int8_t 
		constexpr uintptr_t unit_state = 0x12E0; //int16_t 
		constexpr uintptr_t player_ptr = 0x12F0;
		//constexpr uintptr_t damagemodelinfo = 0x1368 + 0x20 + 0x68 - 0x18;
		constexpr uintptr_t team_num = 0x1348; // uint8_t
	}
}