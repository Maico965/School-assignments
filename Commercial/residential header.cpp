#ifndef RESIDENTIALH
#define RESIDENTIALH

#include <iostream>

using namespace std;

class Residential{
public:
Residential();
void SetPopulation(int population);
void UpdatePop(int newpopulation);

private:
int Population=0;
int zonePop;

};

#endif