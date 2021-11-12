// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

char mark;

char** createTable();
void board(char**);
void markPl1(char**);   //functions used in program
void markPl2(char** );
bool placement(char**, int, int, char);
bool winRules(char**);
bool draw(char**);

int main(){
    

    char** table = createTable();
    while (1) {
        do {
            //drawing the table, then calling the player's turn to mark X or O, depending who is player 1 and 2 
            board(table);
            markPl1(table);
            if (winRules(table)) {
                board(table);
                std::cout << "\nCongrats, Player 1, you won" << std::endl;
                break;
                
            }
            if (draw(table)) { //check if another move is possible. If not, the game is over with draw
                board(table);
                std::cout << "\nOh no, it's a draw" << std::endl;
                break;
            }
            board(table);
            markPl2(table);
            if (winRules(table)) {
                board(table);
                std::cout << "\nCongrats, Player 2, you won" << std::endl;
                break;
            }

        } while (!winRules(table)); //repeat until one player win

        for (int i = 0; i < 3; ++i) { //deleting the table
            delete[] table[i];
        }
        delete[] table;

        std::cout << "Do you want a new game? (Y/N)" << std::endl;
        char choice;
        do {
            while (!(std::cin >> choice)) { //check if user tap y or n correctly
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Tap Y or N, please" << std::endl;
            }
            if (choice == 'Y' || choice == 'y') {
                table = createTable();
                continue;
            }
            else if (choice == 'N' || choice == 'n') {
                return EXIT_SUCCESS;
            }
        }
        while (choice != 'n' && choice != 'N' && choice != 'y' && choice != 'Y');
    }
}
char** createTable() {
    
    char** table = new char* [3];
    for (int i = 0; i < 3; ++i) {
        table[i] = new char[3];
    }                                   //creating a new 3x3 table 
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            table[i][j] = ' ';
        }
    }
    return table;
}
void markPl1(char** table) {

    mark = 'X';
    char position;
    std::cout << "Player 1: Give me the placement (use a z e q s d w x c for the placement)" << std::endl;
    
    while (!(std::cin >> position)) { //check if user tap correctly one of the placements
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Tap a valid character" << std::endl;
    }
    switch (position) {

        case 'a': {
            int i = 0;
            int j = 0;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            } 
        }
        case 'z': { //each letter means a position in table
            int i = 0;
            int j = 1;
            if (placement(table, i, j, mark)) {
                break;
            }
            else { 
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        case 'e': {
            int i = 0;
            int j = 2;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        case 'q': {
            int i = 1;
            int j = 0;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        case 's': {
            int i = 1;
            int j = 1;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        case 'd': {
            int i = 1;
            int j = 2;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        case 'w': {
            int i = 2;
            int j = 0;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        case 'x': {
            int i = 2;
            int j = 1;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        case 'c': {
            int i = 2;
            int j = 2;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl1(table);
                break;
            }
        }
        default: 
            std::cout << "Wrong letter, try again" << std::endl;
            markPl1(table);
    }     
}
void markPl2(char** table) {

    mark = 'O';
    char position;
    std::cout << "Player 2: Give me the placement (use a z e q s d w x c for the placement)" << std::endl;

    while (!(std::cin >> position)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Tap a valid character" << std::endl;
    }
    switch (position) {

        case 'a': {
            int i = 0;
            int j = 0;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 'z': {
            int i = 0;
            int j = 1;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 'e': {
            int i = 0;
            int j = 2;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 'q': {
            int i = 1;
            int j = 0;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 's': {
            int i = 1;
            int j = 1;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 'd': {
            int i = 1;
            int j = 2;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 'w': {
            int i = 2;
            int j = 0;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 'x': {
            int i = 2;
            int j = 1;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        case 'c': {
            int i = 2;
            int j = 2;
            if (placement(table, i, j, mark)) {
                break;
            }
            else {
                std::cout << "This position is already used" << std::endl;
                markPl2(table);
                break;
            }
        }
        default:
            std::cout << "Wrong letter, try again" << std::endl;
            markPl2(table);
  
    }
}
bool placement(char** table, int i, int j, char mark) {

    if (table[i][j] == ' ') { //check if there's somethin on a precised placement

        table[i][j] = mark;
        return true;
    }
    else {

        return false;
    }
}
void board(char** table) {
    //Drawing board
    system("cls");
    std::cout << "Tic Tac Toe...." << std::endl;
    std::cout << "Player 1: X\t Player 2: O" << std::endl << std::endl;
    std::cout << "    " << table[0][0] << "\t" << "||    " << table[0][1] << "    " << "||\t" << table[0][2] << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "    " << table[1][0] << "\t" << "||    " << table[1][1] << "    " << "||\t" << table[1][2] << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "    " << table[2][0] << "\t" << "||    " << table[2][1] << "    " << "||\t" << table[2][2] << std::endl << std::endl;
    
}
bool winRules(char** table) {



    if ((table[0][0] == table[0][1]) && (table[0][2] == table[0][1]) && (table[0][0] == table[0][2])) { // top horizontal row 
        if (table[0][0] && table[0][1] && table[0][2] == ' ') {
            return false;
        }
        else {
            return true;
        }
    }
    if ((table[1][0] == table[1][1]) && (table[1][2] == table[1][1]) && (table[1][0] == table[1][2])) { //middle horizontal row
        if (table[1][0] && table[1][1] && table[1][2] == ' ') {
            return false;
        }
        else {
            return true;
        }
    }
    if ((table[2][0] == table[2][1]) && (table[2][2] == table[2][1]) && (table[2][0] == table[2][2])) { //bottom horizontal row
        if (table[2][0] && table[2][1] && table[2][2] == ' ') {
            return false;
        }
        else {
            return true;
        }
    }

    if ((table[0][0] == table[1][0]) && (table[2][0] == table[1][0]) && (table[0][0] == table[2][0])) { //left vertical row
        if (table[0][0] && table[1][0] && table[2][0] == ' ') {
            return false;
        }
        else {
            return true;
        }
    } 
    if ((table[0][1] == table[1][1]) && (table[2][1] == table[1][1]) && (table[0][1] == table[2][1])) { //middle vertical row
        if (table[0][1] && table[1][1] && table[2][1] == ' ') {
            return false;
        }
        else {
            return true;
        }
    } 
    if ((table[0][2] == table[1][2]) && (table[2][2] == table[1][2]) && (table[0][2] == table[2][2])) { //right vertical row
        if (table[0][2] && table[1][2] && table[2][2] == ' ') {
            return false;
        }
        else {
            return true;
        }
    }

    if ((table[0][0] == table[1][1]) && (table[2][2] == table[1][1]) && (table[0][0] == table[2][2])) { //diagonal row descending
        if (table[0][0] && table[1][1] && table[2][2] ==' ') {
            return false;
        }
        else {
            return true;
        }
    }
    if ((table[2][0] == table[1][1]) && (table[1][1] == table[0][2]) && (table[2][0] == table[0][2])) { //diagonal row ascending
        if (table[2][0] && table[1][1] && table[0][2] == ' ') {
            return false;
        }
        else {
            return true;
        }
    }
   
    return false;

}
bool draw(char** table) {
    //check if all placements contains X or O
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (table[i][j] == ' ') {
                return false;
            }
           
        }
    }
    return true;
}
