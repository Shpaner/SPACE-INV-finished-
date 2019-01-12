//
//  START_MENU.cpp
//  termTEST
//
//  Created by Tobiasz Witalis on 12/01/2019.
//  Copyright © 2019 Tobiasz Witalis. All rights reserved.
//

#include "START_MENU.hpp"

void START::setup_menu()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    
    kier =  STOP;
    
    MENUclose = false;
    otworz = false;
    objective = false;
    controls = false;
    
    //POCZATEK WYSWIETLANIA NAPISU
    napisX  = 5;
    napisY = wysokoscM/2;
    
    startx = napisX;
    starty = napisY+1;
    
    wskaznikx = napisX-1;
    wskazniky = napisY+1;
    
    objX = startx;
    objY = starty+1;
    
    ctrlX = objX;
    ctrlY = objY+1;
    
    //POZYCJE GWIAZDEK
    g1x = 3;
    g1y = 4;
    
    g2x = 6;
    g2y = 1;
    
    g3x = 15;
    g3y = 8;
    
    g4x = 30;
    g4y = 12;
    
    g5x = 22;
    g5y = 30;
    
    g6x = 16;
    g6y = 20;
    
    g7x = 7;
    g7y = 25;
}

void START::color(int n)
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

void START::draw_menu()
{
    
    int zmiennaWysokości = 0;
    move(zmiennaWysokości,0);
    
    color(3);
    
    for (int x=0; x<szerokoscM; x++)
    {
        if (x==0)
            addch(' '|A_ALTCHARSET | 108);
        else if (x==szerokoscM-1)
            addch(' '|A_ALTCHARSET | 107);
        else
            //printw("-");
            addch(' '|A_ALTCHARSET | 113);
    }
    color(0);
    
    zmiennaWysokości++;
    move(zmiennaWysokości,0);
    
    for (int y=0; y<wysokoscM; y++)
    {
        for (int x=0; x<szerokoscM; x++)
        {
            if ((x==0 || x==szerokoscM-1) && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            
            else if ((x==0 || x==szerokoscM-14) && y==napisY)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            
            else if ((x==0 || x==szerokoscM-5) && y==starty)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            
            else if ((x==0 || x==szerokoscM-18) && y==objY)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            
            else if ((x==0 || x==szerokoscM-16) && y==ctrlY)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            //NAPISY
            else if (x==napisX && y==napisY)
            {
                color(2);
                printw("SPACE INVADERS");
                color(0);
            }
            
            else if (x==wskaznikx && y==wskazniky)
            {
                color(5);
                printw(">");
                color(0);
            }
            
            else if (x==startx && y==starty)
            {
                color(6);
                printw("START");
                color(0);
            }
            
            else if (x==objX && y==objY)
            {
                color(6);
                printw("MISSION OBJECTIVES");
                color(0);
            }
            
            else if (x==ctrlX && y==ctrlY)
            {
                color(6);
                printw("MISSION CONTROLS");
                color(0);
            }
            
            //GWIAZDKI
            else if (x==g1x && y==g1y && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                printw("*");
                //g1y++;
                color(0);
            }
            
            else if (x==g2x && y==g2y && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                printw("*");
                //g2y++;
                color(0);
            }
            
            else if (x==g3x && y==g3y && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                printw("*");
                //g3y++;
                color(0);
            }
            
            else if (x==g4x && y==g4y && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                printw("*");
                //g4y++;
                color(0);
            }
            
            else if (x==g5x && y==g5y && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                printw("*");
                //g5y++;
                color(0);
            }
            
            else if (x==g6x && y==g6y && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                printw("*");
                //g6y++;
                color(0);
            }
            
            else if (x==g7x && y==g7y && y!=napisY && y!=starty && y!=objY && y!=ctrlY)
            {
                color(3);
                printw("*");
                //g7y++;
                color(0);
            }
            
            else
                printw(" ");
            
        }
        zmiennaWysokości++;
        move(zmiennaWysokości,0);
    }
    
    color(3);
    
    for (int x=0; x<szerokoscM; x++)
    {
        if (x==0)
            addch(' '|A_ALTCHARSET | 109);
        else if (x==szerokoscM-1)
            addch(' '|A_ALTCHARSET | 106);
        else
            //printw("-");
            addch(' '|A_ALTCHARSET | 113);
    }
    color(0);
    
    zmiennaWysokości++;
    move(zmiennaWysokości,0);
    
    g1y++;
    g2y++;
    g3y++;
    g4y++;
    g5y++;
    g6y++;
    g7y++;
    
}

void START::input_menu()
{
    keypad(stdscr, true);
    halfdelay(1);
    
    int d = getch();
    
    switch(d)
    {
        case KEY_DOWN:
            kier = DOWN;
            break;
        case KEY_UP:
            kier = UP;
            break;
        /*case 'q':
            MENUclose=true;
            break;*/
        case 10:
            otworz = true;
            break;
            
    }
}

void START::logic_menu()
{
    switch (kier)
    {
        case DOWN:
            wskazniky++;
            kier = STOP;
            break;
        case UP:
            wskazniky--;
            kier = STOP;
            break;
        default:
            break;
    }
    
    if (otworz==true && wskazniky==objY)
    {
        controls = false;
        objective = true;
        otworz = false;
    }
    
    if (otworz==true && wskazniky==ctrlY)
    {
        objective = false;
        controls = true;
        otworz = false;
    }
    
    if (otworz==true && wskazniky==starty)
        MENUclose = true;
    
    
    if (g1y==wysokoscM)
    {
        g1x = rand() % szerokoscM;
        g1y = 1;
    }
    
    if (g2y==wysokoscM)
    {
        g2x = rand() % szerokoscM;
        g2y = 1;
    }
    
    if (g3y==wysokoscM)
    {
        g3x = rand() % szerokoscM;
        g3y = 1;
    }
    
    if (g4y==wysokoscM)
    {
        g4x = rand() % szerokoscM;
        g4y = 1;
    }
    
    if (g5y==wysokoscM)
    {
        g5x = rand() % szerokoscM;
        g5y = 1;
    }
    
    if (g6y==wysokoscM)
    {
        g6x = rand() % szerokoscM;
        g6y = 1;
    }
    
    if (g7y==wysokoscM)
    {
        g7x = rand() % szerokoscM;
        g7y = 1;
    }
    
    if (wskazniky > ctrlY)
        wskazniky--;
    
    if (wskazniky < starty)
        wskazniky++;
}

void START::cel()
{
    printw("The objective of the game is to shoot down as many enemies (aliens) as possible!");
    printw("\n");
    printw("During your battle collect extra lifes (pink rectangles) to stay alive, because the longer you play the higher will be your 'time bonus'.");
    printw("\n");
    printw("You will also be provided with grenades which you can use from any part of the map, to destroy one enemy.");
    printw("\n");
    printw("The more enemies you kill the more grenades you'll be awarded with!");
    printw("\n");
    printw("Your scores will be stored in the document called 'SCORES.txt'");
    
}

void START::sterowanie()
{
    printw("Move your ship around by using arrows.");
    printw("\n");
    printw("Shoot by clicking 's' on you keyboard.");
    printw("\n");
    printw("Use grenades by clicking 'g'.");
    printw("\n");
    printw("Click 'q' to quit the game");
    printw("\n");
    printw("\n");
}

void START::wywolaj()
{
setup_menu();

while (MENUclose == false)
{
    draw_menu();
    input_menu();
    logic_menu();
    if (objective == true)
        cel();
        if (controls == true)
            sterowanie();
            }
getch();
endwin();
}
