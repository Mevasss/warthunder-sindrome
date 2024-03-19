#pragma once
#include <thread>

#include "CHud/CHud.h"
#include "CGame/CGame.h"
#include "CUnitList/CUnitList.h"
#include "CPlayer/CPlayer.h"
#include "CUnit/CUnit.h"
#include "CUnitInfo/CUnitInfo.h"
#include "CVehicleInfo/CVehicleInfo.h"
#include <iostream>
#include <vector>
#include <mutex>


class Warthunder
{
public:
	Warthunder()
	{
		try {
			c_hud = new CHud;
			if (!c_hud->get_instance())
				throw "Failed to get CHud instance";

			c_game = new CGame;
			if (!c_game->get_instance())
				throw "Failed to get CGame instance";

			local_player = new CPlayer(CPlayer::get_local());
			if (!local_player->is_valid())
				throw "Failed to get local_player instance";

			local_unit = new CUnit(local_player->unit());
			if (!local_unit->is_valid())
				throw "Failed to get local_unit instance";

			local_unit_info = new CUnitInfo(local_unit->unit_info());
			if (!local_unit_info->is_valid())
				throw "Failed to get local_unit_info instance";

			prediction_engine = new CPredictionEngine(c_game->prediciton_engine());
			if (!prediction_engine->is_valid())
				throw "Failed to get prediction_engine instance";
			
			unit_list.reserve(sizeof(CUnit) * 100);
			temp_units.reserve(sizeof(CUnit) * 100);

			std::thread loopne([&]() { // kill me please cringe coding

				while (1) {

					c_hud->get_instance();
					c_game->get_instance();
					*local_player = CPlayer::get_local();
					*local_unit = local_player->unit();
					*local_unit_info = local_unit->unit_info();
					*prediction_engine = c_game->prediciton_engine();

					const auto local_state = local_player->gui_state();
					if (local_state == GuiState::ALIVE || local_state == GuiState::SPEC || local_state == GuiState::MENU) {

						const auto unit_count = c_game->get_unit_count3();
						auto unit_list = c_game->get_unit_list3();
						if (unit_list.is_valid()) {

							for (uint32_t i = 0; i < unit_count; ++i) {
								CUnit unit = unit_list.unit(i);

								if (!unit.is_valid() || !unit.is_alive() )
									continue;
								
								temp_units.push_back(unit);
							}
						}
					}

					unit_list_mutex.lock();
					unit_list = temp_units;
					unit_list_mutex.unlock();
					temp_units.clear();

					std::this_thread::sleep_for(std::chrono::milliseconds(350));
				}
			});

			loopne.detach();

		}
		catch (const char* message) {
			std::cout << message << std::endl;
		}
		catch (...) {
			std::cout << "[!] Some error in Warthunder class" << std::endl;
		}
		
		
	}
	~Warthunder()
	{
		delete c_hud;
		delete c_game;
		delete local_player;
		delete local_unit;
		delete local_unit_info;
		delete prediction_engine;
	}

	auto view_matrix() -> const ViewMatrix;
	auto rangle() -> const RAngle;
	auto rangle(const RAngle angle) -> void;

	CHud* c_hud;
	CGame* c_game;

	CPlayer* local_player;
	CUnit* local_unit;
	CUnitInfo* local_unit_info;

	CPredictionEngine* prediction_engine;
	
	std::mutex unit_list_mutex; // bebebe
	std::vector<CUnit> unit_list;

private:
	std::vector<CUnit> temp_units;
}; inline Warthunder* warthunder;

