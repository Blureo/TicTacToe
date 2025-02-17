//
//  functions.cpp
//  Tic-Tac-Toe
//
// This file holds the functions used in main
//

#include "functions.hpp"
#include <iostream>
#include <string>

void printGrid(std::string row1[3], std::string row2[3], std::string row3[3]) // prints the current game board
{
    std::cout << "[" << row1[0] << "] [" << row1[1] << "] [" << row1[2] << "]\n";
    std::cout << "[" << row2[0] << "] [" << row2[1] << "] [" << row2[2] << "]\n";
    std::cout << "[" << row3[0] << "] [" << row3[1] << "] [" << row3[2] << "]\n";
}

long firstPlayInput()
{
    std::string firstPlay;
    long inputState = 2;
    
    std::cout << "Type X or O if you want that symbol to play first (X/O): "; // ask user which symbol they wish to have the first turn
    std::cin >> firstPlay;
    
    while (inputState == 2)
    {
        if ((firstPlay != "X") && (firstPlay != "O") && (firstPlay != "o") && (firstPlay != "x")) // if user does not input an X or O we call this function again
        {
            std::cout << "InputError. Please try again." << std::endl;
            return firstPlayInput(); // call again if there is an error
        }
        else if ((firstPlay == "X") || (firstPlay == "x"))
            inputState = 1; // X plays first
        else
            inputState = 0; // O plays first
    }
    
    if (inputState == 1)
        return 1; // X plays first
    else
        return 0; // O plays first
}

void gridChecker(bool player, std::string (&row1)[3], std::string (&row2)[3], std::string (&row3)[3])
{
    std::string otherPlayer;
    std::string input;
    
    long row;
    long column;
    
    bool inputState = true; // true while taking input
    
    if (player)
    {
        otherPlayer = "O"; // If its X's turn, the other player is O
        input = "X"; // if player/turnTracker is true, it is X's turn
    }
    else
    {
        otherPlayer = "X"; // If its O's turn, the other player is X
        input = "O"; // if player/turnTracker is false, it is O's turn
    }
    
    while (inputState) // input loop for row/cloumn selection
    {
        
        std::cout << "Row #: " << std::endl;
        std::cin >> row;
        std::cout << "Column #: " << std::endl;
        std::cin >> column;
        
        switch (row)
        {
            case 1:
                switch (column)
                {
                    case 1:
                        // row 1 column 1
                        if ((row1[0] == " ") && (row1[0] != otherPlayer))
                        {
                            row1[0] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    case 2:
                        // row 1 column 2
                        if ((row1[1] == " ") && (row1[1] != otherPlayer))
                        {
                            row1[1] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    case 3:
                        // row 1 column 3
                        if ((row1[2] == " ") && (row1[2] != otherPlayer))
                        {
                            row1[2] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    default:
                        std::cout << "The inputed value does not apply. Try again." << std::endl;
                        break;
                }
                break;
            case 2:
                switch (column)
                {
                    case 1:
                        // row 2 column 1
                        if ((row2[0] == " ") && (row2[0] != otherPlayer))
                        {
                            row2[0] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    case 2:
                        // row 2 column 2
                        if ((row2[1] == " ") && (row2[1] != otherPlayer))
                        {
                            row2[1] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    case 3:
                        // row 2 column 3
                        if ((row2[2] == " ") && (row2[2] != otherPlayer))
                        {
                            row2[2] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    default:
                        std::cout << "The inputed value does not apply. Try again." << std::endl;
                        break;
                }
                break;
            case 3:
                switch (column)
                {
                    case 1:
                        // row 3 column 1
                        if ((row3[0] == " ") && (row3[0] != otherPlayer))
                        {
                            row3[0] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    case 2:
                        // row 3 column 2
                        if ((row3[1] == " ") && (row3[1] != otherPlayer))
                        {
                            row3[1] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    case 3:
                        // row 3 column 3
                        if ((row3[2] == " ") && (row3[2] != otherPlayer))
                        {
                            row3[2] = input;
                            inputState = false;
                        }
                        else
                        {
                            std::cout << "Space already taken. Try again." << std::endl;
                        }
                        break;
                    default:
                        std::cout << "The inputed value does not apply. Try again." << std::endl;
                        break;
                }
                break;
            default:
                std::cout << "The inputed value does not apply. Try again." << std::endl;
                break;
        }
        
    }
}

/*
void clearScreen() // function "clears" screen between turns
{
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";  // ANSI escape sequence to clear the screen
}
*/

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";  // ANSI escape sequence to clear the screen
}


bool winCheck(bool &tieCheck, std::string row1[3], std::string row2[3], std::string row3[3])
{
    // code to check win-states.
    // there are 8 win states; 3 vertical, 3 horizontal, and 2 diagonal
    
    if ((row1[0] == row1[1]) && (row1[1] == row1[2]) && (row1[0] != " ")) // horizontal row 1
        return false;
    if ((row2[0] == row2[1]) && (row2[1] == row2[2]) && (row2[0] != " ")) // horizontal row 2
        return false;
    if ((row3[0] == row3[1]) && (row3[1] == row3[2]) && (row3[0] != " ")) // horizontal row 3
        return false;
    if ((row1[0] == row2[0]) && (row2[0] == row3[0]) && (row1[0] != " ")) // vertical row 1
        return false;
    if ((row1[1] == row2[1]) && (row2[1] == row3[1]) && (row1[1] != " ")) // vertical row 2
        return false;
    if ((row1[2] == row2[2]) && (row2[2] == row3[2]) && (row1[2] != " ")) // vertical row 3
        return false;
    if ((row1[0] == row2[1]) && (row2[1] == row3[2]) && (row1[0] != " ")) // diagonal top-left to bottom right
        return false;
    if ((row1[2] == row2[1]) && (row2[1] == row3[0]) && (row1[2] != " ")) // diagonal top-right to bottom left
        return false;
 
    for (int i=0; i<3; i++)
    {
        if ((row1[i] == " ") || (row2[i] == " ") || (row3[i] == " ")) // if there are still open spaces there is no tie yet
            return true;
    }
    
    tieCheck = true;
    return false; // there was a tie
}
