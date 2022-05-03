#include <iostream>
#include "Algorithms.h"

// main entry point into the application

int main()
{
	std::cout << "Hello world!" << std::endl;
	
	if (!Algo::WriteMessage())
		std::cout << "FAILURE: method did not succeded!";

	return 0;
}