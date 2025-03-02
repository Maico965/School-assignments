#include "PowerLine.h"


void Compile(vector <vector<Zone*>> &SimMap) {

	int XMax;
	int YMax;
	
		if ((!(X - 1 == -1)) && (!(Y - 1 == -1))) {
			SimMap[X - 1][Y - 1]->SetPowerLine(true)
		}
		if (!(X - 1 == -1)) {
			SimMap[X - 1][Y]->SetPowerLine(true)
		}
		if ((!(X - 1 == -1)) && (!(Y + 1 > YMax)))
		{
			SimMap[X - 1][Y + 1]->SetPowerLine(true)
		}
		if ((!(Y - 1 == -1))) {
			SimMap[X][Y - 1]->SetPowerLine(true)
		}
		if (!(Y + 1 > YMax)) {
			SimMap[X][Y + 1]->SetPowerLine(true)
		}
		if ((!(X + 1 > XMax)) && (!(Y - 1 == -1))) {
			SimMap[X + 1][Y - 1]->SetPowerLine(true)
		}
		if (!(X + 1 > XMax)) {
			SimMap[X + 1][Y]->SetPowerLine(true)
		}
							
		if ((!(X + 1 > XMax)) && (!(Y + 1 > YMax))) {
			SimMap[X + 1][Y + 1]->SetPowerLine(true)
		}







}
