#ifndef AI_H
#define AI_H

#include <iostream>
#include "utils.h"
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <tuple>

//Make moves for ai
void make_ai_move(Game_board &board);

//Check if player could win
std::vector<int> could_player_win(Game_board board, int x, int y, char mark);

#endif  