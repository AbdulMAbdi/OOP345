// Workshop <Workshop 1>
// Name: <Abdul Abdi>
// Student #: <146779186>
// Course: OOP345 Summer 2019
// File: <w1.cpp>

#include <iostream> 
#include "process.h" 



using namespace sict; 

extern const int INITIAL = 3; 

int main(int argc, const char* argv[])
{
	std::cout << "Command Line : "; 
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << " "; 
	}
	std::cout << std::endl; 
	if (argc < 2)
	{
		std::cerr << "***Insufficient number of arguments***" << std::endl; 
		return 1; 
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			process(argv[i]); 
		}

		return 0; 
	}
}

