// Diplomacy_Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Country.h"
#include "EnumTypes.h"

//Create a global Class instance?
Country Austria;
Country England;
Country France;
Country Germany;
Country	Italy;
Country Russia;
Country Turkey;

void preGameSetUp(int numOfPlayers) {
	/*
	Country Austria = Country(eAustria, "Daniel");
	std::cout << "Austria:\n";
	num = Austria.GetNumOfUnits();
	std::cout << num << std::endl;
	//or do this:
	Country *Russia = new Country(eRussia, "Kate");
	std::cout << "Russia:\n";
	num = Russia -> GetNumOfUnits();
	std::cout << num << std::endl;
	*/
	std::string nameinput;
	if (numOfPlayers = 7)
	{
		std::cout << "Starting Diplomacy with 7 players.\n";
		std::cout << "Please enter the Austrian Leader's name: ";
		std::cin >> nameinput;
		Austria = Country(eAustria, nameinput);
		std::cout << "\nPlease enter the English Prime Minister's name: ";
		std::cin >> nameinput;
		England = Country(eEngland, nameinput);
		std::cout << "\nPlease enter the French Leader's name: ";
		std::cin >> nameinput;
		France = Country(eFrance, nameinput);
		std::cout << "\nPlease enter the German Chancellor's name: ";
		std::cin >> nameinput;
		Germany = Country(eGermany, nameinput);
		std::cout << "\nPlease enter the Italian Leader's name: ";
		std::cin >> nameinput;
		Italy = Country(eItaly, nameinput);
		std::cout << "\nPlease enter the Russian Tsar's name: ";
		std::cin >> nameinput;
		Russia = Country(eRussia, nameinput);
		std::cout << "\nPlease enter the Turkish Leader's name: ";
		std::cin >> nameinput;
		Turkey = Country(eTurkey, nameinput);
	}
	else
	{
		//Do nothing for now. Always pass 7 for the time being.
	}
}

int main()
{
	int num;
	std::string input;
	eTurn currentTurn = Spring1901;

	//start game loop now
	while (1) {		
		std::cout << currentTurn;
		
		std::cout << "\nWhen ready please type your country name to enter commands: ";
		std::cin >> input;

		if (input == "exit" || input == "Exit" || input == "EXIT")
		{
			std::cout << "Exiting Diplomacy\n Goodbye!";
			break;
		}
		if (input == "Austria" || input == "Austria")
		{
			//do Austria's commands
		}
		else if (input == "England" || input == "england")
		{
			//do England's commands
		}
		else
		{
			std::cout << "Not understood. Please try again.";
		}
	}

    return 0;
}

