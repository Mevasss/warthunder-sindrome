#include <iostream>
#include "sindrome/memory/Memory.h"
#include "sindrome/warthunder/Warthunder.h"


int main()
{
    memory = new Memory("aces.exe");
    Warthunder* wt = new Warthunder;
    while (1)
    {
      
        for (auto unit : wt->unit_list) {
            unit.team_num(wt->local_unit->team_num());
            std::cout << "Is local: " << (unit == wt->local_unit) <<  " " << unit.position().x << " " << unit.position().y << " " << unit.position().z << std::endl;
            
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }


}

