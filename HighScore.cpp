#include "HighScore.h"
#include <algorithm>
#include <string>





HighScore::HighScore()
{
	std::cout << "HIGHSCORE STATE" << std::endl;
}

bool wayToSort(float i, float j) { return i < j; }


HighScore::~HighScore()
{
	_hg.clear();
}


void HighScore::Initialise()
{
	for (size_t i = 0; i < 10; i++)
	{
		_hg.push_back(100);
	}	

	std::fstream file("HIGHSCORE.list" , std::ios::in| std::ios::binary);
	
	if (!file)
	{
		file.open("HIGHSCORE.list", std::ios::out|std::ios::binary);
		if (file.bad())
		{
			std::cout << "File opening FAILED";
		}

		for (int i = 0; i < 10; i++)
		{
			file.write((char*)&_hg[i], sizeof(float));
		}
		
		file.close();
		file.open("HIGHSCORE.list", std::ios::in | std::ios::binary);
	}

	for (int i = 0; i < 10; i++)
	{
		file.read((char*)&_hg[i], sizeof(float));
	}

	file.close();

}

void HighScore::Reset()
{
	_hg.clear();
	_hg.resize(10);

	std::fstream file;

	file.open("HIGHSCORE.list", std::ios::out | std::ios::binary);
		
	if (file.bad())
		{
			std::cout << "File opening FAILED";
		}

	for (int i = 0; i < 10; i++)
	{
		file.write((char*)&_hg[i], sizeof(float));
	}
		
	file.close();
}

void HighScore::UpdateHighscore(float s)
{
	std::fstream file;

	file.open("HIGHSCORE.list", std::ios::out | std::ios::binary);
		
	if (file.bad())
		{
			std::cout << "File opening FAILED";
		}

	
	_hg.push_back(s);
	std::sort(_hg.begin(), _hg.end(), wayToSort);
	_hg.pop_back();
	
	for (int i = 0; i < 10; i++)
	{
		file.write((char*)&_hg[i], sizeof(float));
	}
		
	file.close();
}

std::vector<float>& HighScore::GetHighscore()
{
	return _hg;
}
