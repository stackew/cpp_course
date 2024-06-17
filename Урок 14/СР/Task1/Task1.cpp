#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string string = "fas jdf jaf";

	std::replace(string.begin(), string.end(), ' ', '\t');
	
	std::cout << string;
	return 0;
}