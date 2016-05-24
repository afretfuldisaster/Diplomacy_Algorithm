#pragma once
enum eLocation
{
	eBLANK,
	eLon, eYor, eWal, eEdi, eLvp, eCly, //England
	eNrg, eNAt, eMid, eIri, eEng, eNth, eHel, eSka, eGoL, eWes, eTyn, eIon, eAdr, eAeg, eEas, eBla, eBal, eBar, eBot, //Water
	eDen, eHol, eBel, eNwy, eSwe, ePor, eSpa, eNaf, eTun, eAlb, eSer, eBul, eRum, eGre, eFin, //Neutral
	eKie, eBer, eRuh, eMun, eSil, ePru, //Germany
	ePic, eBre, ePar, eBur, eGas, eMar, //France
	ePie, eVen, eTus, eRom, eApu, eNap, //Italy
	eTyr, eBoh, eBud, eVie, eTri, eGal, //Austria
	eCon, eSmy, eAnk, eArm, eSyr, //Turkey
	eSev, eMos, eUkr, eWar, eLvn, eStP //Russia
};

enum eTurn {
	Spring1901,
	Autumn1901,
	Winter1901
};

enum eUnitType
{
	eArmy,
	eFleet
};

enum eUnitCommand
{
	eHold,
	eMove,
	eSupportHold,
	eSupportMove,
	eConvoy
};

enum eUnitVia
{
	eViaLand,
	eViaSea,
	eViaConvoy
};
enum eLocationType
{
	eCoastal,
	eLand,
	eSea
};

enum ePlayerCountry
{
	eAustria,
	eEngland,
	eFrance,
	eGermany,
	eItaly,
	eRussia,
	eTurkey
};

