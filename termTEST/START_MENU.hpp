//
//  START_MENU.hpp
//  termTEST
//
//  Created by Tobiasz Witalis on 12/01/2019.
//  Copyright © 2019 Tobiasz Witalis. All rights reserved.
//

#ifndef START_MENU_hpp
#define START_MENU_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

class START
{
public:
    int szerokoscM = 25;
    int wysokoscM = 33;
    
    int napisX, napisY, g1x, g1y, g2x, g2y, g3x, g3y, g4x, g4y, g5x, g5y, g6x, g6y, g7x, g7y, wskaznikx, wskazniky, startx, starty, objX, objY, ctrlX, ctrlY;
    
    bool MENUclose;
    bool otworz; //w funckji logic sprawdza po nacisnieciu spacji, czy restartowac gre, czy wyjsc.
    bool objective;
    bool controls;
    bool start = true;
    
    enum Direction {STOP=0, UP, DOWN};
    Direction kier;
    
    void setup_menu();
    void draw_menu();
    void input_menu();
    void logic_menu();
    void cel();
    void sterowanie();
    void color(int);
    void wywolaj();
};
#endif /* START_MENU_hpp */
