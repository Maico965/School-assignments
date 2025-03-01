#include <iostream>
#include "Zone.cpp"
#include "Residential.h"

using namespace std;

Residential::Residential(int zoneNum)
{
    zoneNum=zonePop;
}

void Residential::SetPopulation(vector <vector<Zone*>> &SimMap)
{
    for(i=0;i<XMax;i++)
    {
        for(j=0;j<YMax;j++)
        {
            if (SimMap[i][j].letter =='R')
            {
                SimMap[i][j].zoneNum = 0;
            }
        }

    }

}


void Residential::UpdatePop(vector <vector<Zone*>> &SimMap)
{
    int adjcheck=0;
    for(i=0;i<XMax;i++)
    {
        for(j=0;j<YMax;j++)
        {
            if ((SimMap[i][j].letter =='R' && SimMap[i][j].zoneNum==0) && ((SimMap[i-1][j-1].letter =='T' || SimMap[i-1][j].letter =='T' || SimMap[i][j-1].letter =='T' || SimMap[i+1][j+1].letter =='T' || SimMap[i+1][j].letter =='T' || SimMap[i][j+1].letter =='T' || SimMap[i-1][j+1].letter =='T' || SimMap[i+1][j-1].letter =='T'))
            {
                SimMap[i][j].zoneNum= SimMap[i][j].zoneNum + 1;

            }
            else if((SimMap[i][j].letter=='R' && SimMap[i][j].zoneNum ==0) && ((SimMap[i-1][j-1].letter=='R' && SimMap[i-1][j-1].zoneNum >=1) || (SimMap[i-1][j].letter=='R' && SimMap[i-1][j].zoneNum >=1) || (SimMap[i][j-1].letter =='R' && SimMap[i][j-1].zoneNum >=1) || (SimMap[i+1][j+1].letter =='R' && SimMap[i+1][j+1].zoneNum >=1) || (SimMap[i+1][j].letter =='R' && SimMap[i+1][j].zoneNum >=1) || (SimMap[i][j+1].letter =='R' && SimMap[i][j+1].zoneNum >=1) || (SimMap[i-1][j+1].letter =='R' && SimMap[i-1][j+1].zoneNum >=1) || (SimMap[i+1][j-1].letter =='R' && SimMap[i+1][j-1].zoneNum >=1)))
            {
                SimMap[i][j].zoneNum = SimMap[i][j].zoneNum +1;
                
            }
            else if ((SimMap[i][j].letter =='R' && SimMap[i][j].zoneNum ==1) && ((SimMap[i-1][j-1].letter =='R' && SimMap[i-1][j-1].zoneNum >=1) || (SimMap[i-1][j].letter =='R' && SimMap[i-1][j].zoneNum >=1) || (SimMap[i][j-1].letter =='R' && SimMap[i][j-1].zoneNum >=1) || (SimMap[i+1][j+1].letter =='R' && SimMap[i+1][j+1].zoneNum >=1) || (SimMap[i+1][j].letter =='R' && SimMap[i+1][j].zoneNum >=1) || (SimMap[i][j+1].letter =='R' && SimMap[i][j+1].zoneNum >=1) || (SimMap[i-1][j+1].letter =='R' && SimMap[i-1][j+1].zoneNum >=1) || (SimMap[i+1][j-1].letter =='R' && SimMap[i+1][j-1].zoneNum >=1)))
            {   
                for(t=0;t<XMax;t++)
                {
                    for(w=0;w<YMax;w++)
                    {
                        if(SimMap[t][w].zoneNum >=1)
                        {
                            adjcheck++;
                        }
                    }
                }

                if(adjcheck>=3)
                {
                    SimMap[i][j].zoneNum = SimMap[i][j].zoneNum +1;
                }
                else
                {
                    SimMap[i][j].zoneNum= SimMap[i][j].zoneNum+0;
                }
            }
            else if((SimMap[i][j].letter =='R' && SimMap[i][j].zoneNum ==2) && ((SimMap[i-1][j-1].letter =='R' && SimMap[i-1][j-1].zoneNum >=2) || (SimMap[i-1][j].letter =='R' && SimMap[i-1][j].zoneNum >=2) || (SimMap[i][j-1].letter == 'R' && SimMap[i][j-1].zoneNum >=2) || (SimMap[i+1][j+1].letter =='R' && SimMap[i+1][j+1].zoneNum >=2) || (SimMap[i+1][j].letter =='R' && SimMap[i+1][j].zoneNum >=2) || (SimMap[i][j+1].letter =='R' && SimMap[i][j+1].zoneNum >=2) || (SimMap[i-1][j+1].letter =='R' && SimMap[i-1][j+1].zoneNum >=2) || (SimMap[i+1][j-1].letter =='R' && SimMap[i+1][j-1].zoneNum >=2)))
            {
                for(t=0;t<XMax;t++)
                {
                    for(w=0;w<YMax;w++)
                    {
                        if(SimMap[t][w].zoneNum >=2)
                        {
                            adjcheck++;
                        }
                    }
                }

                 if(adjcheck>=5)
                {
                    SimMap[i][j].zoneNum = SimMap[i][j].zoneNum +1;
                }
                else
                {
                    SimMap[i][j].zoneNum= SimMap[i][j].zoneNum+0;
                }

            }
            else if((SimMap[i][j].letter =='R' && SimMap[i][j].zoneNum ==3) && ((SimMap[i-1][j-1].letter =='R' && SimMap[i-1][j-1].zoneNum >=3) || (SimMap[i-1][j].letter =='R' && SimMap[i-1][j].zoneNum >=3) || (SimMap[i][j-1].letter == 'R' && SimMap[i][j-1].zoneNum >=3) || (SimMap[i+1][j+1].letter =='R' && SimMap[i+1][j+1].zoneNum >=3) || (SimMap[i+1][j].letter =='R' && SimMap[i+1][j].zoneNum >=3) || (SimMap[i][j+1].letter =='R' && SimMap[i][j+1].zoneNum >=3) || (SimMap[i-1][j+1].letter =='R' && SimMap[i-1][j+1].zoneNum >=3) || (SimMap[i+1][j-1].letter =='R' && SimMap[i+1][j-1].zoneNum >=3)))
            {
                 for(t=0;t<XMax;t++)
                {
                    for(w=0;w<YMax;w++)
                    {
                        if(SimMap[t][w].zoneNum >=3)
                        {
                            adjcheck++;
                        }
                    }
                }

                 if(adjcheck>=7)
                {
                    SimMap[i][j].zoneNum = SimMap[i][j].zoneNum +1;
                }
                else
                {
                    SimMap[i][j].zoneNum= SimMap[i][j].zoneNum+0;
                }
            }
            else if ((SimMap[i][j].letter =='R' && SimMap[i][j].zoneNum ==4) && ((SimMap[i-1][j-1].letter =='R' && SimMap[i-1][j-1].zoneNum >=4) || (SimMap[i-1][j].letter =='R' && SimMap[i-1][j].zoneNum >=4) || (SimMap[i][j-1].letter == 'R' && SimMap[i][j-1].zoneNum >=4) || (SimMap[i+1][j+1].letter =='R' && SimMap[i+1][j+1].zoneNum >=4) || (SimMap[i+1][j].letter =='R' && SimMap[i+1][j].zoneNum >=4) || (SimMap[i][j+1].letter =='R' && SimMap[i][j+1].zoneNum >=4) || (SimMap[i-1][j+1].letter =='R' && SimMap[i-1][j+1].zoneNum >=4) || (SimMap[i+1][j-1].letter =='R' && SimMap[i+1][j-1].zoneNum >=4)))
            {
                 for(t=0;t<XMax;t++)
                {
                    for(w=0;w<YMax;w++)
                    {
                        if(SimMap[t][w].zoneNum >=3)
                        {
                            adjcheck++;
                        }
                    }
                }

                if(adjcheck>=9)
                {
                    SimMap[i][j].zoneNum = SimMap[i][j].zoneNum +1;
                }
                else
                {
                    SimMap[i][j].zoneNum= SimMap[i][j].zoneNum+0;
                }
            }
        }

    }

}