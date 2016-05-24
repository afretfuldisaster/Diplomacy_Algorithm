/*
Class Name: Country
Purpose:	The purpose of this class is to hold all the information for a Country throughout the game.
Public Variables:
	
Private Variables:	
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
		/*
		if (countryUnits[i].unitLocation == eBLANK) //This line is never true... Thus doesn't create the stuff
		{
			countryUnits[i].unitLocation = B;
			countryUnits[i].unitType = C;
			countryUnits[i].unitLocationType = GetLocationType(B);
		}
		*/
		countryUnits[i].unitLocation = B;
		countryUnits[i].unitType = C;
		countryUnits[i].unitLocationType = GetLocationType(B);

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

eLocation Country::ConvertToELocation(int A) { return countryUnits[A].unitLocation; }

/* 
	This is only called at the creation of the game.
	The Build and Destroy Unit functions will increment or decrement the
	number of units from their respective functions
*/
void Country::SetNumOfUnits(int A)
{
	numOfUnits = A;
}

inline int Country::GetNumOfUnits() { return numOfUnits; }

inline eUnitType Country::GetUnitType(int uNum) { return countryUnits[uNum].unitType; }


void Country::PrintAllUnitsInfo(int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << " (" << i << ") ";
		PrintUTypeAsString(countryUnits[i].unitType);
		std::cout << " ";
		PrintLocAsString(countryUnits[i].unitLocation);
		std::cout<< std::endl;
	}
}

inline void Country::PrintLocAsString(eLocation A)
{
	switch (A)
	{
	case eAdr:
		std::cout << "Adriatic Sea";
		break;
	case eAeg:
		std::cout << "Aegian Sea";
		break;
	case eAlb:
		std::cout << "Albania";
		break;
	case eAnk:
		std::cout << "Ankara";
		break;
	case eApu:
		std::cout << "Apu";
		break;
	case eArm:
		std::cout << "Armenia";
		break;
	case eBal:
		std::cout << "Baltic Sea";
		break;
	case eBar:
		std::cout << "Barents Sea";
		break;
	case eBel:
		std::cout << "Belgium";
		break;
	case eBer:
		std::cout << "Berlin";
		break;
	case eBla:
		std::cout << "Black Sea";
		break;
	case eBoh:
		std::cout << "Bohemia";
		break;
	case eBot:
		std::cout << "Gulf of Bothnia";
		break;
	case eBre:
		std::cout << "Brest";
		break;
	case eBud:
		std::cout << "Budapest";
		break;
	case eBul:
		std::cout << "Bulgaria";
		break;
	case eBur:
		std::cout << "Burgundy";
		break;
	case eCly:
		std::cout << "Clyde";
		break;
	case eCon:
		std::cout << "Constantinople";
		break;
	case eDen:
		std::cout << "Denmark";
		break;
	case eEas:
		std::cout << "Eastern Mediterranean Sea";
		break;
	case eEdi:
		std::cout << "Edinburgh";
		break;
	case eEng:
		std::cout << "English Channel";
		break;
	case eFin:
		std::cout << "Finland";
		break;
	case eGal:
		std::cout << "Galatia";
		break;
	case eGas:
		std::cout << "Gascony";
		break;
	case eGoL:
		std::cout << "Gulf of Lyon";
		break;
	case eGre:
		std::cout << "Greece";
		break;
	case eHel:
		std::cout << "Helgoland Bight";
		break;
	case eHol:
		std::cout << "Holland";
		break;
	case eIon:
		std::cout << "Ionian Sea";
		break;
	case eIri:
		std::cout << "Irish Sea";
		break;
	case eKie:
		std::cout << "Kiel";
		break;
	case eLon:
		std::cout << "London";
		break;
	case eLvn:
		std::cout << "Livonia";
		break;
	case eLvp:
		std::cout << "Liverpool";
		break;
	case eMar:
		std::cout << "Marseille";
		break;
	case eMid:
		std::cout << "Mid-Atlantic Ocean";
		break;
	case eMos:
		std::cout << "Moscow";
		break;
	case eMun:
		std::cout << "Munich";
		break;
	case eNaf:
		std::cout << "North Africa";
		break;
	case eNap:
		std::cout << "Naples";
		break;
	case eNAt:
		std::cout << "North Atlantic";
		break;
	case ePar:
		std::cout << "Paris";
		break;
	case ePic:
		std::cout << "Picardy";
		break;
	case ePie:
		std::cout << "Piedmont";
		break;
	case ePor:
		std::cout << "Portugal";
		break;
	case ePru:
		std::cout << "Prussia";
		break;
	case eRom:
		std::cout << "Rome";
		break;
	case eRuh:
		std::cout << "Ruhr";
		break;
	case eRum:
		std::cout << "Rumania";
		break;
	case eSer:
		std::cout << "Serbia";
		break;
	case eSev:
		std::cout << "Sevastopol";
		break;
	case eSil:
		std::cout << "Silesia";
		break;
	case eSka:
		std::cout << "Skagerrak";
		break;
	case eSmy:
		std::cout << "Smryna";
		break;
	case eSpa:
		std::cout << "Spain";
		break;
	case eStP:
		std::cout << "St Petersburg";
		break;
	case eSwe:
		std::cout << "Sweden";
		break;
	case eSyr:
		std::cout << "Syria";
		break;
	case eTri:
		std::cout << "Trieste";
		break;
	case eTun:
		std::cout << "Tunis";
		break;
	case eTus:
		std::cout << "Tuscany";
		break;
	case eTyn:
		std::cout << "Tyrbennian Sea";
		break;
	case eTyr:
		std::cout << "Tyrolia";
		break;
	case eUkr:
		std::cout << "Ukraine";
		break;
	case eVie:
		std::cout << "Vienna";
		break;
	case eVen:
		std::cout << "Venice";
		break;
	case eWal:
		std::cout << "Wales";
		break;
	case eWar:
		std::cout << "Warsaw";
		break;
	case eWes:
		std::cout << "Western Mediterranean";
		break;
	case eYor:
		std::cout << "York";
		break;
	default:
		std::cout << "INVALID"; // For debugging purposes only right now
		break;
	}

}

