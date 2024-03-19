#include <iostream>
#include <fstream> 
#include <format>
#include "sindrome/memory/Memory.h"
#include "sindrome/warthunder/Warthunder.h"

void test_offsets(Warthunder* wt);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

    memory = new Memory("aces.exe");
    Warthunder* wt = new Warthunder;

    test_offsets(wt);
  

    while (1)
    {   
        wt->unit_list_mutex.lock();
        for (auto unit : wt->unit_list) {
            //std::cout << unit.unit_info().vehicle_info().vehice_name() << std::endl;
        }
        wt->unit_list_mutex.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }


}

void test_offsets(Warthunder* wt)
{
    std::cout << "-- CHud --" << std::endl;
    bool old_penetration_crosshair = wt->c_hud->penetration_crosshair(); wt->c_hud->penetration_crosshair(!old_penetration_crosshair);
    std::cout << std::format("Penetration crosshair: {} -> {}", old_penetration_crosshair, wt->c_hud->penetration_crosshair()) << std::endl;

    bool old_aircraft_selection = wt->c_hud->aircraft_selection(); wt->c_hud->aircraft_selection(!old_aircraft_selection);
    std::cout << std::format("Aircraft selection: {} -> {}", old_aircraft_selection, wt->c_hud->aircraft_selection()) << std::endl;

    bool old_can_select_unit = wt->c_hud->can_select_unit(); wt->c_hud->can_select_unit(!old_can_select_unit);
    std::cout << std::format("Can select unit: {} -> {}", old_can_select_unit, wt->c_hud->can_select_unit()) << std::endl;

    bool old_ground_to_air_prediction = wt->c_hud->ground_to_air_prediction(); wt->c_hud->ground_to_air_prediction(!old_ground_to_air_prediction);
    std::cout << std::format("Ground to air prediction: {} -> {}", old_ground_to_air_prediction, wt->c_hud->ground_to_air_prediction()) << std::endl;

    bool old_vehicle_name = wt->c_hud->vehicle_names(); wt->c_hud->vehicle_names(!old_vehicle_name);
    std::cout << std::format("Ground to air prediction: {} -> {}", old_vehicle_name, wt->c_hud->vehicle_names()) << std::endl;

    std::cout << std::endl << "-- CGame --" << std::endl;
    std::cout << std::format("Unit count (3): {}", wt->c_game->get_unit_count3()) << std::endl;
    std::cout << std::format("Is unit list valid: {}", wt->c_game->get_unit_list3().is_valid()) << std::endl;
    std::cout << std::format("Last unit in list valid: {}", wt->c_game->get_unit_list3().unit(wt->c_game->get_unit_count3()).is_valid()) << std::endl;
    std::cout << std::format("Is local camera valid: {}", wt->c_game->local_camera().is_valid()) << std::endl;
    std::cout << std::format("Local camera position (xyz): {} {} {}", wt->c_game->local_camera().position().x, wt->c_game->local_camera().position().y, wt->c_game->local_camera().position().z) << std::endl;

    std::cout << std::endl << "-- Local player --" << std::endl;
    std::cout << std::format("Is local player valid: {}", wt->local_player->is_valid()) << std::endl;
    std::cout << std::format("Local player name: {}", wt->local_player->name()) << std::endl;
    std::cout << std::format("Local player gui state: {}", (std::uint8_t)wt->local_player->gui_state()) << std::endl;

    std::cout << std::endl << "-- Local unit --" << std::endl;
    std::cout << std::format("Is local unit valid: {}", wt->local_unit->is_valid()) << std::endl;
    std::cout << std::format("Is local unit alive: {}", wt->local_unit->is_alive()) << std::endl;
    std::cout << std::format("Is local unit bot: {}", wt->local_unit->is_bot()) << std::endl;
    std::cout << std::format("Local unit team num: {}", wt->local_unit->team_num()) << std::endl;
    std::cout << std::format("Local unit state (idk its bad): {}", wt->local_unit->unit_state()) << std::endl;
    std::cout << std::format("Local unit reload progress: {}", wt->local_unit->reload_progress()) << std::endl;
    std::cout << std::format("Local unit state position (xyz): {} {} {}", wt->local_unit->position().x, wt->local_unit->position().y, wt->local_unit->position().z) << std::endl;

    std::cout << std::endl << "-- Last unit --" << std::endl;
    std::cout << std::format("Last unit in list teamnum: {}", wt->c_game->get_unit_list3().unit(wt->c_game->get_unit_count3()).team_num()) << std::endl;

    std::cout << std::endl << "-- Local unit info --" << std::endl;
    std::cout << std::format("Is local unit info valid: {}", wt->local_unit_info->is_valid()) << std::endl;
    std::cout << std::format("Is local unit plane: {}", wt->local_unit_info->is_plane()) << std::endl;
    std::cout << std::format("Is local unit dummy: {}", wt->local_unit_info->is_dummy()) << std::endl;
    std::cout << std::format("Is enabled bombsight: {}", wt->local_unit_info->bombsight_local()) << std::endl;
    std::cout << std::format("Local unit type: {}", wt->local_unit_info->unit_type()) << std::endl;
    std::cout << std::format("Local vehicle valid: {}", wt->local_unit_info->vehicle_info().is_valid()) << std::endl;
    std::cout << std::format("Local vehicle name: {}", wt->local_unit_info->vehicle_info().vehice_name()) << std::endl;

    std::cout << std::endl << "-- Prediction engine --" << std::endl;
    std::cout << std::format("Is prediction engine valid: {}", wt->prediction_engine->is_valid()) << std::endl;
    std::cout << std::format("Is unit selected: {}", wt->prediction_engine->is_unit_selected()) << std::endl;
    std::cout << std::format("Is predicted team num (false positive when no selected unit): {}", wt->prediction_engine->selected_unit().team_num()) << std::endl;
    std::cout << std::format("Predicted position (xyz): {} {} {}", wt->prediction_engine->predicted_position().x, wt->prediction_engine->predicted_position().y, wt->prediction_engine->predicted_position().z) << std::endl;
}

