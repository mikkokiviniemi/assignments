#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <array>



struct Cell{
    char cell_type = ' ';

    void set_type(char type){
        cell_type = type;
    }
    
};

using Game_board = std::array<std::array<Cell, 10>, 10>;

struct Player{
    int x = 0;
    int y = 0;
    char skin = 'X';
    int points = 0;

    void move (int movex, int movey) {
        x = movex;
        y = movey;
    }
};

int randomBetween(int min, int max);

Game_board fill_board ();

bool can_move (Game_board& board, int x, int y);

bool move_prompt (Game_board& board, Player& player);

void print_board (Game_board& board, Player& player);


#endif  