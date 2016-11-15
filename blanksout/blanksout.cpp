// blanksout.cpp
// Corey Gray
// 14 Nov 2016
// CS 201 Assignment 7: Takes a map<int, string> and strips out leading or following blanks.

#include "blanksout.h"
#include <map>
using std::map;
#include <string>
using std::string;
#include <utility>
using std::get;

void blanksOut(map<int, string> & data)
{
	for (auto& p : data)
	{		
		string& value = get<1>(p);

		if (value.empty())
			break;

		while (true)
		{
			if (value.empty())
				break;
			
			if (isblank(value[0]))
				value.erase(0, 1);

			else
				break;
		}

		while (true)
		{			
			if (value.empty())
				break;

			if (isblank(value[ value.size() - 1 ]))
				value.erase( value.size() - 1 );

			else
				break;
		}
	}
}