inline void Country::PrintUTypeAsString(eUnitType A)
{
	switch (A)
	{
	case eArmy:
		std::cout << "Army";
		break;
	case eFleet:
		std::cout << "Fleet";
		break;
	default:
		break;
	}
}

void Country::SetUnitLocation(eLocation A)
{

}

/*
Function:	SetUnitCommands
Parameters:	
Purpose:	When the command is to Hold, set the command to hold
Overloaded:	Y
*/
void Country::SetUnitCommands(int unitNum, eLocation A, eUnitCommand B)
{
	countryUnits[unitNum].unitCommand = B;
}

/*
Function:	SetUnitCommands
Purpose:	When the command is to Move, set the desired destination location
*/
void Country::SetUnitCommands(int unitNum, eLocation currLoc, eUnitCommand uCom, eLocation to)
{
	bool result = false;
	countryUnits[unitNum].unitCommand = uCom;
	result = IsMoveLegal(unitNum, currLoc, uCom, to);
	if (result == true)	countryUnits[unitNum].unitTo = to;
	else
	{
		std::cout << "Move is not legal!";
	}
	
}

/*
Function:	SetUnitCommands
Purpose:	When the command is to Support Hold or Support Move, set the command.
*/
void Country::SetUnitCommands(int unitNum, eLocation A, eUnitCommand B, eLocation next, eUnitVia via)
{

}

bool Country::IsMoveLegal(int unitNum, eLocation A, eUnitCommand B, eLocation next)
{
	eLocationType fromType, toType;
	eUnitType unit;
	bool result;

	unit = GetUnitType(unitNum);
	fromType = GetLocationType(A);
	toType = GetLocationType(next);

	switch (B)
	{
	case(eMove):
		if (unit != eFleet && toType == eSea) return false; //army move to sea is illegal
		else if (unit != eArmy && toType == eLand) return false; //Fleet move to land is illegal
		else //now moves to only adjacent locations
		{
			result = DoLocationsTouch(A, next);
		}
		break;
	case(eSupportHold):
		//Get if the locations touch
		result = DoLocationsTouch(A, next);

		break;
	case(eSupportMove):
		break;
	case(eConvoy):
		break;
	default:
		break;
	}

	return result;
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

bool Country::DoLocationsTouch(eLocation A, eLocation B) 
{
	return true;
}

