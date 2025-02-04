//
//  functions.hpp
//  Tic-Tac-Toe
//
//  his file holds the functions used in main
//

#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <string>

void printGrid(std::string row1[3], std::string row2[3], std::string row3[3]);
long firstPlayInput();
void gridChecker(bool player, std::string (&row1)[3], std::string (&row2)[3], std::string (&row3)[3]);
void clearScreen();
bool winCheck(bool &tieCheck, std::string row1[3], std::string row2[3], std::string row3[3]);

#endif /* functions_hpp */
