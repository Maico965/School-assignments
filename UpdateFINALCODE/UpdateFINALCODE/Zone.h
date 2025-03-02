#ifndef ZONEH
#define ZONEH

#include <iostream>
#include <vector>

using namespace std;

class Zone
{
public:
	Zone();												 //
	Zone(int x, int y, char letter, int XMax, int YMax); //
	void SetType(char letter);							 //
	void SetPosition(int y, int x);						 //
	char GetType();										 //
	virtual void compile() = 0;
	void SetPowerLine(bool powerline);							//
	bool GetPowerline();										//
	int GetX();													//
	int GetY();													//
	int GetPopulation();										//
	int GetPollution();
	void SetEdgeBooleans(vector<vector<Zone *>> &SimMap);		//
	void SetAdjacentPopulation(vector<vector<Zone *>> &SimMap); //
	int GetAdjacency();
	void SetChecked(bool checked);	   //
	bool GetChecked();				   //
	void SetIncrement(bool increment); //
	bool GetIncrement();			   //
	void Deploy();

	// Virtuals for loops
	virtual void PopulationLoop(char letter, int &goods, int &workers) = 0;
	virtual void AdjacencyLoop(char letter, int &goods, int &workers, int maxPopulation) = 0;
	virtual void YLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency) = 0;
	virtual void XLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, int YPeak) = 0;
	virtual void ZeroGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap) = 0;
	virtual void OneGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap) = 0;
	virtual void SetPopulation(vector<vector<Zone *>> &SimMap) = 0;
	virtual void UpdatePop(vector<vector<Zone *>> &SimMap, int &workers) = 0;
	virtual void IncrementPopulation() = 0;

	// override these with my functions, changing the 1good/1worker requirement to two workers for industrial or using the "checked" boolean for residential
protected:
	int X, Y;
	int XMax;
	int YMax;
	char type;
	int zoneNum;

	int population = 0;
	int pollution = 0;
	bool powered = false;
	int adjacentPopulation = 0;

	bool XLow = false;
	bool XHigh = false;
	bool YLow = false;
	bool YHigh = false;

	// Counter for number of adjacent cells with the listed populations
	int oneNext = 0;
	int twoNext = 0;
	int threeNext = 0;
	int fourNext = 0;
	int fiveNext = 0;
	// run the SetAdjacentPopulation  function to update these values
	bool checked = false;
	bool increment = false;

	// bools for recursive function;
	bool populationCheck = false;
	bool adjacencyCheck = false;
	bool YCheck = false;
	bool XCheck = false;
};

#endif
