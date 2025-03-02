#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "Zone.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "PL.h"
#include "pollution.h"


using namespace std;

int main()
{

	ifstream fstream;
	fstream.open("region1.csv");

	string tempString;
	int YGetter = 1;
	int strLength;
	int k = 0;
	int Turns = 0;
	int RefreshRate;
	int goods = 0;
	int workers = 0;
	bool resMatch, indMatch, comMatch;
	cout << "Welcome to the pollution simulation!" << endl << endl;

	// Getting Dimensions;
	getline(fstream, tempString);

	strLength = tempString.size();

	while (!fstream.eof())
	{
		getline(fstream, tempString);
		++YGetter;
	}

	int XMax = strLength / 2 + 1;
	int YMax = YGetter;
	fstream.close();
	// End of getting dimensions

	// Getting Time Config Settings
	fstream.open("config1.txt");
	string stringToInt = "";
	string subString = "Refresh";
	int indexSubstring = 0;

	while (tempString.at(0) != 'T')
	{
		getline(fstream, tempString);
	}

	for (int i = 0; i < tempString.size(); ++i)
	{
		if (isdigit(tempString.at(i)))
		{
			stringToInt += tempString.at(i);
		}
	}

	Turns = stoi(stringToInt);
	stringToInt = "";

	while (tempString.find(subString) != NULL)
	{
		getline(fstream, tempString);
	}

	for (int i = 0; i < tempString.size(); ++i)
	{
		if (isdigit(tempString.at(i)))
		{
			stringToInt += tempString.at(i);
		}
	}
	RefreshRate = stoi(stringToInt);

	cout << "Reading the configuration information for the simulation." << endl
		 << endl;
	cout << "The number of turns is: " << Turns << endl;
	cout << "The refresh rate of the program is: " << RefreshRate << endl
		 << endl;

	fstream.close();

	// Getting input from region1.csv

	fstream.open("region1.csv");
	vector<vector<char>> MapReader(YMax, vector<char>(XMax));

	cout << "Outputting initial map layout: " << endl;

	for (int j = 0; j < YMax; ++j)
	{
		getline(fstream, tempString);

		cout << endl;
		k = 0;
		for (int i = 0; i < strLength; ++i)
		{

			// cout << tempString.at(i);
			if (tempString.at(i) != ',')
			{
				// cout << tempString.at(i);

				MapReader[j][k] = tempString.at(i);
				cout << MapReader[j][k] << ' ';
				++k;
			}
		}
	}
	fstream.close();

	// End of reading initial region information (next portion of project)

	// Simulation Variables

	int TotalPollution = 0;
	int AvailableGoods = 0;
	int AvailableWorkers = 0;

	cout << endl << endl << "Building Zone" << endl;
	vector<vector<Zone *>> SimMap(YMax, vector<Zone *>(XMax));

	for (int i = 0; i < YMax; ++i)
	{
		for (int j = 0; j < XMax; ++j)
		{
			if (MapReader[i][j] == 'R')
			{
				SimMap[i][j] = new Residential(i, j, MapReader[i][j], XMax, YMax);
			}
			else if (MapReader[i][j] == 'I')
			{
				SimMap[i][j] = new Industrial(i, j, MapReader[i][j], XMax, YMax);
			}
			else if (MapReader[i][j] == 'C')
			{
				SimMap[i][j] = new Commercial(i, j, MapReader[i][j], XMax, YMax);
			}
			else if (MapReader[i][j] == 'T' || '#')
			{
				SimMap[i][j] = new PL(i, j, MapReader[i][j], XMax, YMax);
			}
			else
			{
				SimMap[i][j] = new PlaceHolder(i, j, MapReader[i][j], XMax, YMax);
			}
		}
	}

	/*

	for(int i = 0; i<YMax; ++i){                                         //setting up which cells have power lines connected to them
		for(int j = 0; j<XMax; ++j{
			if(SimMap[i][j]->GetType() == ('T' || '#')){
			SimMap[i][j]->Compile();
			}

		}
	}

	*/

	/*
	for (int k = 0; k <= Turns; ++k) {
		for (int i = 0; i < YMax; ++i) {
			for (int j = 0; j < XMax; ++j) {
				SimMap[i][j]->SetAdjacentPopulation();
			}
		}

		for (int i = 0; i < YMax; ++i) {
			for (int j = 0; j < XMax; ++j) {
				if (SimMap[i][j]->GetType() == 'R') {
					SimMap[i][j]->UpdatePop();
					resMatch = true;
				}
				if (resMatch == true);
				break;
			}
			if (resMatch == true);
			break;
		}


		for (int i = 0; i < YMax; ++i) {
			for (int j = 0; j < XMax; ++j) {
				if (SimMap[i][j]->GetType() == 'C') {
					SimMap[i][j]->PopulationLoop('C', goods, workers, SimMap);
					comMatch = true;
				}
				if (comMatch == true);
				break;
			}
			if (comMatch == true);
			break;
		}


		for (int i = 0; i < YMax; ++i) {
			for (int j = 0; j < XMax; ++j) {
				if (SimMap[i][j]->GetType() == 'I') {
					SimMap[i][j]->PopulationLoop('I', goods, workers, SimMap);
					comMatch = true;
				}
				if (comMatch == true);
				break;
			}
			if (comMatch == true);
			break;
		}
		resMatch = false;
		indMatch = false;
		comMatch = false;

		for (int i = 0; i < YMax; ++i) {
			for (int j = 0; j < XMax; ++j{
				if (SimMap[i][j]->GetIncrement() == true) {
				SimMap[i][j]->Deploy();
				}
				}
		}

		for (int i = 0; i < YMax; ++i) {
			for (int j = 0; j < XMax; ++j{
				SimMap[i][j]->SetChecked(false);
				SimMap[i][j]->SetIncrement(false);
				}
		}

		for (int i = 0; i < YMax; ++i) {
			for (int j = 0; j < XMax; ++j{
				if (SimMap[i][j]->GetPopulation()>0){
				cout << SimMap[i][j]->GetPopulation() << " ";
				}
				else {
					cout << SimMap[i][j]->GetType() << " ";
					}
			}
		}

	}
	*/

	return 0;
}
