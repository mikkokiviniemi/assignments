#include "ai.h"
#include "utils.h"


//Moves AI
void make_ai_move (Game_board& board) {

    std::vector<int> player_move = could_player_win(board,0,0,'O');

    if(player_move[2] == 1){//Check if AI could win
        add_mark (board,player_move[0], player_move[1],'O');
    } else {
        std::vector<int> move = could_player_win(board,0,0,'X'); //Blocks player

        add_mark (board,move[0], move[1],'O');
    }
    
}

//Check if player could win
std::vector<int> could_player_win (Game_board board,int x, int y, char mark) {
    Game_board new_board = board;
    
    if (can_make_move(new_board,x,y)) {
        add_mark(new_board,x,y,mark);
    }
    if (has_won(new_board,mark)) {
        return {x,y,1};
    }
    else {
        if (x==2 && y==2){ 

            int row = randomBetween(0,2);
            int col = randomBetween(0,2);

            while (!can_make_move(new_board,row,col)){
                row = randomBetween(0,2);

                col = randomBetween(0,2);
            }

            return {row,col,0}; //Return random move if player could not win
        }
        else if (y < 2){
            y++;
        } else if (x != 2 && y == 2) {
            y = 0;
            x++;
        }
        return could_player_win(board,x,y,mark);
    }



}