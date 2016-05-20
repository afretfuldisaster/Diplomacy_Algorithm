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

	std::string nameinput;

	if (numOfPlayers == 7)
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
	if (numOfPlayers == 6)
	{
		//6 players
	}
	if (numOfPlayers == 5)
	{
		//5 players
	}
	if (numOfPlayers == 4)
	{
		//4 players
	}
	if (numOfPlayers == 3)
	{
		//3 players
	}
	if (numOfPlayers == 2)
	{
		//2 players
	}
	else
	{
		//Do nothing for now. Always pass 7 for the time being.
		// 1 player? 
	}
}

int main()
{
	int num, temp;
	std::string input, input2, input3;
	eTurn currentTurn = Spring1901;

	preGameSetUp(7);

	system("cls"); //Not ideal but works for debug output now

	//start game loop now
	while (1) {
		std::cout << "Type 'Exit' when ready to quit.\nWhen ready please type your country name to enter commands: ";
		std::cin >> input;

		if (input == "exit" || input == "Exit" || input == "EXIT")
		{
			std::cout << "Exiting Diplomacy\n Goodbye!";
			break;
		}
		if (input == "Austria" || input == "austria")
		{
			//Output Austria's units and locations
			temp = Austria.GetNumOfUnits();
			Austria.PrintAllUnitsInfo(temp);
			std::cout << "Which unit would you like to command?";
			std::cin >> input2;
			//Act on that input -- how?
			std::cout << "What is that unit's orders?";
			std::cin >> input3;
			//Act on that input -- how?
		}
		else if (input == "England" || input == "england")
		{
			//Output England's units and locations
			temp = England.GetNumOfUnits();
			England.PrintAllUnitsInfo(temp);
		}
		else if (input == "France" || input == "france")
		{
			//do France's commands
		}
		else if (input == "Germany" || input == "germany")
		{
			//do Germany's commands
		}
		else if (input == "Italy" || input == "italy")
		{
			//do Italy's commands
		}
		else if (input == "Russia" || input == "russia")
		{
			//do Russia's commands
			std::cout << Russia.GetNumOfUnits();
		}
		else if (input == "Turkey" || input == "turkey")
		{
			//do Turkey's commands
		}
		else
		{
			std::cout << "Input not understood. Please try again.";

		}

		//system("cls"); //Not ideal but works to clear the console screen for now
	}

    return 0;
}

