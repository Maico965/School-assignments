#include <iostream>
#include <vector>
#include "pollution.h"
#include "Industrial.h"
#include "Industrial.cpp"
#include "Zone.h"
#include "main.cpp"
#include "analysis.h"

using namespace std;



// compile
void Pollution::Compile(vector<vector<Zone *>> &SimMap)
{
}


Analysis::Analysis(int x, int y, char letter, int XMax, int YMax)
{
    X = x;
    Y = y;
    type = letter;
    this->XMax = XMax;
    this->YMax = YMax;

}


//Output the final region state
void Analysis::printRegion(){
    //cout << final map
}


//Output the total, regional population for residential zones, industrial zones, and commercial zones
void Analysis::printZonePopulation(vector<vector<Zone *>> &SimMap)
{
    int XPeak = XMax;
    int YPeak = YMax;

    for (int i = 0; i < YMax; ++i)
        {
            for (int j = 0; j < XMax; ++j)
            {
                while (SimMap[i][j]->GetType() == 'R')
                {
                    int residentialPop = 0;
                    residentialPop += SimMap[i][j]->GetPopulation();
                    cout << "Residential Zone population: " << residentialPop << endl;
                }

                while (SimMap[i][j]->GetType() == 'C')
                {
                    int commercialPop = 0;
                    commercialPop += SimMap[i][j]->GetPopulation();
                    cout << "Commercial Zone population: " << commercialPop << endl;
                }

                while (SimMap[i][j]->GetType() == 'I')
                {
                    int industrialPop = 0;
                    industrialPop += SimMap[i][j]->GetPopulation();
                    cout << "Residential Zone population: " << industrialPop << endl;
                }
            }
        }
}


//Output the final regional pollution state
void Analysis::analysisPollution(vector<vector<Zone *>> &SimMap)
{
    int XPeak = XMax;
    int YPeak = YMax;
    for (int i = 0; i < YMax; ++i)
        {
            for (int j = 0; j < XMax; ++j)
            {
                while (SimMap[i][j]->GetType() == 'R')
                {
                    int pollution = 0;
                    int residentialPoll;
                    pollution += SimMap[i][j]->GetPollution();
                    residentialPoll = pollution;
                    cout << "Residential Zone pollution: " << residentialPoll << endl;
                }

                while (SimMap[i][j]->GetType() == 'C')
                {
                    int pollution = 0;
                    int commercialPoll;
                    pollution += SimMap[i][j]->GetPollution();
                    commercialPoll = pollution;
                    cout << "Commercial Zone pollution: " << commercialPoll << endl;
                }

                while (SimMap[i][j]->GetType() == 'I')
                {
                    int pollution = 0;
                    int industrialPoll;
                    pollution += SimMap[i][j]->GetPollution();
                    industrialPoll = pollution;
                    cout << "Industrial Zone pollution: " << industrialPoll << endl;
                }
            }
        }
}

//Output the total pollution in the region
void Analysis::printTotalPollution(vector<vector<Zone *>> &SimMap){
    int totalregionPoll = residentialPoll + commercialPoll + industrialPoll;
    cout << "The total pollution in the region is: " << totalregionPoll << endl;
    
}


//Prompt the user for the coordinates of some rectangular area of the region to analyze more closely
int Analysis::userAnalysis(int userX, int userY){
    
    /* 
    int userCoordinates;
    cout << "Enter the coordinates of the region that you want to analyze (x,y): ";
    getline(cin, userCoordinates);
    

    //check what char is in the user region
    if (userCoordinates)
    

    //You must perform bounds checking to make sure the coordinates are within the bounds of the region, and re-prompt the user if their coordinates are outside the bounds
    int XPeak = XMax;
    int YPeak = YMax;
    if (userX > XMax || userY > YMax)
    {
        cout << "Out of bounds, try again: ";
        getline(cin, userCoordinates);
    }

 */
    

}


//Output the total population for residential zones, industrial zones, and commercial zones within the area specified by the user
void Analysis::analysisPopulation(vector<vector<Zone *>> &SimMap){
    /*
    int XPeak = XMax;
    int YPeak = YMax;
    for (int i = userY; i < YMax; ++i)
	{
		for (int j = userX; j < XMax; ++j)
		{
            if (SimMap[i][j]->GetType() == 'R')
            {
                cout << "Residential Zone population: " << residentialPop << endl;
            }

            if (SimMap[i][j]->GetType() == 'C')
            {
                cout << "Commercial Zone population: " << commercialPop << endl;
            }

            if (SimMap[i][j]->GetType() == 'I')
            {
                cout << "Residential Zone population: " << industrialPop << endl;
        }

    }
    */

}



//Output the total pollution within the area specified by the user
void Analysis::analysisPollution(vector<vector<Zone *>> &SimMap){
    /*
    for (int i = userY; i < YMax; ++i)
	{
		for (int j = userX; j < XMax; ++j)
		{
            if (SimMap[i][j]->GetType() == 'R')
            {
                cout << "Residential Zone pollution: " << residentialPoll << endl;
            }

            if (SimMap[i][j]->GetType() == 'C')
            {
                cout << "Commercial Zone pollution: " << commercialPoll << endl;
            }

            if (SimMap[i][j]->GetType() == 'I')
            {
                cout << "Industrial Zone pollution: " << industrialPoll << endl;
            }
        }
        */
}
