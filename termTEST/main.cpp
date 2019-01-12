//
//  main.cpp
//  SpaceINV
//
//  Created by Tobiasz Witalis on 04/01/2019.
//  Copyright © 2019 Tobiasz Witalis. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <fstream>

#include "START_MENU.hpp"
#include "GAMEOVER_MENU.hpp"
#include "GAME.hpp"

int main()
{
    START poczatek;
    GAME gra;
    GAMEOVER koniec;
    
    
    while (koniec.gameover == false)
    {
        if (poczatek.start == true)
            poczatek.wywolaj();
        poczatek.start = false;
    
        if (koniec.gierka == true)
            gra.wywolaj();
        koniec.gierka = false;
        koniec.zakonc_petle = false;
    
        koniec.wywolaj();
    }
return 0;
}

