#pragma once
#include "Singleton.h"
#include <iostream>
#include <string>

class DebugManager
{
	friend class Singleton<DebugManager>;
public:
	bool CHECK(bool givemeabool, std::string TAG)
	{
		if (givemeabool)
		{
			std::cout << TAG << " ---> SUCEEDED" << std::endl;
			return true;
		}
		
		else
		{
			std::cout << TAG << " ---> FAILED" << std::endl;
			return false;
		}
	
		return true;

	}


private:
	DebugManager() {}
	DebugManager(const DebugManager&);
	DebugManager& operator=(const DebugManager&);
};

typedef Singleton<DebugManager> Debug;
