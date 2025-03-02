#include <iostream>
#include <vector>
#include "PL.h"
using namespace std;

PL::PL(int x, int y, char letter, int XMax, int YMax)
{
	X = x;
	Y = y;
	type = letter;
	this->XMax = XMax;
	this->YMax = YMax;
}

void PL::Compile(vector<vector<Zone *>> &SimMap)
{
}

void PL::PopulationLoop(char letter, int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}

void PL::AdjacencyLoop(char letter, int &goods, int &workers, int maxPopulation, vector<vector<Zone *>> &SimMap)
{
}

void PL::YLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, vector<vector<Zone *>> &SimMap)
{
}

void PL::XLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, int YPeak, vector<vector<Zone *>> &SimMap)
{
}

void PL::ZeroGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}

void PL::OneGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}

void PL::SetPopulation(vector<vector<Zone *>> &SimMap)
{
}

void PL::UpdatePop(vector<vector<Zone *>> &SimMap, int &workers)
{
}

void PL::IncrementPopulation(vector<vector<Zone *>> &SimMap, int &workers, int &goods)
{
}


void PL::Compile(vector<vector<Zone *>> &SimMap)
{

	// int XMax;
	// int YMax;

	if ((!(X - 1 == -1)) && (!(Y - 1 == -1)))
	{
		SimMap[X - 1][Y - 1]->SetPowerLine(true);
	}

	if (!(X - 1 == -1))
	{
		SimMap[X - 1][Y]->SetPowerLine(true);
	}

	if ((!(X - 1 == -1)) && (!(Y + 1 > YMax)))
	{
		SimMap[X - 1][Y + 1]->SetPowerLine(true);
	}

	if ((!(Y - 1 == -1)))
	{
		SimMap[X][Y - 1]->SetPowerLine(true);
	}

	if (!(Y + 1 > YMax))
	{
		SimMap[X][Y + 1]->SetPowerLine(true);
	}

	if ((!(X + 1 > XMax)) && (!(Y - 1 == -1)))
	{
		SimMap[X + 1][Y - 1]->SetPowerLine(true);
	}
	
	if (!(X + 1 > XMax))
	{
		SimMap[X + 1][Y]->SetPowerLine(true);
	}

	if ((!(X + 1 > XMax)) && (!(Y + 1 > YMax)))
	{
		SimMap[X + 1][Y + 1]->SetPowerLine(true);
	}
}
