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