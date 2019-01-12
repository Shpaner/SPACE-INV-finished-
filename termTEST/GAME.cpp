//
//  GAME.cpp
//  termTEST
//
//  Created by Tobiasz Witalis on 12/01/2019.
//  Copyright © 2019 Tobiasz Witalis. All rights reserved.
//

#include "GAME.hpp"

void GAME::setup()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    
    life = 5;
    czas = 0;
    BONUSczasowy1 = 5000;
    BONUSczasowy2 = 10000;
    grenades = 0;
    strzal = false;
    strzal2 = false;
    strzal3 = false;
    Bonus = true;
    Bonus2 = false;
    Granat = false;
    timeBONUS = false;
    timeBONUS2 = false;
    dir =  STOP;
    ppx  = szerokosc/2;
    ppy = wysokosc-2;
    enemyX = szerokosc/2;
    enemyY = 1;
    strzalX = ppx;
    strzalY = ppy-1;
    strzal2X = ppx;
    strzal2Y = ppy-1;
    sx = ppx;
    s2x = ppx;
    bonusX = rand() % szerokosc;
    bonusY = rand() % wysokosc+15;
    bonus2X = rand() % szerokosc;
    bonus2Y = rand() % wysokosc;
    score = 0;
}

void GAME::color(int n)
{
    start_color();
    
    if (n==1)
    {
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }
    
    if (n==2)
    {
        init_pair(2, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(2));
    }
    
    if (n==3)
    {
        init_pair(3, COLOR_BLUE, COLOR_BLACK);
        attron(COLOR_PAIR(3));
    }
    
    if (n==4)
    {
        init_pair(4, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(4));
    }
    
    if (n==5)
    {
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        attron(COLOR_PAIR(5));
    }
    
    if (n==6)
    {
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        attron(COLOR_PAIR(6));
    }
    
    if (n==0)
    {
        attroff(COLOR_PAIRS);
    }
}

void GAME::draw()
{
    strzalX = sx;
    strzal2X = s2x;
    //strzal3X = ppx;
    
    int zmiennaWysokości = 0;
    move(zmiennaWysokości,0);
    
    color(3);
    
    for (int x=0; x<szerokosc; x++)
    {
        if (x==0)
            addch(' '|A_ALTCHARSET | 108);
        else if (x==szerokosc-1)
            addch(' '|A_ALTCHARSET | 107);
        else
            //printw("-");
            addch(' '|A_ALTCHARSET | 113);
    }
    
    color(0);
    
    zmiennaWysokości++;
    move(zmiennaWysokości,0);
    for (int k=0; k<wysokosc; k++)
    {
        for (int x=0; x<szerokosc;x++)
        {
            if (x==0 || x==szerokosc-1)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            else if ((x == strzalX) && (k==strzalY) && strzal == true)
            {
                color(1);
                printw("!");
                strzalY--;
                color(0);
            }
            else if ((x == strzal2X) && (k==strzal2Y) && strzal2 == true)
            {
                color(1);
                printw("!");
                strzal2Y--;
                color(0);
            }
            else if (x==enemyX && k==enemyY)
            {
                color(4);
                addch(' '|A_ALTCHARSET | 96);
                //printw("@");
                color(0);
            }
            else if (x==ppx && k==ppy)
            {
                color(6);
                //addch(' '|A_ALTCHARSET | 97);
                printw("H");
                color(0);
            }
            else if (life==1 && x==bonusX && k==bonusY && Bonus==true)
            {
                color(5);
                addch(' '|A_ALTCHARSET | 97);
                color(0);
            }
            else if (life==1 && x==bonus2X && k==bonus2Y && Bonus2==true)
            {
                color(5);
                addch(' '|A_ALTCHARSET | 97);
                color(0);
            }
            else
                printw(" ");
        }
        
        zmiennaWysokości++;
        move(zmiennaWysokości,0);
    }
    
    color(3);
    
    for (int x=0; x<szerokosc; x++)
    {
        if (x==0)
            addch(' '|A_ALTCHARSET | 109);
        else if (x==szerokosc-1)
            addch(' '|A_ALTCHARSET | 106);
        else
            //printw("-");
            addch(' '|A_ALTCHARSET | 113);
    }
    
    color(0);
    
    zmiennaWysokości++;
    move(zmiennaWysokości,0);
    
    enemyY++;
    czas++;
}

void GAME::zapis()
{
    //ZAPIS PUNKTACJI W OSOBNYM PLIKU
    ofstream plik;
    plik.open("SCORES.txt", ios::app);
    
    if(timeBONUS == true)
        plik<<"\n"<<"SCORE: "<<score + BONUSczasowy1<<"    (BONUS CZASOWY + 5000)"<<"\n";
    
    else if (timeBONUS2 == true)
        plik<<"\n"<<"SCORE: "<<score + BONUSczasowy2<<"    (BONUS CZASOWY + 10000)"<<"\n";
    
    else
        plik<<"\n"<<"SCORE: "<<score<<"\n";
    
    plik<<"ENEMIES SHOT: "<<enemies<<"\n"<<"\n";
    plik.close();
}

