#pragma once
#include "EnumTypes.h"

class Unit
{
public:
	Unit();
	~Unit();
	Unit(ePlayerCountry A);

	void setUnitType(eUnitType);
	void setUnitLoc(eLocation, eLocationType);

private:
	eLocationType unit_location_type;
	eLocation unit_location;
	eUnitType unit_type;
};

