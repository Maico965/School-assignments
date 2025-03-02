#include <iostream>
#include <vector>
#include "Commercial.h"
using namespace std;

Commercial::Commercial(int x, int y, char letter, int XMax, int YMax)
{
    X = x;
    Y = y;
    type = letter;
    this->XMax = XMax;
    this->YMax = YMax;
}

void Commercial::Compile(vector<vector<Zone *>> &SimMap)
{
}

void Commercial::SetPopulation(vector<vector<Zone *>> &SimMap)
{
}

void Commercial::UpdatePop(vector<vector<Zone *>> &SimMap, int &workers)
{
}

void Commercial::IncrementPopulation(vector<vector<Zone *>> &SimMap, int &workers, int &goods)
{
}

void Commercial::ZeroGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{

    if (powered && (workers > 0) && (goods > 0))
    {
        SetIncrement(true);
        --workers;
        --goods;
    }
    if ((!powered) && (workers > 0) && (goods > 0) && (adjacentPopulation > 0))
    {
        SetIncrement(true);
        --workers;
        --goods;
    }
    SetChecked(true);
}

void Commercial::OneGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{

    if (((oneNext + twoNext + threeNext + fourNext + fiveNext) >= 2) && (workers > 0) && (goods > 0))
    {
        ++population;
        --workers;
        --goods;
    }
    SetChecked(true);
}

void Commercial::PopulationLoop(char letter, int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{

    int maxPopulation = 0;
    int tiePresent = 0;
    int y, x;
    bool decrementTime;
    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                SimMap[i][j]->GetPopulation() >= maxPopulation)
            {
                maxPopulation = SimMap[i][j]->GetPopulation();
            }
        }
    }

    while ((workers >= 1) && (goods >= 1))
    {

        for (int i = 0; i < YMax; ++i)
        {
            for (int j = 0; j < XMax; ++j)
            {
                if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                    SimMap[i][j]->GetPopulation() == maxPopulation)
                {
                    maxPopulation = SimMap[i][j]->GetPopulation();
                    x = i;
                    y = j;
                }
            }
        }

        for (int i = 0; i < YMax; ++i)
        {
            for (int j = 0; j < XMax; ++j)
            {
                if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                    SimMap[i][j]->GetPopulation() == maxPopulation)
                {
                    ++tiePresent;
                }
            }
        }

        if (tiePresent > 1)
        {
            AdjacencyLoop(letter, goods, workers, maxPopulation, SimMap);
        }

        else
        {
            if (SimMap[y][x]->GetPopulation() == 0)
            {
                SimMap[y][x]->ZeroGrow(goods, workers, SimMap);
            }
            else if (SimMap[y][x]->GetPopulation() == 1)
            {
                SimMap[y][x]->OneGrow(goods, workers, SimMap);
            }
            else
            {
                SimMap[y][x]->SetChecked(true);
            }
        }

        decrementTime = true;

        for (int i = 0; i < YMax; ++i)
        {
            for (int j = 0; j < XMax; ++j)
            {
                if ((SimMap[i][j]->GetType() == letter) && (SimMap[i][j]->GetPopulation() == maxPopulation) &&
                    (SimMap[i][j]->GetChecked() == false))
                {
                    decrementTime = false;
                }
            }
        }
        if (decrementTime == true)
        {
            --maxPopulation;
        }
    }
}

void Commercial::AdjacencyLoop(char letter, int &goods, int &workers, int maxPopulation, vector<vector<Zone *>> &SimMap)
{

    int maxAdjacency = 0;
    int tiePresent = 0;
    int y, x;

    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                (SimMap[i][j]->GetPopulation() == maxPopulation) && (SimMap[i][j]->GetAdjacency() >= maxAdjacency))
            {
                maxAdjacency = SimMap[i][j]->GetAdjacency();
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                (SimMap[i][j]->GetPopulation() == maxPopulation) && (SimMap[i][j]->GetAdjacency() == maxAdjacency))
            {
                ++tiePresent;
            }
        }
    }

    if (tiePresent > 1)
    {
        YLoop(letter, goods, workers, maxPopulation, maxAdjacency, SimMap);
    }

    else
    {
        if (SimMap[y][x]->GetPopulation() == 0)
        {
            SimMap[y][x]->ZeroGrow(goods, workers, SimMap);
        }
        else if (SimMap[y][x]->GetPopulation() == 1)
        {
            SimMap[y][x]->OneGrow(goods, workers, SimMap);
        }
        else
        {
            SimMap[y][x]->SetChecked(true);
        }
    }
}

void Commercial::YLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, vector<vector<Zone *>> &SimMap)
{

    int YPeak = YMax;
    int tiePresent = 0;
    int y, x;
    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                (SimMap[i][j]->GetAdjacency() == maxAdjacency) && (SimMap[i][j]->GetPopulation() == maxPopulation) &&
                (SimMap[i][j]->GetY() <= YPeak))
            {
                YPeak = SimMap[i][j]->GetY();
                x = i;
                y = j;
            }
        }
    }

    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                (SimMap[i][j]->GetAdjacency() == maxAdjacency) && (SimMap[i][j]->GetPopulation() == maxPopulation) &&
                (SimMap[i][j]->GetY() == YPeak))
            {
                ++tiePresent;
            }
        }
    }

    if (tiePresent > 1)
    {
        XLoop(letter, goods, workers, maxPopulation, maxAdjacency, YPeak, SimMap);
    }

    else
    {
        if (SimMap[y][x]->GetPopulation() == 0)
        {
            SimMap[y][x]->ZeroGrow(goods, workers, SimMap);
        }
        else if (SimMap[y][x]->GetPopulation() == 1)
        {
            SimMap[y][x]->OneGrow(goods, workers, SimMap);
        }
        else
        {
            SimMap[y][x]->SetChecked(true);
        }
    }
}

void Commercial::XLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, int YPeak, vector<vector<Zone *>> &SimMap)
{
    int XPeak = XMax;
    int tiePresent = 0;
    int y, x;
    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) &&
                (SimMap[i][j]->GetAdjacency() == maxAdjacency) && (SimMap[i][j]->GetPopulation() == maxPopulation) &&
                (SimMap[i][j]->GetY() == YPeak) && (SimMap[i][j]->GetX() <= XMax))
                XPeak = SimMap[i][j]->GetX();
            y = i;
            x = j;
        }
    }

    if (SimMap[y][x]->GetPopulation() == 0)
    {
        SimMap[y][x]->ZeroGrow(goods, workers, SimMap);
    }
    else if (SimMap[y][x]->GetPopulation() == 1)
    {
        SimMap[y][x]->OneGrow(goods, workers, SimMap);
    }
    else
    {
        SimMap[y][x]->SetChecked(true);
    }
}