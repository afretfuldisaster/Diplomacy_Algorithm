#pragma once
#include "EnumTypes.h"

class Country
{

private:
	int numOfUnits;
	ePlayerCountry pCountry; //Which country are we talking about?

	struct sUnitInfo {
		eUnitType unitType;
		eLocation unitLocation;
		eLocationType unitLocationType;
		eLocation unitTo;
		eUnitVia unitVia;
	} countryUnits[18]; //18 is max number of units

public:
	//Variables
	std::string playerName;
	
	Country();
	~Country();
	Country(ePlayerCountry, std::string);

	//Get Functions
	ePlayerCountry GetPlayerCountry(void);
	inline int GetNumOfUnits(void);
	void PrintAllUnitsInfo(int);

	//Set Functions
	void SetPlayerCountry(ePlayerCountry);
	void SetUnitLocation(eLocation);
	void SetNumOfUnits(int);
	void SetUnitMoveTo(eLocation, eLocation, eUnitType);

	//Special Functions
	void BuildNewUnit(ePlayerCountry, eLocation, eUnitType);
	void DestroyUnit(ePlayerCountry, eLocation);
	inline void PrintLocAsString(eLocation);
	inline void PrintUTypeAsString(eUnitType);
	eLocationType GetLocationType(eLocation A);
	inline eLocation ConvertToELocation(int);
};