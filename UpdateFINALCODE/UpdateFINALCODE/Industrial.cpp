#include <iostream>
#include <string>
#include <vector>
#include "Zone.h"
#include "Industrial.h"

using namespace std;

Industrial::Industrial(int x, int y, char letter, int XMax, int YMax)
{
    X = x;
    Y = y;
    type = letter;
    this->XMax = XMax;
    this->YMax = YMax;
}

void Industrial::Compile(vector<vector<Zone *>> &SimMap)
{
}

void Industrial::PopulationLoop(char letter, int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
    int maxPopulation = 0;
    int tiePresent = 0;
    int y, x;
    bool decrementTime;
    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) && SimMap[i][j]->GetPopulation() >= maxPopulation)
            {
                maxPopulation = SimMap[i][j]->GetPopulation();
            }
        }
    }

    while (workers > 1)
    {

        for (int i = 0; i < YMax; ++i)
        {
            for (int j = 0; j < XMax; ++j)
            {
                if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) && SimMap[i][j]->GetPopulation() == maxPopulation)
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
                if ((SimMap[i][j]->GetChecked() == false) && (SimMap[i][j]->GetType() == letter) && SimMap[i][j]->GetPopulation() == maxPopulation)
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
                if ((SimMap[i][j]->GetType() == letter) && (SimMap[i][j]->GetPopulation() == maxPopulation) && (SimMap[i][j]->GetChecked() == false))
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
void Industrial::AdjacencyLoop(char letter, int &goods, int &workers, int maxPopulation, vector<vector<Zone *>> &SimMap)
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

void Industrial::YLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, vector<vector<Zone *>> &SimMap)
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

    IncrementPopulation(SimMap, workers, goods);
}


void Industrial::XLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, int YPeak, vector<vector<Zone *>> &SimMap)
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

    IncrementPopulation(SimMap, workers, goods);
}

void Industrial::ZeroGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}
void Industrial::OneGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}
void Industrial::UpdatePop(vector<vector<Zone *>> &SimMap, int &workers)
{
}
void Industrial::SetPopulation(vector<vector<Zone *>> &SimMap)
{
}
void Industrial::IncrementPopulation(vector<vector<Zone *>> &SimMap, int &workers, int &goods)
{
}

void Industrial::SetPopulation(vector<vector<Zone *>> &SimMap)
{
    int XPeak = XMax;
    int YPeak = YMax;
    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++i)
        {
            if (SimMap[i][j]->GetType() == 'I')
            {
            }
        }
    }
}

void Industrial::IncrementPopulation(vector<vector<Zone *>> &SimMap, int &workers, int &goods)
{
    adjacent = 0;
    for (int i = 0; i < YMax; ++i)
        {
            for (int j = 0; j < XMax; ++j)
            {
                SimMap[i][j]->SetChecked(true);
                i = Y;
                j = X;

                if ((SimMap[i][j]->GetType() == 'I' && SimMap[i][j]->GetPopulation() == 0) && (SimMap[i - 1][j - 1]->GetType() == 'T' || SimMap[i - 1][j]->GetType() == 'T' 
                || SimMap[i][j - 1]->GetType() == 'T' || SimMap[i + 1][j + 1]->GetType() == 'T' || SimMap[i + 1][j]->GetType() == 'T' || SimMap[i][j + 1]->GetType() == 'T' 
                || SimMap[i - 1][j + 1]->GetType() == 'T' || SimMap[i + 1][j - 1]->GetType() == 'T') && (workers >= 2))
                {
                    SimMap[i][j]->SetIncrement(true);

                    ++goods;
                    workers = workers - 2;
                }

                else if ((SimMap[i][j]->GetType() == 'I' && SimMap[i][j]->GetPopulation() == 0) &&
                         ((SimMap[i - 1][j - 1]->GetType() == 'I' && SimMap[i - 1][j - 1]->GetPopulation() >= 1) || (SimMap[i - 1][j]->GetType() == 'I' && SimMap[i - 1][j]->GetPopulation() >= 1) || 
                         (SimMap[i][j - 1]->GetType() == 'I' && SimMap[i][j - 1]->GetPopulation() >= 1) || (SimMap[i + 1][j + 1]->GetType() == 'I' && SimMap[i + 1][j + 1]->GetPopulation() >= 1) || 
                         (SimMap[i + 1][j]->GetType() == 'I' && SimMap[i + 1][j]->GetPopulation() >= 1) || (SimMap[i][j + 1]->GetType() == 'I' && SimMap[i][j + 1]->GetPopulation() >= 1) || 
                         (SimMap[i - 1][j + 1]->GetType() == 'I' && SimMap[i - 1][j + 1]->GetPopulation() >= 1) || (SimMap[i + 1][j - 1]->GetType() == 'I' && SimMap[i + 1][j - 1]->GetPopulation() >= 1)) 
                         && (workers >= 2))
                {
                    SimMap[i][j]->SetIncrement(true);

                    ++goods;
                    workers = workers - 2;
                }

                else if ((SimMap[i][j]->GetType() == 'I' && SimMap[i][j]->GetPopulation() == 1) && (workers >= 2))
                {
                    if (SimMap[i - 1][j - 1]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i - 1][j]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i][j - 1]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i - 1][j + 1]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i][j + 1]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i + 1][j + 1]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i + 1][j]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i + 1][j - 1]->GetPopulation() >= 1)
                    {
                        ++adjacent;
                    }
                    if (adjacent >= 2)
                    {
                        SimMap[i][j]->SetIncrement(true);
                        ++goods;
                        workers = workers - 2;
                    }
                }

                else if ((SimMap[i][j]->GetType() == 'I' && SimMap[i][j]->GetPopulation() == 2) && (workers >= 2))
                {
                    if (SimMap[i - 1][j - 1]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i - 1][j]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i][j - 1]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i - 1][j + 1]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i][j + 1]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i + 1][j + 1]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i + 1][j]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    else if (SimMap[i + 1][j - 1]->GetPopulation() >= 2)
                    {
                        ++adjacent;
                    }
                    if (adjacent >= 4)
                    {
                        SimMap[i][j]->SetIncrement(true);
                        ++goods;
                        workers = workers - 2;
                    }
                }
            }
        }
}