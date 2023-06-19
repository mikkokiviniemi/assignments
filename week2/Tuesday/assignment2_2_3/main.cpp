/*
Group: Mikko Kiviniemi, Juho Holopainen and Elisa Harjunpää

Text based adventure game.
Create a game where a player moves around a 2D array maze.

Exercise 1:
Create a 2d array and randomly fill it with different objects. Start with a 10*10 grid. The grid is filled with cell struct that has the values cell_type.
The cell types for the game are:
'  ' for empty
O for obstacle
Print out the the game board.

Exercise 2:
Add a player with the possibility of moving around the grid by going north, west, east and south. The player can't move past an obstacle.

Exercise 3:
When the player moves to the other side of the board they have won the game. Show to the player that they have won.

Optional exercises:
Add treasures into the board. The player needs to grab 5 treasures before they can win the game. They player should be able to check how many treasures they have found during the game.
*/

#include <iostream>
#include <array>
#include "utils.h"

int main()
{   
    
    Game_board board = fill_board();
    Player player = {0,0};
    std::cout << "W = up, A = left, S = down, D = right\n";
    print_board(board,player);

    int x,y;

    bool won = false;
    while (!won)
    {
        won = move_prompt(board, player);
        system("clear");
        print_board(board,player);
    }

    std::cout << "You won!\n";
    
    

    return 0;
}
