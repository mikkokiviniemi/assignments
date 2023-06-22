/*
Group: Mikko Kiviniemi, Juho Holopainen and Elisa Harjunpää

Group assignment.

You are going to create a tic tac toe game that you can play against another player or an AI opponent.

You can create the board as a console application and you can have each player represented by a O or an X.

You can have the opponent choose randomly where it will place its next move, or you can implement an algorithm to calculate the best move it could play.

One such algorithm is called Minimax algorithm that will go trough all the possible moves and then choose the best one.
*/

#include <iostream>
#include <array>
#include "utils.h"
#include "ai.h"

int main()
{   
    
    Game_board board = fill_board();

    int index = randomBetween(0,1);

    std::string winner;

    while (true) {

        if(index % 2 == 0){
            print_board(board);
            make_move(board);
            if(has_won(board,'X')){
                winner = "Player";
            }
        }else {
            make_ai_move(board);
            if(has_won(board,'O')){
                winner = "AI";
            }
        }

        if(check_tie(board)) {
            winner = "Tie";
        }

        if(winner.size() != 0) {
            print_board(board);
            if(winner == "Tie") {
                std::cout << "Tie\n";
            } else {
            std::cout << winner << " won!\n";
            }
            break;
        }
        index++;
    }

    
    return 0;
}
