#ifndef POLLUTION
#define POLLUTION

#include <iostream>
#include "Zone.h"

using namespace std;

class Pollution : public Zone
{
public:
    Pollution(int y, int x, char letter, int XMax, int YMax);
    void Compile(vector<vector<Zone *>> &SimMap);
    void adjacent(vector<vector<Zone *>> &SimMap);
    void setPollution(vector<vector<Zone *>> &SimMap);


private:
    int commercialPoll;
    int residentialPoll;
    int industrialPoll;
    int road;
    int pollution;
    int population;
};

#endif