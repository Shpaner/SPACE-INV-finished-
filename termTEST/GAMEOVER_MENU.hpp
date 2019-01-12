//
//  GAMEOVER_MENU.hpp
//  termTEST
//
//  Created by Tobiasz Witalis on 11/01/2019.
//  Copyright © 2019 Tobiasz Witalis. All rights reserved.
//

#ifndef GAMEOVER_MENU_hpp
#define GAMEOVER_MENU_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

class GAMEOVER
{
public:
    void drawM();
    void setupM();
    void logicM();
    void inputM();
    void color(int);
    void wywolaj();
    
    const int szerokoscM = 25;
    const int wysokoscM = 33;
    
    int tabelaX, tabelaY, g1x, g1y, g2x, g2y, g3x, g3y, g4x, g4y, g5x, g5y, g6x, g6y, g7x, g7y, wskaznikx, wskazniky, restartx, restarty, quitx, quity;
    
    bool gameover;
    bool otworz; //w funckji logic sprawdza po nacisnieciu spacji, czy restartowac gre, czy wyjsc.
    bool gierka = true;
    bool zakonc_petle;
    
    enum eDirection {STOP=0, UP, DOWN};
    eDirection kier;
};
#endif /* GAMEOVER_MENU_hpp */
