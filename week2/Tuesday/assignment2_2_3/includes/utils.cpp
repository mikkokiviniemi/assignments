#include "utils.h"


using Game_board = std::array<std::array<Cell, 10>, 10>;

int randomBetween(int min, int max){
    
    static bool initDone {false};
    if (!initDone){
        std::srand(time(NULL));
        initDone = true;
    }
    return min + rand() % (( max + 1 ) - min);
}

Game_board fill_board () {
    
    Game_board board;
    

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            int random_cell = randomBetween(0,5);

            if(random_cell == 1){
                Cell new_cell = {'O'};
                board[col][row] = new_cell; 
            }
            else if (random_cell == 2){
                Cell new_cell = {'*'};
                board[col][row] = new_cell;
            }
            else {
                Cell new_cell = {' '};
                board[col][row] = new_cell; 
            }
            
        }
    }

    return board;

}

bool can_move (Game_board& board, int x, int y){

    if((x < 0) || (x > 9) || (y < 0) || (y > 9)) {
        return false;
    }

    return board[y][x].cell_type != 'O';
}

bool move_prompt (Game_board& board, Player& player) {
    char c;
    int x = player.x;
    int y = player.y;

    std::cout << "(W,A,S,D): ";
    std::cin >> c;


    if (c == 'W'){
        y = y - 1;
    }
    else if (c == 'A'){
        x = x - 1;
    }
    else if (c == 'S'){
        y = y + 1;
    }
    else if (c == 'D'){
        x = x + 1;
    }

    if(can_move(board,x,y)){
        if(board[y][x].cell_type == '*'){
            player.points += 1;
            board[y][x].cell_type = ' ';
        }
        player.move(x,y);
    }

    
    return y == 9 && player.points >= 5;
}

void print_board (Game_board& board, Player& player) {
    std::cout << "Points: " << player.points << "/5\n";
    std::cout << "############\n";
    for (int row = 0; row < 10; row++) {
        std::cout << "#";
        for (int col = 0; col < 10; col++) {

            if ((col == player.x) && (row == player.y)){
                std::cout << player.skin;
            }else {
                std::cout << board[row][col].cell_type;
            }
                   
        }
        std::cout << "#";
        std::cout << "\n";
    }
    std::cout << "####GOAL####\n";

}