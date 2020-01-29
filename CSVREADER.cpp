#include "CSVReader.h"



bool CSVReader::Read()
{
	vector<string> lines;

	string line;

	ifstream in(this->path);

	int i = 0;
	if (in.is_open())

	{
		while (in.good())
		{
			getline(in, line);
			lines.push_back(line);
		}
		in.close();

		this->lines = lines;
		return true;
	}
	else
	{
		return false;
	}
}

CSVReader::CSVReader(string path) {
	this->path = path;
}


CSVReader::~CSVReader()
{
}
