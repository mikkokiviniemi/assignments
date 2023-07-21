#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <tuple>

struct Cell{
    char cell_type = ' ';

    void set_type(char type){
        cell_type = type;
    }
    
};

using Game_board = std::array<std::array<Cell, 3>, 3>;

//Fills board with empty cells
Game_board fill_board ();

//Adds mark to board
void add_mark(Game_board &board, int row, int col, char mark);

//Check if you can make move
bool can_make_move(Game_board &board, int x, int y);

//Check if spesific mark has won
bool has_won(Game_board &board, char mark);

//Generates random number
int randomBetween(int min, int max);

//Asks move from player
void make_move(Game_board &board);

//Prints board
void print_board (Game_board& board);

//Check if gameboard is full
bool check_tie(Game_board &board);

#endif  