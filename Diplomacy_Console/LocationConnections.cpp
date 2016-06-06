#include "stdafx.h"
#include <iostream>
#include <string>
#include "Country.h"
#include "EnumTypes.h"

/*
	This file needs to hold the function to determine which locations are possible to move.
*/

void ReturnPossibleMoves(eLocation A, eUnitType B)
{
	switch (A)
	{
	case eLon:
		if (B == eFleet)
		{

		}
		else if (B == eArmy)
		{

		}
		break;
	case eBal:
		break;
	default:
		break;
	}
}

void PrintPossibleMoves(eLocation A, eUnitType B)
{
	switch (A) 
	{
		case eTri:
			if (B == eFleet)
			{
				std::cout << "(0) Venice " << std::endl;
				std::cout << "(1) Albania " << std::endl;
				std::cout << "(2) Adriatic Sea " << std::endl;
			}
			else if (B == eArmy)
			{
				std::cout << "(0) Venice " << std::endl;
				std::cout << "(1) Albania " << std::endl;
				std::cout << "(2) Tyrolia " << std::endl;
				std::cout << "(3) Vienna " << std::endl;
				std::cout << "(4) Budapest " << std::endl;
				std::cout << "(5) Serbia " << std::endl;
			}
			break;
		case eBal:
			break;
		default:
			break;
	}

}
