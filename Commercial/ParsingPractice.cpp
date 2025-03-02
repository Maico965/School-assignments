// ParsingPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include "Zone.h"

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

cout << "Welcome to the pollution simulation!" << endl << endl;

//Getting Dimensions;
getline(fstream, tempString);


strLength = tempString.size();

while (!fstream.eof()) {
	getline(fstream, tempString);
	++YGetter;
}

int XMax = strLength / 2 + 1;
int YMax = YGetter;
fstream.close();
//End of getting dimensions

//Getting Time Config Settings
fstream.open("config1.txt");
string stringToInt = "";
string subString = "Refresh";
int indexSubstring = 0;

while (tempString.at(0) != 'T') {
	getline(fstream, tempString);


}


for (int i = 0; i < tempString.size(); ++i) {
	if (isdigit(tempString.at(i))) {
		stringToInt += tempString.at(i);
	}

}



Turns = stoi(stringToInt);
stringToInt = "";

while (tempString.find(subString) != NULL) {
	getline(fstream, tempString);
}


for (int i = 0; i < tempString.size(); ++i) {
	if (isdigit(tempString.at(i))) {
		stringToInt += tempString.at(i);
	}

}
RefreshRate = stoi(stringToInt);

cout << "Reading the configuration information for the simulation." << endl << endl;
cout << "The number of turns is: " << Turns << endl;
cout << "The refresh rate of the program is: " << RefreshRate << endl << endl;


fstream.close();

//Getting input from region1.csv

fstream.open("region1.csv");
vector<vector<char>>MapReader(YMax, vector<char>(XMax));

cout << "Outputting initial map layout: " << endl;

for (int j = 0; j < YMax; ++j) {
	getline(fstream, tempString);

	cout << endl;
	k = 0;
	for (int i = 0; i < strLength; ++i) {

		//cout << tempString.at(i);
		if (tempString.at(i) != ',') {
			//cout << tempString.at(i);

			MapReader[j][k] = tempString.at(i);
			cout << MapReader[j][k] << ' ';
			++k;
		}

	}
}
fstream.close();

// End of reading initial region information (next portion of project)




//Simulation Variables

int TotalPollution = 0;
int AvailableGoods = 0;
int AvailableWorkers = 0;






cout << endl << endl << "Building Zone" << endl;
vector <vector<Zone*>> SimMap(YMax, vector<Zone*>(XMax));

	for (int i = 0; i < YMax; ++i) {
		for (int j = 0; j < XMax; ++j){
		SimMap[i][j] = new Zone(i, j, MapReader[i][j]);
		}
	}

// Done

//Getting PowerLine Information

	
	
	/*
	for (int i = 0; i < YMax; ++i) {
		for (int j = 0; j < XMax; ++j) {
			
		}
	}

	*/






/*Building vector of zone objects;
		cout << endl << endl << "Building Zone" << endl;
			vector <vector<Zone*>> SimMap(YMax, vector<Zone*>(XMax));


			Zone zone;
			zone.SetType('c');
*/

/*for (int j = 0; j < YMax; ++j) {
	
	for (int i = 0; i < XMax; ++i) {
		SimMap[j][i]->SetType(MapReader[j][i]);
		SimMap[j][i]->SetPosition(j, i);
		

	}
}
*/

				
				
				
 return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
