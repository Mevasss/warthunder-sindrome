#include <iostream>
#include <fstream> 
#include "sindrome/memory/Memory.h"
#include "sindrome/warthunder/Warthunder.h"


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

    memory = new Memory("aces.exe");
    Warthunder* wt = new Warthunder;
    std::fstream file("One.txt");
    while (1)
    {   
        wt->c_hud->penetration_crosshair(true);
        wt->c_hud->aircraft_selection(true);
        wt->c_hud->can_select_unit(true);
        wt->c_hud->ground_to_air_prediction(true);
        wt->c_hud->vehicle_names(true);
        
        wt->unit_list_mutex.lock();
        for (auto unit : wt->unit_list) {
            std::cout << unit.unit_info().is_plane();
        }
        wt->unit_list_mutex.unlock();

        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }


}

