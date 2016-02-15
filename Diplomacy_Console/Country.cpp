/*
Class Name: Country
Purpose:	The purpose of this class is to hold all the information for a Country throughout the game.
*/
#include "stdafx.h"
#include <iostream>
#include "Country.h"

//Standard Constructors and Destructors - No use
Country::Country()
{
}
Country::~Country()
{
}

//Use this constructor to create a country at the beginning of the game
Country::Country(ePlayerCountry A, std::string nameinput)
{

	//Set the number of units in the start of the set up
	SetNumOfUnits(0);
	switch (A) {
		//Set up all the starting units using the BuildNewUnit interface	
	case eAustria:
		BuildNewUnit(eAustria, eVie, eArmy);
		BuildNewUnit(eAustria, eTri, eFleet);
		BuildNewUnit(eAustria, eBud, eArmy);
		break;
	case eEngland:
		BuildNewUnit(eEngland, eLon, eFleet);
		BuildNewUnit(eEngland, eLvp, eArmy);
		BuildNewUnit(eEngland, eEdi, eFleet);
		break;
	case eFrance:
		BuildNewUnit(eFrance, ePar, eArmy);
		BuildNewUnit(eFrance, eBre, eFleet);
		BuildNewUnit(eFrance, eMar, eArmy);
		break;
	case eGermany:
		BuildNewUnit(eGermany, eBer, eArmy);
		BuildNewUnit(eGermany, eKie, eFleet);
		BuildNewUnit(eGermany, eMun, eArmy);
		break;
	case eItaly:
		BuildNewUnit(eItaly, eVen, eArmy);
		BuildNewUnit(eItaly, eNap, eFleet);
		BuildNewUnit(eItaly, eRom, eArmy);
		break;
	case eRussia:
		BuildNewUnit(eRussia, eSev, eFleet);
		BuildNewUnit(eRussia, eWar, eArmy);
		BuildNewUnit(eRussia, eStP, eFleet);
		BuildNewUnit(eRussia, eMos, eArmy);
		break;
	case eTurkey:
		//F Ankara, A Con, A Smyrna
		BuildNewUnit(eTurkey, eCon, eArmy);
		BuildNewUnit(eTurkey, eAnk, eFleet);
		BuildNewUnit(eTurkey, eSmy, eArmy);
		break;
	default:
		//Nothing? Error handling?
		break;
	}

	//Set the player's name
	playerName = nameinput;
}

/* Use this function to create a new unit
	Parameter 1: The country/player
	Parameter 2: The location of the build
	Parameter 3: The type of unit being built
*/
void Country::BuildNewUnit(ePlayerCountry A, eLocation B, eUnitType C) 
{
	int i = GetNumOfUnits();
	//is the location allowable to be built at for that country
	switch (A)
	{
	case eAustria:
		if(B == eVie || B == eTri || B == eBud)	break;
		else
		{
			std::cout << "Build location not allowed";
			return;
		}
	case eEngland:
		if (B == eLon || B == eEdi || B == eLvp)break;
		else
		{
			std::cout << "Build location not allowed";
			return;
		}
	case eFrance:
		if (B == eBre || B == ePar || B == eMar) break;
		else
		{
			std::cout << "Build location not allowed";
			return;
		}
	case eGermany:
		if (B == eMun || B == eKie || B == eBer) break;
		else
		{
			std::cout << "Build location not allowed";
			return;
		}
	case eItaly:
		if (B == eVen || B == eRom || B == eNap) break;
		else
		{
			std::cout << "Build location not allowed.";
			return;
		}
	case eRussia:
		if (B == eMos || B == eStP || B == eSev || B == eWar) break;
		else
		{
			std::cout << "Build location not allowed.";
			return;
		}
	case eTurkey:
		if (B == eCon || B == eSmy || B == eAnk) break;
		else
		{
			std::cout << "Build location not allowed.";
			return;
		}
	default:
		break;
	}
	//Is the unit type allowable to be built there based on type and location?
	eLocationType temp = GetLocationType(B);
	if ((temp == eLand) && (C != eArmy))
	{
		//ERROR!
		std::cout << "You cannot build a Fleet on dry land!";
		return;
	}
	else if ((temp == eSea) && (C != eFleet))
	{
		//ERROR!
		std::cout << "You cannot build an Army in the sea!";
		return;
	}
	else //Create the unit
	{
		if (countryUnits[i].unitLocation == eBLANK)
		{
			countryUnits[i].unitLocation = B;
			countryUnits[i].unitType = C;
			countryUnits[i].unitLocationType = GetLocationType(B);
		}
		i++;
		SetNumOfUnits(i);
	}
}

void Country::SetPlayerCountry(ePlayerCountry A)
{
	pCountry = A;
}
ePlayerCountry Country::GetPlayerCountry()
{
	return pCountry;
}

/* 
	This is only called at the creation of the game.
	The Build and Destroy Unit functions will increment or decrement the
	number of units from their respective functions
*/
void Country::SetNumOfUnits(int A)
{
	numOfUnits = A;
}

inline int Country::GetNumOfUnits()
{
	return numOfUnits;
}

void Country::SetUnitLocation(eLocation A)
{

}

void Country::DestroyUnit(ePlayerCountry A, eLocation B)
{
	//Destroy is going to be a larger issue... This is because of the need to be able to destroy
	//a unit in the middle of the array list and restructure the array for now.
}

eLocationType Country::GetLocationType(eLocation A)
{
	//If it is coastal
	if (A == eNrg || A == eNAt || A == eMid || A == eIri || A == eEng || A == eNth || A == eHel ||
		A == eSka || A == eGoL || A == eWes || A == eTyn || A == eIon || A == eAdr || A == eAeg ||
		A == eEas || A == eBla || A == eBal || A == eBar || A == eBot)
	{
		return eSea;
	}
	else if (A == eSer || A == eRuh || A == eBur || A == ePar || A == eSil || A == eTyr ||
			 A == eBoh || A == eBud || A == eMos || A == eVie || A == eGal || A == eUkr ||
			 A == eWar)
	{
		return eLand;
	}
	else
	{
		return eCoastal;
	}
}