#include <iostream>
#include <vector>
#include "Residential.h"

using namespace std;

Residential::Residential(int x, int y, char letter, int XMax, int YMax)
{
    X = x;
    Y = y;
    type = letter;
    this->XMax = XMax;
    this->YMax = YMax;
}

void Residential::Compile(vector<vector<Zone *>> &SimMap)
{
}
void Residential::PopulationLoop(char letter, int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}
void Residential::AdjacencyLoop(char letter, int &goods, int &workers, int maxPopulation, vector<vector<Zone *>> &SimMap)
{
}
void Residential::YLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, vector<vector<Zone *>> &SimMap)
{
}
void Residential::XLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, int YPeak, vector<vector<Zone *>> &SimMap)
{
}
void Residential::ZeroGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}
void Residential::OneGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap)
{
}

void Residential::IncrementPopulation(vector<vector<Zone *>> &SimMap, int &workers, int &goods)
{
}


void Residential::SetPopulation(vector<vector<Zone *>> &SimMap)
{
    for (int i = 0; i < XMax; i++)
    {
        for (int j = 0; j < YMax; j++)
        {
            if (SimMap[i][j]->GetType() == 'R')
            {
                SimMap[i][j]->SetIncrement(false);
            }
        }
    }
}


void Residential::UpdatePop(vector<vector<Zone *>> &SimMap, int &workers)
{
    int adjcheck = 0;
    for (int i = 0; i < YMax; i++)
    {
        for (int j = 0; j < XMax; j++)
        {
            if ((SimMap[i][j]->GetType() =='R' && SimMap[i][j]->GetType() ==0) && ((SimMap[i-1][j-1]->GetType() =='T' 
            || SimMap[i-1][j]->GetType() =='T' || SimMap[i][j-1]->GetType() =='T' || SimMap[i+1][j+1]->GetType() =='T' 
            || SimMap[i+1][j]->GetType() =='T' || SimMap[i][j+1]->GetType() =='T' || SimMap[i-1][j+1]->GetType() =='T' 
            || SimMap[i+1][j-1]->GetType() =='T')))
            {
                SimMap[i][j]->SetIncrement(true);
                ++workers;

            }

            else if ((SimMap[i][j]->GetType()=='R' && SimMap[i][j]->GetPopulation() ==0) && 
            ((SimMap[i-1][j-1]->GetType()=='R' && SimMap[i-1][j-1]->GetPopulation() >=1) || 
            (SimMap[i-1][j]->GetType()=='R' && SimMap[i-1][j]->GetPopulation() >=1) || 
            (SimMap[i][j-1]->GetType() =='R' && SimMap[i][j-1]->GetPopulation() >=1) || 
            (SimMap[i+1][j+1]->GetType() =='R' && SimMap[i+1][j+1]->GetPopulation() >=1) || 
            (SimMap[i+1][j]->GetType() =='R' && SimMap[i+1][j]->GetPopulation() >=1) || 
            (SimMap[i][j+1]->GetType() =='R' && SimMap[i][j+1]->GetPopulation() >=1) || 
            (SimMap[i-1][j+1]->GetType() =='R' && SimMap[i-1][j+1]->GetPopulation() >=1) || 
            (SimMap[i+1][j-1]->GetType() =='R' && SimMap[i+1][j-1]->GetPopulation() >=1)))
            {
                SimMap[i][j]->SetIncrement(true);
                ++workers;
                
            }

            else if ((SimMap[i][j]->GetType() =='R' && SimMap[i][j]->GetPopulation() ==1) && 
            ((SimMap[i-1][j-1]->GetType() =='R' && SimMap[i-1][j-1]->GetPopulation() >=1) || 
            (SimMap[i-1][j]->GetType() =='R' && SimMap[i-1][j]->GetPopulation() >=1) || 
            (SimMap[i][j-1]->GetType() =='R' && SimMap[i][j-1]->GetPopulation() >=1) || 
            (SimMap[i+1][j+1]->GetType() =='R' && SimMap[i+1][j+1]->GetPopulation() >=1) || 
            (SimMap[i+1][j]->GetType() =='R' && SimMap[i+1][j]->GetPopulation() >=1) || 
            (SimMap[i][j+1]->GetType() =='R' && SimMap[i][j+1]->GetPopulation() >=1) || 
            (SimMap[i-1][j+1]->GetType() =='R' && SimMap[i-1][j+1]->GetPopulation() >=1) || 
            (SimMap[i+1][j-1]->GetType() =='R' && SimMap[i+1][j-1]->GetPopulation() >=1)))
            {
                for (int t = 0; t < YMax; t++)
                {
                    for (int w = 0; w < XMax; w++)
                    {
                        if (SimMap[t][w]->GetPopulation() >= 1)
                        {
                            adjcheck++;
                        }
                    }
                }

                if (adjcheck >= 3)
                {
                    SimMap[i][j]->SetIncrement(true);
                    ++workers;
                }

                else
                {
                    SimMap[i][j]->SetIncrement(false);
                }
            }

            else if ((SimMap[i][j]->GetType() =='R' && SimMap[i][j]->GetPopulation() ==2) && 
            ((SimMap[i-1][j-1]->GetType() =='R' && SimMap[i-1][j-1]->GetPopulation() >=2) || 
            (SimMap[i-1][j]->GetType() =='R' && SimMap[i-1][j]->GetPopulation() >=2) || 
            (SimMap[i][j-1]->GetType() == 'R' && SimMap[i][j-1]->GetPopulation() >=2) || 
            (SimMap[i+1][j+1]->GetType() =='R' && SimMap[i+1][j+1]->GetPopulation() >=2) || 
            (SimMap[i+1][j]->GetType() =='R' && SimMap[i+1][j]->GetPopulation() >=2) || 
            (SimMap[i][j+1]->GetType() =='R' && SimMap[i][j+1]->GetPopulation() >=2) || 
            (SimMap[i-1][j+1]->GetType() =='R' && SimMap[i-1][j+1]->GetPopulation() >=2) || 
            (SimMap[i+1][j-1]->GetType() =='R' && SimMap[i+1][j-1]->GetPopulation() >=2)))
            {
                for (int t = 0; t < XMax; t++)
                {
                    for (int w = 0; w < YMax; w++)
                    {
                        if (SimMap[t][w]->GetPopulation() >= 2)
                        {
                            adjcheck++;
                        }
                    }
                }

                if (adjcheck >= 5)
                {
                    SimMap[i][j]->SetIncrement(true);
                    ++workers;
                }

                else
                {
                    SimMap[i][j]->SetIncrement(false);
                }

            }

            else if((SimMap[i][j]->GetType() =='R' && SimMap[i][j]->GetPopulation() ==3) && 
            ((SimMap[i-1][j-1]->GetType() =='R' && SimMap[i-1][j-1]->GetPopulation() >=3) || 
            (SimMap[i-1][j]->GetType() =='R' && SimMap[i-1][j]->GetPopulation() >=3) || 
            (SimMap[i][j-1]->GetType() == 'R' && SimMap[i][j-1]->GetPopulation() >=3) || 
            (SimMap[i+1][j+1]->GetType() =='R' && SimMap[i+1][j+1]->GetPopulation() >=3) || 
            (SimMap[i+1][j]->GetType() =='R' && SimMap[i+1][j]->GetPopulation() >=3) || 
            (SimMap[i][j+1]->GetType() =='R' && SimMap[i][j+1]->GetPopulation() >=3) || 
            (SimMap[i-1][j+1]->GetType() =='R' && SimMap[i-1][j+1]->GetPopulation() >=3) || 
            (SimMap[i+1][j-1]->GetType() =='R' && SimMap[i+1][j-1]->GetPopulation() >=3)))
            {
                for (int t = 0; t < XMax; t++)
                {
                    for (int w = 0; w < YMax; w++)
                    {
                        if (SimMap[t][w]->GetPopulation() >= 3)
                        {
                            adjcheck++;
                        }
                    }
                }

                if (adjcheck >= 7)
                {
                    SimMap[i][j]->SetIncrement(true);
                    ++workers;
                }

                else
                {
                    SimMap[i][j]->SetIncrement(false);
                }
            }

            else if ((SimMap[i][j]->GetType() =='R' && SimMap[i][j]->GetPopulation() ==4) && 
            ((SimMap[i-1][j-1]->GetType() =='R' && SimMap[i-1][j-1]->GetPopulation() >=4) || 
            (SimMap[i-1][j]->GetType() =='R' && SimMap[i-1][j]->GetPopulation() >=4) || 
            (SimMap[i][j-1]->GetType() == 'R' && SimMap[i][j-1]->GetPopulation() >=4) || 
            (SimMap[i+1][j+1]->GetType() =='R' && SimMap[i+1][j+1]->GetPopulation() >=4) || 
            (SimMap[i+1][j]->GetType() =='R' && SimMap[i+1][j]->GetPopulation() >=4) || 
            (SimMap[i][j+1]->GetType() =='R' && SimMap[i][j+1]->GetPopulation() >=4) || 
            (SimMap[i-1][j+1]->GetType() =='R' && SimMap[i-1][j+1]->GetPopulation() >=4) || 
            (SimMap[i+1][j-1]->GetType() =='R' && SimMap[i+1][j-1]->GetPopulation() >=4)))
            {
                for (int t = 0; t < XMax; t++)
                {
                    for (int w = 0; w < YMax; w++)
                    {
                        if (SimMap[t][w]->GetPopulation() >= 3)
                        {
                            adjcheck++;
                        }
                    }
                }

                if (adjcheck >= 9)
                {
                    SimMap[i][j]->SetIncrement(true);
                    ++workers;
                }

                else
                {
                    SimMap[i][j]->SetIncrement(false);
                }
            }
        }
    }
}
