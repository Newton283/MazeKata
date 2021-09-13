#include <iostream>
#include <vector>
#include "UserStoryTesting.h"
#include "Tile.h"
#include "Maze.h"
#include "MazeSolver.h"

void UserStoryTesting::RunUserStories()
{
	if (UserStoryOne() &&
		UserStoryTwo() /*&&
		UserStoryThree() &&
		UserStoryFour() &&
		UserStoryFive()*/)
	{
		std::cout << "\nPassed All User Stories!";
	}
}

bool UserStoryTesting::UserStoryOne()
{
	std::cout << "%%% User Story 1 %%%\n\n";
	std::vector<char> row = { '%','~','%','%','%','%','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(7, 1, outline);
	maze.Display();

	std::cout << "Start point at: \nRow " << maze.GetStartPoint()->GetRow()
		<< "\nColumn " << maze.GetStartPoint()->GetColumn()
		<< "\nIcon " << maze.GetStartPoint()->GetDisplayChar();

	if ((maze.GetStartPoint()->GetRow() == 0) &&
		(maze.GetStartPoint()->GetColumn() == 1) &&
		(maze.GetStartPoint()->GetDisplayChar() == '~'))
	{
		"\nPassed User Story 1!\n";
		std::cout << "\n\n%%% End UserStory 1 %%%\n\n";
		return true;
	}
	else
	{
		"\Failed User Story 1!\n";
		std::cout << "\n\n%%% End UserStory 1 %%%\n\n";
		return false;
	}
}

bool UserStoryTesting::UserStoryTwo()
{
	std::cout << "%%% User Story 2 %%%\n\n";

	std::vector<char> row1 = { '%','%','~','%' };
	std::vector<char> row2 = { '%','%','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	MazeSolver solver(maze, maze->GetStartPoint());

	while (solver.GetHasSolvedMaze() != true)
	{
		maze->Display();
		solver.Move();
	}

	maze->Display();

	if (solver.GetHasSolvedMaze())
	{
		std::cout << "\nPassed User Story 2!\n";
		std::cout << "\n\n%%% End UserStory 2 %%%\n\n";
		return true;
	}
	else
	{
		std::cout << "\nFailed User Story 2!\n";
		std::cout << "\n\n%%% End UserStory 2 %%%\n\n";
		return false;
	}
}
