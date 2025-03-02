#include <iostream>
#include <vector>
#include "pollution.h"
#include "Industrial.h"
#include "Industrial.cpp"
#include "Zone.h"
#include "main.cpp"

using namespace std;

// compile
void Pollution::Compile(vector<vector<Zone *>> &SimMap)
{
}

Pollution::Pollution(int x, int y, char letter, int XMax, int YMax)
{
    X = x;
    Y = y;
    type = letter;
    this->XMax = XMax;
    this->YMax = YMax;
}

// set the industrial cell pollution = population
void Pollution::setPollution(vector<vector<Zone *>> &SimMap)
{
    int XPeak = XMax;
    int YPeak = YMax;
    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            // pollution for industrial cells is based on their population
            while ((SimMap[i][j]->GetType() == 'I'))
            {
                // checking each cell
                if ((SimMap[i - 1][j - 1]))
                {
                    pollution = population;
                }

                if ((SimMap[i - 1][j]))
                {
                    pollution = population;
                }

                if ((SimMap[i][j - 1]))
                {
                    pollution = population;
                }

                if ((SimMap[i - 1][j + 1]))
                {
                    pollution = population;
                }

                if ((SimMap[i][j + 1]))
                {
                    pollution = population;
                }

                if ((SimMap[i + 1][j + 1]))
                {
                    pollution = population;
                }

                if ((SimMap[i + 1][j]))
                {
                    pollution = population;
                }

                if ((SimMap[i + 1][j - 1]))
                {
                    pollution = population;
                }
            }
        }
    }
}

void Pollution::adjacent(vector<vector<Zone *>> &SimMap)
{
    // loop through adjacent cells
    // set pollution as (pollution -1) for adjacent

    /* Adjacent cells
    1) SimMap[i - 1][j - 1]

    2) SimMap[i - 1][j]

    3) SimMap[i][j - 1]

    4) SimMap[i + 1][j + 1]

    5) SimMap[i + 1][j]

    6) SimMap[i][j + 1]

    7) SimMap[i - 1][j + 1]

    8) SimMap[i + 1][j - 1]
    */
   
    int XPeak = XMax;
    int YPeak = YMax;
    for (int i = 0; i < YMax; ++i)
    {
        for (int j = 0; j < XMax; ++j)
        {
            while ((SimMap[i][j]->GetType() == 'I' || SimMap[i][j]->GetType() == 'R' || SimMap[i][j]->GetType() == 'C' || SimMap[i][j]->GetType() == '-'))
            {
                // check each adjacent cell for R (residential)
                if ((SimMap[i - 1][j - 1]->GetType() == 'R') || (SimMap[i - 1][j]->GetType() == 'R') || (SimMap[i][j - 1]->GetType() == 'R') ||
                    (SimMap[i + 1][j + 1]->GetType() == 'R') || (SimMap[i + 1][j]->GetType() == 'R') || (SimMap[i][j + 1]->GetType() == 'R') ||
                    (SimMap[i - 1][j + 1]->GetType() == 'R') || (SimMap[i + 1][j - 1]->GetType() == 'R'))
                {
                    ++residentialPoll;
                    pollution = population - 1;
                }

                // check each adjacent cell for C (commercial)
                else if ((SimMap[i - 1][j - 1]->GetType() == 'C') || (SimMap[i - 1][j]->GetType() == 'C') || (SimMap[i][j - 1]->GetType() == 'C') ||
                         (SimMap[i + 1][j + 1]->GetType() == 'C') || (SimMap[i + 1][j]->GetType() == 'C') || (SimMap[i][j + 1]->GetType() == 'C') ||
                         (SimMap[i - 1][j + 1]->GetType() == 'C') || (SimMap[i + 1][j - 1]->GetType() == 'C'))
                {
                    ++commercialPoll;
                    pollution = population - 1;
                }

                // check each adjacent cell for - (road)
                else if ((SimMap[i - 1][j - 1]->GetType() == '-') || (SimMap[i - 1][j]->GetType() == '-') || (SimMap[i][j - 1]->GetType() == '-') ||
                         (SimMap[i + 1][j + 1]->GetType() == '-') || (SimMap[i + 1][j]->GetType() == '-') || (SimMap[i][j + 1]->GetType() == '-') ||
                         (SimMap[i - 1][j + 1]->GetType() == '-') || (SimMap[i + 1][j - 1]->GetType() == '-'))
                {
                    ++road;
                    pollution = population - 1;
                }

                // check each adjacent cell for I (industrial pollution doesn't decrease based on pop.)
                else if ((SimMap[i - 1][j - 1]->GetType() == 'I') || (SimMap[i - 1][j]->GetType() == 'I') || (SimMap[i][j - 1]->GetType() == 'I') ||
                         (SimMap[i + 1][j + 1]->GetType() == 'I') || (SimMap[i + 1][j]->GetType() == 'I') || (SimMap[i][j + 1]->GetType() == 'I') ||
                         (SimMap[i - 1][j + 1]->GetType() == 'I') || (SimMap[i + 1][j - 1]->GetType() == 'I'))
                {
                    ++industrialPoll;
                }
            }
        }
    }
}
