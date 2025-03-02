#include "Zone.h"

class Industrial : public Zone
{
public:
	Industrial(int x, int y, char letter, int XMax, int YMax);
	void Compile(vector<vector<Zone *>> &SimMap);
	void PopulationLoop(char letter, int &goods, int &workers, vector<vector<Zone *>> &SimMap);
	void AdjacencyLoop(char letter, int &goods, int &workers, int maxPopulation, vector<vector<Zone *>> &SimMap);
	void YLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, vector<vector<Zone *>> &SimMap);
	void XLoop(char letter, int &goods, int &workers, int maxPopulation, int maxAdjacency, int YPeak, vector<vector<Zone *>> &SimMap);
	void ZeroGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap);
	void OneGrow(int &goods, int &workers, vector<vector<Zone *>> &SimMap);
	void SetPopulation(vector<vector<Zone *>> &SimMap);
	void UpdatePop(vector<vector<Zone *>> &SimMap, int &workers);
	void SetPopulation(vector<vector<Zone *>> &SimMap);
	void IncrementPopulation(vector<vector<Zone *>> &SimMap, int &workers, int &goods);

private:
	int available_workers = 0;
	int population;
	int goods = 0;
	bool connection = true;
	string power;
	int pollution = 0;
	int adjacent;
};
