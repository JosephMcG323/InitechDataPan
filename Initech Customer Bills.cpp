// Initech Customer Bills.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <string>
#include "Plan.h"
#include "CSVReader.h"


//float caluculateGold(float mins, float texts);
//float caluculateSilver(int mins, int texts);
//float caluculateBronze(int mins, int texts);



int main()
{

	float call, txt = 0.0;
	int selectedPlan = 0;

	CSVReader *test = new CSVReader("C:/Users/Joseph McGuinness/Desktop/Test.csv");


	vector<plan*> plans;


	string split = ",";
	string substr = "";
	if (test->Read()) {


		for (string line : test->lines) {

			//line = 	gold,20,1000,800
			std::string delimiter = ",";

			size_t pos = 0;
			std::string token;
			vector<string> lines;
			while ((pos = line.find(delimiter)) != std::string::npos) {
				token = line.substr(0, pos);
				lines.push_back(token);
				line.erase(0, pos + delimiter.length());
			}

			plans.push_back(new plan(lines[0], stod(lines[1]), stod(lines[2]), stod(lines[3]), stod(lines[4]), stod(lines[5]), stod(lines[6]), stod(lines[7]), stod(lines[8]), stod(lines[9])));

		}
	}


	cout << "How many minutes has the customer used?" << endl;

	cin >> call;

	cout << "How many text messages have they used?" << endl;

	cin >> txt;

	cout << "Select a plan:" << endl;
	for (int i = 0; i < plans.size(); i++)
	{
		cout << "[" << i << "]" << " " << plans[i]->name << endl;
	}
	
	cin >> selectedPlan;

	cout << plans[selectedPlan]->calculate(call, txt) << endl;

	cout << endl;


}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
