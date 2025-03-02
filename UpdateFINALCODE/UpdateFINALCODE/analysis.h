#ifndef ANALYSIS
#define ANALYSIS


#include <iostream>
#include "Main.cpp"
#include "pollution.h"
#include "Industrial.h"
#include "Residential.h"
#include "Commercial.h"
#include "Zone.h"

using namespace std;

class Analysis : public Zone
{
public:
    Analysis(int y, int x, char letter, int XMax, int YMax);

    void Compile(vector<vector<Zone *>> &SimMap);
    
    void printRegion();                                                     //output final map

    void printZonePopulation(vector<vector<Zone *>> &SimMap);            //output each zone's population

    void printZonePollution(vector<vector<Zone *>> &SimMap);               //output each zone's pollution

    void printTotalPollution(vector<vector<Zone *>> &SimMap);                                       //output total pollution

    int userAnalysis(int userX, int userY);                                            //prompt user to enter coordinates to analyze more closely

    void analysisPopulation(vector<vector<Zone *>> &SimMap);                                        //population in the region the user entered

    void analysisPollution(vector<vector<Zone *>> &SimMap);                                         //pollution in the region the user entered
private:
    int residentialPoll;
    int commercialPoll;
    int industrialPoll;


};


#endif