/*
Author: Evan Newton

Description: This file contains the 'main' function.

TODO add Maze Parser, Maze, and Maze Solver when done
*/

#include <iostream>
#include "UserStoryTesting.h"
int main()
{
	UserStoryTesting test;

	test.RunUserStories();
	
	std::cout << "Press ENTER to exit";
	int userInput = std::cin.get();
    return 0;
}