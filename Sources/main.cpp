#include "split.h"
#include "complex.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
constexpr auto M_PI = 3.14159265358979323846264338327950288419716939937510;

using std::cout; using std::cin; using std::endl;
using std::pair; 
using std::string;
using std::getline; 
using std::vector;
using std::map;
using std::stod;
using std::find;

int main(int argc, char* argv[])
{
	string currbuff;
	map<string, complex> decs;
	while (getline(cin, currbuff))
	{
		vector<string> currentBuffer = split(currbuff);
		vector<string>::const_iterator i = currentBuffer.begin();
		i = find(currentBuffer.begin(), currentBuffer.end(), "=");
		if (i != currentBuffer.end())
		{
			decs[i[-1]] = complex(stod(i[1]), stod(i[2]));
			cout << "One Complex number defined with : \n\tName : " << i[-1] << "\n\tValue : " << decs[i[-1]] << endl;
			continue;
		}
		i = find(currentBuffer.begin(), currentBuffer.end(), "inverse");
		if (i != currentBuffer.end())
		{
			cout << 1 / decs[ i[1] ] << endl;
			continue;
		}
		i = find(currentBuffer.begin(), currentBuffer.end(), "mod");
		if (i != currentBuffer.end())
		{
			cout << decs[i[1]].mod() << endl;
			continue;
		}
		i = find(currentBuffer.begin(), currentBuffer.end(), "arg");
		if (i != currentBuffer.end())
		{
			cout << decs[i[1]].arg()*(180/M_PI) << endl;
			continue;
		}
		i = find(currentBuffer.begin(), currentBuffer.end(), "rotate");
		if (i != currentBuffer.end())
		{
			decs[i[1]].rotate(stod(i[2])*(M_PI/180));
			cout << decs[i[1]] << endl;
			continue;
		}
		i = find(currentBuffer.begin(), currentBuffer.end(), "log");
		if (i != currentBuffer.end())
		{
			cout << decs[i[1]].complex_log() << endl;
			continue;
		}
		i = find(currentBuffer.begin(), currentBuffer.end(), "sqrt");
		if (i != currentBuffer.end())
		{
			cout << decs[i[1]].complex_sqrt().first << endl;
			cout << decs[i[1]].complex_sqrt().second << endl;
			continue;
		}
		i = find(currentBuffer.begin(), currentBuffer.end(), "conjugate");
		if (i != currentBuffer.end())
		{
			cout << decs[i[1]].conjugate() << endl;
			continue;
		}
	}
}
