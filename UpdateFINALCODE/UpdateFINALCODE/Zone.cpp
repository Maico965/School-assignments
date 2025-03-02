#include <iostream>
#include <vector>
#include "Zone.h"
using namespace std;

Zone::Zone()
{
	type = 'a';
	X = 0;
	Y = 0;
	XMax = 0;
	YMax = 0;
}

Zone::Zone(int y, int x, char letter, int XMax, int YMax)
{
	Y = y;
	X = x;
	type = letter;
	this->XMax = XMax;
	this->YMax = YMax;
}

void Zone::SetType(char letter)
{
	type = letter;
}

void Zone::SetPosition(int y, int x)
{
	Y = y;
	X = x;
}

char Zone::GetType()
{

	return type;
}

void Zone::SetPowerLine(bool powerline)
{
	powered = powerline;
}

bool Zone::GetPowerline()
{
	return powered;
}

int Zone::GetX()
{

	return X;
}

int Zone::GetY()
{
	return Y;
}

int Zone::GetPopulation()
{
	return population;
}

int Zone::GetPollution(){
	return pollution;
}

void Zone::SetEdgeBooleans(vector<vector<Zone *>> &SimMap)
{

	if ((Y - 1) > -1)
	{
		YLow = true;
	}
	if ((Y + 1) <= YMax)
	{
		YHigh = true;
	}
	if ((X - 1) > -1)
	{
		XLow = true;
	}
	if ((X + 1) <= XMax)
	{
		XHigh = true;
	}
}

void Zone::SetAdjacentPopulation(vector<vector<Zone *>> &SimMap)
{

	adjacentPopulation = 0;
	oneNext = 0;
	twoNext = 0;
	threeNext = 0;
	fourNext = 0;
	fiveNext = 0;

	SetEdgeBooleans(SimMap);

	if (XLow)
	{
		if (YLow)
		{
			adjacentPopulation += SimMap[X - 1][Y - 1]->GetPopulation();
			if (SimMap[X - 1][Y - 1]->GetPopulation() == 1)
			{
				++oneNext;
			}
			if (SimMap[X - 1][Y - 1]->GetPopulation() == 2)
			{
				++twoNext;
			}
			if (SimMap[X - 1][Y - 1]->GetPopulation() == 3)
			{
				++threeNext;
			}
			if (SimMap[X - 1][Y - 1]->GetPopulation() == 4)
			{
				++fourNext;
			}
			if (SimMap[X - 1][Y - 1]->GetPopulation() == 5)
			{
				++fiveNext;
			}
		}

		adjacentPopulation += SimMap[X - 1][Y]->GetPopulation();

		if (SimMap[X - 1][Y]->GetPopulation() == 1)
		{
			++oneNext;
		}
		if (SimMap[X - 1][Y]->GetPopulation() == 2)
		{
			++twoNext;
		}
		if (SimMap[X - 1][Y]->GetPopulation() == 3)
		{
			++threeNext;
		}
		if (SimMap[X - 1][Y]->GetPopulation() == 4)
		{
			++fourNext;
		}
		if (SimMap[X - 1][Y]->GetPopulation() == 5)
		{
			++fiveNext;
		}

		if (YHigh)
		{

			if (SimMap[X - 1][Y + 1]->GetPopulation() == 1)
			{
				++oneNext;
			}
			if (SimMap[X - 1][Y + 1]->GetPopulation() == 2)
			{
				++twoNext;
			}
			if (SimMap[X - 1][Y + 1]->GetPopulation() == 3)
			{
				++threeNext;
			}
			if (SimMap[X - 1][Y + 1]->GetPopulation() == 4)
			{
				++fourNext;
			}
			if (SimMap[X - 1][Y + 1]->GetPopulation() == 5)
			{
				++fiveNext;
			}

			adjacentPopulation += SimMap[X - 1][Y + 1]->GetPopulation();
		}
	}

	if (YLow)
	{

		if (SimMap[X][Y - 1]->GetPopulation() == 1)
		{
			++oneNext;
		}
		if (SimMap[X][Y - 1]->GetPopulation() == 2)
		{
			++twoNext;
		}
		if (SimMap[X][Y - 1]->GetPopulation() == 3)
		{
			++threeNext;
		}
		if (SimMap[X][Y - 1]->GetPopulation() == 4)
		{
			++fourNext;
		}
		if (SimMap[X][Y - 1]->GetPopulation() == 5)
		{
			++fiveNext;
		}

		adjacentPopulation += SimMap[X][Y - 1]->GetPopulation();
	}

	if (YHigh)
	{

		if (SimMap[X][Y + 1]->GetPopulation() == 1)
		{
			++oneNext;
		}
		if (SimMap[X][Y + 1]->GetPopulation() == 2)
		{
			++twoNext;
		}
		if (SimMap[X][Y + 1]->GetPopulation() == 3)
		{
			++threeNext;
		}
		if (SimMap[X][Y + 1]->GetPopulation() == 4)
		{
			++fourNext;
		}
		if (SimMap[X][Y + 1]->GetPopulation() == 5)
		{
			++fiveNext;
		}

		adjacentPopulation += SimMap[X][Y + 1]->GetPopulation();
	}

	if (XHigh)
	{
		if (YLow)
		{

			if (SimMap[X + 1][Y - 1]->GetPopulation() == 1)
			{
				++oneNext;
			}
			if (SimMap[X + 1][Y - 1]->GetPopulation() == 2)
			{
				++twoNext;
			}
			if (SimMap[X + 1][Y - 1]->GetPopulation() == 3)
			{
				++threeNext;
			}
			if (SimMap[X + 1][Y - 1]->GetPopulation() == 4)
			{
				++fourNext;
			}
			if (SimMap[X + 1][Y - 1]->GetPopulation() == 5)
			{
				++fiveNext;
			}

			adjacentPopulation += SimMap[X + 1][Y - 1]->GetPopulation();
		}

		if (SimMap[X + 1][Y]->GetPopulation() == 1)
		{
			++oneNext;
		}
		if (SimMap[X + 1][Y]->GetPopulation() == 2)
		{
			++twoNext;
		}
		if (SimMap[X + 1][Y]->GetPopulation() == 3)
		{
			++threeNext;
		}
		if (SimMap[X + 1][Y]->GetPopulation() == 4)
		{
			++fourNext;
		}
		if (SimMap[X + 1][Y]->GetPopulation() == 5)
		{
			++fiveNext;
		}

		adjacentPopulation += SimMap[X + 1][Y]->GetPopulation();

		if (YHigh)
		{

			if (SimMap[X + 1][Y + 1]->GetPopulation() == 1)
			{
				++oneNext;
			}
			if (SimMap[X + 1][Y + 1]->GetPopulation() == 2)
			{
				++twoNext;
			}
			if (SimMap[X + 1][Y + 1]->GetPopulation() == 3)
			{
				++threeNext;
			}
			if (SimMap[X + 1][Y + 1]->GetPopulation() == 4)
			{
				++fourNext;
			}
			if (SimMap[X + 1][Y + 1]->GetPopulation() == 5)
			{
				++fiveNext;
			}

			adjacentPopulation += SimMap[X + 1][Y + 1]->GetPopulation();
		}
	}
}

int Zone::GetAdjacency()
{

	return adjacentPopulation;
}

void Zone::SetChecked(bool checked)
{
	this->checked = checked;
}

bool Zone::GetChecked()
{
	return checked;
}

void Zone::SetIncrement(bool increment)
{
	this->increment = increment;
}

bool Zone::GetIncrement()
{
	return increment;
}

void Zone::Deploy()
{
	++population;
}
