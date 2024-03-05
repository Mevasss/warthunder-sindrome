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

        for (auto unit : wt->unit_list) {
            if (unit.team_num() != wt->local_unit->team_num() ) 
                std::cout << unit.player().name() << " " << unit.unit_info().tank_info().tank_name() << std::endl;
            //have troubles to cout russian names to console, but it is normal string -- test to file
            std::cout << unit.player().name() << " " << unit.unit_info().tank_info().tank_name() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }


}

