//
//  main.cpp
//  Tic-Tac-Toe
//
//  Command-line based Tic-Tac-Toe
//

#include <iostream>
#include <string>
#include "functions.hpp"

void printGrid(std::string row1[3], std::string row2[3], std::string row3[3]);
long firstPlayInput();
void gridChecker(bool player, std::string (&row1)[3], std::string (&row2)[3], std::string (&row3)[3]);
void clearScreen();

int main()
{
    std::string row1[3] = {" ", " ", " "}; // row 1 of the grid
    std::string row2[3] = {" ", " ", " "}; // row 2 of the grid
    std::string row3[3] = {" ", " ", " "}; // row 3 of the grid
    
    bool gameState = true; // game loops while this is true
    bool turnTracker; // true when it is X's turn and false when it is O's turn
    bool tieCheck = false;
    
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    std::cout << "Row numbers go 1-3, left-to-right\n Column numbers go 1-3, top-to-bottom." << std::endl;
    std::cout << "You can either input your row and column values individually or at once separated by a space: " << std::endl;
    std::cout << "'2 2' or two separate inputs of 2\n" << std::endl;
    
    turnTracker = firstPlayInput();
    
    while (gameState)
    {
        // game goes here
        printGrid(row1, row2, row3);
        gridChecker(turnTracker, row1, row2, row3);
        clearScreen();
        gameState = winCheck(tieCheck, row1, row2, row3);
        
        
        if ((gameState == false) && tieCheck)
        {
            clearScreen();
            printGrid(row1, row2, row3);
            std::cout << "There was a tie!" << std::endl;
        }
        else if ((gameState == false) && turnTracker) // if turnTracker is true then it was X's turn when the win was recognized
        {
            clearScreen();
            printGrid(row1, row2, row3);
            std::cout << "X has won the game!" << std::endl;
        }
            
        else if ((gameState == false) && !turnTracker) // if turnTracker is false then it was X's turn when the win was recognized
        {
            clearScreen();
            printGrid(row1, row2, row3);
            std::cout << "O has won the game!" << std::endl;
        }

        turnTracker = !turnTracker; // play switches back and forth between X and O
    }
}

/*
 
 Box should print like this:
 
 [ ] [ ] [ ]
 [ ] [ ] [ ]
 [ ] [ ] [ ]
 
 */
