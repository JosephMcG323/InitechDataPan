#include "plan.h"
#include <iostream>
#include "conio.h"
#include <string>
using namespace std;


plan::plan(string name, double planCost, double planinclMins, double planinclTxtMsgs, double planFirstTierMins, double planFirstTierRate,
	double planSecondTierMin, double planSecondTierRate, double planFollowOnMin, double planFollowOnMsg){

	this->name = name;
	this->planCost = planCost;
	this->inclMins = planinclMins;
	this->inclTxtMsgs = planinclTxtMsgs;
	this->FirstTierMins = planFirstTierMins;
	this->FirstTierRate = planFirstTierRate;
	this->SecondTierMin = planSecondTierMin;
	this->SecondTierRate = planSecondTierRate;
	this->FollowOnMin = planFollowOnMin;
	this->FollowOnMsg = planFollowOnMsg;

}

double plan::calculate(int mins, int texts) {

	return (this->planCost + this->calculateTxt(texts) + this->calculateMins(mins));
}

double plan::calculateTxt(int texts) {

	double cost = 0;

	if (texts > this->FollowOnMsg)
	{
		cost = (texts - this->inclTxtMsgs) * this->FollowOnMsg;

		return cost;
	}

	else 
	{
		cost = 0;
	}


	return cost;

}



double plan::calculateMins(int mins) {

	// mins = 1000

	double cost = 0;
	/// inclMins 500
	if (mins <= this->inclMins) {
		return 0;
	}
	// all mins not included
	mins = mins - this->inclMins; // 500


	/// FirstTierMins 50
	if (mins <= this->FirstTierMins) {
		// they only used tier mins
		cost = (mins * this->FirstTierRate); // 1
		return cost;
	}
	// all mins not included & all first mins not included
	else {
		mins = mins - this->FirstTierMins; // 450
		cost = this->FirstTierMins * this->FirstTierRate; // 450
	}

	/// SecondTierMin 500
	if (mins <= this->SecondTierMin) { // 2
		// they only used tier mins
		cost = cost + (mins * this->SecondTierRate); // 900
		return cost; // 900
	}
	else {
		mins = mins - this->SecondTierMin; // 430
		cost = cost + this->SecondTierMin * this->SecondTierRate; // 860
	}


	cost = cost + (mins * FollowOnMin); // 860 + (430 * 1)

	return cost; // 1290
}





