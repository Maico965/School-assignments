#include <iostream>
#include "Zone.h"


using namespace std;

Zone::Zone() {
	type = 'a';
	X = 0;
	Y = 0;
}

Zone::Zone(int y, int x, char letter) {
	Y = y;
	X = x;
	type = letter;



}



void Zone::SetType(char letter) {
	type = letter;




}

void Zone::SetPosition(int y, int x) {
	Y = y;
	X=x;



}

char Zone::GetType() {


	return type;
}

int Zone::GetX() {

	return X;


}


int Zone::GetY() {
	return Y;


}


void SetPowerLine(bool powerline) {
	powered = powerline



}
bool GetPowerline() {


	return powered;

}