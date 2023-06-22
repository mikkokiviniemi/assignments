#include "utils.h"


using Game_board = std::array<std::array<Cell, 3>, 3>;

//Fills board with empty cells
Game_board fill_board () {
    
    Game_board board;
    
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {

            Cell new_cell = {' '};
            board[col][row] = new_cell; 
        }
    }

    return board;
}
//Adds mark to board
void add_mark (Game_board& board,int row,int col,char mark) {
    board[row][col].cell_type = mark;
}
//Check if you can make move
bool can_make_move (Game_board& board, int x, int y){

    if((x < 0) || (x > 2) || (y < 0) || (y > 2)) {
        return false;
    }

    return board[x][y].cell_type == ' ';
}

//Check if spesific mark has won
bool has_won (Game_board& board,char mark) {

    //Check row
    for (int row = 0; row < 3; row++) {
        if(board[row][0].cell_type == mark && board[row][1].cell_type == mark && board[row][2].cell_type == mark) {
            return true;
        }
    }

    //Check col
    for (int col = 0; col < 3; col++) {
        if(board[0][col].cell_type == mark && board[1][col].cell_type == mark && board[2][col].cell_type == mark) {
            return true;
        }
    }

    //Check diagonal left to right
    if(board[0][0].cell_type == mark && board[1][1].cell_type == mark && board[2][2].cell_type == mark) {
        return true;
    }
    //Check diagonal right to left
    if(board[2][0].cell_type == mark && board[1][1].cell_type == mark && board[0][2].cell_type == mark) {
        return true;
    }
    return false;
}

//Generates random number
int randomBetween(int min, int max){
    
    static bool initDone {false};
    if (!initDone){
        std::srand(time(NULL));
        initDone = true;
    }
    return min + rand() % (( max + 1 ) - min);
}
//Asks move from player
void make_move (Game_board& board) {

    std::string coords;
    int row,col;
    bool invalid_coords = true;

    while(invalid_coords) {
        std::cout << "Give coords: ";
        std::getline(std::cin,coords);
        if(coords.size() == 2){
            row = coords.at(0) - '0';
            col = coords.at(1) - '0';
            if(can_make_move(board,row,col)) {
                break;
            }
        }
        std::cout << "Wrong move!\n";
    }
    add_mark (board,row, col,'X');
}
//Prints board
void print_board (Game_board& board) {
    std::cout << "-------\n";
    for (int row = 0; row < 3; row++) {
        std::cout << "|";
        for (int col = 0; col < 3; col++) {

            std::cout << board[row][col].cell_type << "|";

        }
        std::cout << "\n";
        std::cout << "-------\n";
    }

}
//Check if gameboard is full
bool check_tie (Game_board& board) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {

            if (board[row][col].cell_type == ' '){
                return false;
            }
                   
        }
    }
    return true;
}