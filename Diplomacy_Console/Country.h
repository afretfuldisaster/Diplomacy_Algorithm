#pragma once
#include "EnumTypes.h"

class Country
{

private:
	struct sUnitInfo {
		eUnitType unitType;
		eLocation unitLocation;
		eLocationType unitLocationType;
	} countryUnits[18];
	
	struct sCommands {
		
	};

	//vector<sUnits> countryUnits(18);
	int numOfUnits;
	ePlayerCountry pCountry; //Which country are we talking about?

public:
	//Variables
	std::string playerName;
	
	Country();
	~Country();
	Country(ePlayerCountry, std::string);

	//Get Functions
	ePlayerCountry GetPlayerCountry(void);
	int GetNumOfUnits(void);

	//Set Functions
	void SetPlayerCountry(ePlayerCountry);
	void SetUnitLocation(eLocation);
	void SetNumOfUnits(ePlayerCountry);

	//Special Functions
	void BuildNewUnit(ePlayerCountry, eLocation, eUnitType);
	void DestroyUnit(ePlayerCountry, eLocation);
	eLocationType GetLocationType(eLocation A);
};