void GAME::input()
{
    keypad(stdscr, true);
    halfdelay(1);
    
    int c = getch();
    
    switch(c)
    {
        case KEY_LEFT:
            dir = LEFT;
            break;
        case KEY_RIGHT:
            dir = RIGHT;
            break;
        case KEY_DOWN:
            dir = DOWN;
            break;
        case KEY_UP:
            dir = UP;
            break;
        case 's':
            if(strzal==true)
            {
                strzal2 = true;
                s2x = ppx;
            }
            else
            {
                strzal = true;
                sx = ppx;
            }
            break;
        case 'g':
            Granat = true;
            break;
        case 'q':    //   "q" - QUIT
            life = 0;
            break;
    }
}

void GAME::logic()
{
    switch (dir)
    {
        case LEFT:
            ppx--;
            strzalX--;
            strzal2X--;
            //strzal3X--;
            dir = STOP;
            break;
        case RIGHT:
            ppx++;
            strzalX++;
            strzal2X++;
            dir = STOP;
            break;
        case DOWN:
            ppy++;
            strzalY++;
            strzal2Y++;
            dir = STOP;
            break;
        case UP:
            ppy--;
            strzalY--;
            strzal2Y--;
            dir = STOP;
            break;
        default:
            break;
    }
    
    if ((ppx == enemyX && ppy == enemyY) || (ppx == enemyX && ppy == enemyY+1))
    {
        score = score - 150;
        enemyX = rand() % szerokosc;
        enemyY = 1;
        life--;
    }
    
    if (enemyY == wysokosc)
    {
        score = score - 50;
        life--;
        enemyX = rand() % szerokosc;
        enemyY = 1;
    }
    
    //KOLIZJA PIERWSZEGO NABOJU Z WROGIEM
    if ((strzalX == enemyX && strzalY == enemyY) || (strzalX == enemyX && strzalY == enemyY+1) || (strzalX == enemyX && strzalY == enemyY-1))
    {
        score = score + 200;            //PUNKTY
        enemyX = rand() % szerokosc;    //SPAWN WROGA W NOWYM MIEJSCU
        enemyY = 1;
        enemies++;
        strzal = false;
    }
    
    //KOLIZJA DRUGIEGO NABOJU Z WROGIEM
    if ((strzal2X == enemyX && strzal2Y == enemyY) || (strzal2X == enemyX && strzal2Y == enemyY+1) || (strzal2X == enemyX && strzal2Y == enemyY-1))
    {
        score = score + 200;
        enemyX = rand() % szerokosc;
        enemyY = 1;
        enemies++;
        strzal2 = false;
    }
    
    
    if (ppx == szerokosc-2 || ppy == wysokosc-1 || ppx == 1 || ppy == 0)
    {
        dir = STOP;
    }
    
    if (strzalY == 1)
    {
        strzalX = ppx;
        strzalY = ppy;
        strzal = false;
    }
    
    if (strzal2Y == 1)
    {
        strzal2X = ppx;
        strzal2Y = ppy;
        strzal2 = false;
    }
    
    if (bonusX == ppx && bonusY == ppy && Bonus == true)
    {
        life = life +3;
        bonusY = rand() % wysokosc;
        bonusX = rand() % szerokosc;
        Bonus = false;
        Bonus2 = true;
    }
    if (bonus2X == ppx && bonus2Y == ppy && Bonus2 == true)
    {
        life = life +3;
        bonusY = rand() % wysokosc;
        bonusX = rand() % szerokosc;
        Bonus = true;
        Bonus2 = false;
    }
    
    if (czas > 450)
        timeBONUS = true;
    
    if (czas > 900)
    {
        timeBONUS = false;
        timeBONUS2 =true;
    }
    
    if (Granat == true && grenades > 0)
    {
        score = score + 500;
        enemyX = rand() % szerokosc;
        enemyY = 1;
        enemies++;
        grenades--;
        Granat = false;
    }
    
    
    if (enemies == 8)
        grenades =  1;
    
    if (enemies == 15)
        grenades = 2;
    
    if (enemies == 26)
        grenades = 3;
    
    if (enemies == 40)
        grenades = 5;
    
    if (enemies == 60)
        grenades = 5;
    
    if (grenades < 0)
        grenades = 0;
    //WYJSCIE POZA MAPE
    /*if (ppx > szerokosc)
     ppx--;
     
     if (ppx < szerokosc)
     ppx++;
     
     if (ppy > wysokosc)
     ppy--;
     
     if (ppy < wysokosc)
     ppy++;*/
}

void GAME::wywolaj()
{
    setup();
    
    while (life>0)
    {
        draw();
        input();
        logic();
        
        printw("SCORE: %d | ", score);
        color(5);
        printw("LIFES LEFT: %d | ", life);
        color(0);
        printw("ENEMIES SHOT: %d ", enemies);
        printw("\n");
        color(4);
        printw("GRENADES: %d", grenades);
        color(0);
    }
    getch();
    endwin();
    zapis();
}
