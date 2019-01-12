//
//  GAME.hpp
//  termTEST
//
//  Created by Tobiasz Witalis on 12/01/2019.
//  Copyright © 2019 Tobiasz Witalis. All rights reserved.
//

#ifndef GAME_hpp
#define GAME_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <fstream>

using namespace std;

class GAME
{
public:
    bool strzal;
    bool strzal2;
    bool strzal3;
    bool Bonus;
    bool Bonus2;
    bool Granat;
    bool timeBONUS;
    bool timeBONUS2;
    const int szerokosc=25;
    const int wysokosc=33;
    int ppx, ppy, score, enemyX, enemyY, strzalX, strzalY, life, enemies, strzal2X, strzal2Y, strzal3X, strzal3Y, s2x, sx, n, bonusX, bonusY, czas, bonus2X, bonus2Y, BONUSczasowy1, grenades, BONUSczasowy2;
    enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
    eDirection dir;
    
    void setup();
    void color(int);
    void draw();
    void zapis();
    void input();
    void logic();
    void wywolaj();
};
#endif /* GAME_hpp */
