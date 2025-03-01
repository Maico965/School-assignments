#ifndef ZONEH
#define ZONEH

#include <iostream>

using namespace std;


class Zone{
public:

	Zone();
	Zone(int x, int y, char letter);
	void SetType(char letter);
	void SetPosition(int y, int x);
	char GetType();
	virtual void compile() = 0;
	void SetPowerLine(bool powerline);
	bool GetPowerline();




private:
	int X, Y;
	int XMax, YMax;
	char type;

	bool powered = false; 
	int adjacentPopulation = 0;


};

#endif
