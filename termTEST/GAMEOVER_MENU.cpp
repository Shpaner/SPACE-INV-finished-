//
//  GAMEOVER_MENU.cpp
//  termTEST
//
//  Created by Tobiasz Witalis on 11/01/2019.
//  Copyright © 2019 Tobiasz Witalis. All rights reserved.
//

#include "GAMEOVER_MENU.hpp"

void GAMEOVER::setupM()
{
    initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    
    kier =  STOP;
    
    gameover = false;
    otworz = false;
    gierka = true;
    bool zakoncz_petle = false;
    
    //POCZATEK WYSWIETLANIA NAPISU
    tabelaX  = 7;
    tabelaY = wysokoscM/2;
    
    restartx = tabelaX;
    restarty = tabelaY+1;
    
    wskaznikx = tabelaX-1;
    wskazniky = tabelaY+1;
    
    quitx = restartx;
    quity = restarty+1;
    
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

void GAMEOVER::color(int n)
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

void GAMEOVER::drawM()
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
            if ((x==0 || x==szerokoscM-1) && y!=tabelaY && y!=restarty && y!=quity)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            
            else if ((x==0 || x==szerokoscM-9) && y==tabelaY)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            
            else if ((x==0 || x==szerokoscM-12) && y==restarty)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            
            else if ((x==0 || x==szerokoscM-8) && y==quity)
            {
                color(3);
                //printw("|");
                addch(' '|A_ALTCHARSET | 120);
                color(0);
            }
            //NAPISY
            else if (x==tabelaX && y==tabelaY)
            {
                color(2);
                printw("GAME OVER");
                color(0);
            }
            
            else if (x==wskaznikx && y==wskazniky)
            {
                color(5);
                printw(">");
                color(0);
            }
            
            else if (x==restartx && y==restarty)
            {
                color(6);
                printw("RESTART GAME");
                color(0);
            }
            
            else if (x==quitx && y==quity)
            {
                color(6);
                printw("QUITGAME");
                color(0);
            }
            
            //GWIAZDKI
            else if (x==g1x && y==g1y && y!=tabelaY && y!=restarty && y!=quity)
            {
                color(3);
                printw("*");
                //g1y++;
                color(0);
            }
            
            else if (x==g2x && y==g2y && y!=tabelaY && y!=restarty && y!=quity)
            {
                color(3);
                printw("*");
                //g2y++;
                color(0);
            }
            
            else if (x==g3x && y==g3y && y!=tabelaY && y!=restarty && y!=quity)
            {
                color(3);
                printw("*");
                //g3y++;
                color(0);
            }
            
            else if (x==g4x && y==g4y && y!=tabelaY && y!=restarty && y!=quity)
            {
                color(3);
                printw("*");
                //g4y++;
                color(0);
            }
            
            else if (x==g5x && y==g5y && y!=tabelaY && y!=restarty && y!=quity)
            {
                color(3);
                printw("*");
                //g5y++;
                color(0);
            }
            
            else if (x==g6x && y==g6y && y!=tabelaY && y!=restarty && y!=quity)
            {
                color(3);
                printw("*");
                //g6y++;
                color(0);
            }
            
            else if (x==g7x && y==g7y && y!=tabelaY && y!=restarty && y!=quity)
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

void GAMEOVER::inputM()
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
        case 10:
            otworz = true;
            break;
            
    }
}

void GAMEOVER::logicM()
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
    
    if (otworz==true && wskazniky==quity)
    {
        zakonc_petle = true;
        gameover = true;
    }
    
    if (otworz==true && wskazniky==restarty)
    {
        zakonc_petle = true;
        gierka = true;
    }
    
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
    
    if (wskazniky > quity)
        wskazniky--;
    
    if (wskazniky < restarty)
        wskazniky++;
}

void GAMEOVER::wywolaj()
{
    setupM();
     
     while (zakonc_petle == false)
     {
     drawM();
     inputM();
     logicM();
     }
     getch();
     endwin();
}
