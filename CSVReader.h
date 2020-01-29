#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#pragma once
using namespace std;

class CSVReader
{

private:
	string path;

public:

	vector<string> lines;
	bool Read();
	CSVReader(string path);
	~CSVReader();
};

