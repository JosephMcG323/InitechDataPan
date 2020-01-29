#pragma once
#include <iostream>
#include "conio.h"
#include <string>
using namespace std;

class plan
{
public:
	string name;
	plan(string name, double planCost, double planinclMins, double planinclTxtMsgs, double planFirstTierMins, double planFirstTierRate, double planSecondTierMin, double planSecondTierRate, double planFollowOnMin, double planFollowOnMsg);
	double calculate(int min, int texts);

private:

	int planCost = 0;
	double inclMins = 0;
	double inclTxtMsgs = 0;
	double FirstTierMins = 0;
	double FirstTierRate = 0;
	double SecondTierMin = 0;
	double SecondTierRate = 0;
	double FollowOnMin = 0;
	double FollowOnMsg = 0;

	double calculateTxt(int txt);

	double calculateMins(int mins);

};