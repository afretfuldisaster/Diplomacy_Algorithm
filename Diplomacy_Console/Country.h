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
		eVia unitVia;
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
	void GetAllUnitsInfo(void);

	//Set Functions
	void SetPlayerCountry(ePlayerCountry);
	void SetUnitLocation(eLocation);
	void SetNumOfUnits(int);

	//Special Functions
	void BuildNewUnit(ePlayerCountry, eLocation, eUnitType);
	void DestroyUnit(ePlayerCountry, eLocation);
	eLocationType GetLocationType(eLocation A);
};