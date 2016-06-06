#pragma once
#include "EnumTypes.h"

//Can i make a number of smaller tables as 1 large table will be filled with a number of falses

//const bool **ptrCnct = new bool*[75]; //default fill should be false 

const bool connected[75][75] = {};

void ReturnPossibleMoves();
void PrintPossibleMoves(eLocation, eUnitType);