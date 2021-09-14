#include <iostream>
#include <vector>
#include "UserStoryTesting.h"
#include "Tile.h"
#include "Maze.h"
#include "MazeSolver.h"

void UserStoryTesting::RunUserStories()
{
	if (UserStoryOne() &&
		UserStoryTwo() &&
		UserStoryThree() &&
		UserStoryFour() &&
		UserStoryFive() &&
		UserStoryFiveAlt() &&
		UserStoryBackgroundMaze())
	{
		std::cout << "\nPassed All User Stories!\n\n";
	}
}

bool UserStoryTesting::UserStoryOne()
{
	std::cout << "%%% User Story 1 %%%\n\n";
	std::cout << "Legend: %(Boundary)   ~(OpenMaze)\n\n";
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
		std::cout << "\nPassed User Story 1!\n";
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
	std::cout << "Legend: %(Boundary)   ~(OpenMaze)   #(SolverPath)   @(SolverLocation)\n\n";

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

bool UserStoryTesting::UserStoryThree()
{
	std::cout << "%%% User Story 3 %%%\n\n";
	std::cout << "Legend: %(Boundary)   ~(OpenMaze)   #(SolverPath)   @(SolverLocation)\n\n";

	std::vector<char> row1 = { '%','~','%','%','%' };
	std::vector<char> row2 = { '%','~','~','~','%' };
	std::vector<char> row3 = { '%','~','~','~','%' };
	std::vector<char> row4 = { '%','%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(5, 4, outline);

	MazeSolver solver(maze, maze->GetStartPoint());

	while (solver.GetHasSolvedMaze() != true)
	{
		maze->Display();
		solver.Move();
	}

	maze->Display();

	if (solver.GetHasSolvedMaze())
	{
		std::cout << "\nPassed User Story 3!\n";
		std::cout << "\n\n%%% End UserStory 3 %%%\n\n";
		return true;
	}
	else
	{
		std::cout << "\nFailed User Story 3!\n";
		std::cout << "\n\n%%% End UserStory 3 %%%\n\n";
		return false;
	}
}

bool UserStoryTesting::UserStoryFour()
{
	std::cout << "%%% User Story 4 %%%\n\n";
	std::cout << "Legend: %(Boundary)   ~(OpenMaze)   #(SolverPath)   @(SolverLocation)\n\n";

	std::vector<char> row1 = { '%','~','%','%','%' };
	std::vector<char> row2 = { '%','~','~','~','%' };
	std::vector<char> row3 = { '%','%','%','~','%' };
	std::vector<char> row4 = { '%','~','~','~','%' };
	std::vector<char> row5 = { '%','~','%','%','%' };
	std::vector<char> row6 = { '%','~','~','~','%' };
	std::vector<char> row7 = { '%','%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);
	outline.push_back(row5);
	outline.push_back(row6);
	outline.push_back(row7);

	Maze* maze = new Maze(5, 7, outline);

	MazeSolver solver(maze, maze->GetStartPoint());

	while (solver.GetHasSolvedMaze() != true)
	{
		maze->Display();
		solver.Move();
	}

	maze->Display();

	if (solver.GetHasSolvedMaze())
	{
		std::cout << "\nPassed User Story 4!\n";
		std::cout << "\n\n%%% End UserStory 4 %%%\n\n";
		return true;
	}
	else
	{
		std::cout << "\nFailed User Story 4!\n";
		std::cout << "\n\n%%% End UserStory 4 %%%\n\n";
		return false;
	}
}

bool UserStoryTesting::UserStoryFive()
{
	std::cout << "%%% User Story 5 %%%\n\n";
	std::cout << "Legend: %(Boundary)   ~(OpenMaze)   #(SolverPath)   @(SolverLocation)\n\n";

	std::vector<char> row1 = { '%','~','%','%','%' };
	std::vector<char> row2 = { '%','~','~','~','%' };
	std::vector<char> row3 = { '%','~','%','%','%' };
	std::vector<char> row4 = { '%','~','~','~','%' };
	std::vector<char> row5 = { '%','~','%','~','%' };
	std::vector<char> row6 = { '%','%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);
	outline.push_back(row5);
	outline.push_back(row6);

	Maze* maze = new Maze(5, 6, outline);

	MazeSolver solver(maze, maze->GetStartPoint());

	while (solver.GetHasSolvedMaze() != true)
	{
		maze->Display();
		solver.Move();
	}

	maze->Display();

	if (solver.GetHasSolvedMaze())
	{
		std::cout << "\nPassed User Story 5!\n";
		std::cout << "\n\n%%% End UserStory 5 %%%\n\n";
		return true;
	}
	else
	{
		std::cout << "\nFailed User Story 5!\n";
		std::cout << "\n\n%%% End UserStory 5 %%%\n\n";
		return false;
	}
}

bool UserStoryTesting::UserStoryFiveAlt()
{
	std::cout << "%%% User Story 5 Alt %%%\n\n";
	std::cout << "Legend: %(Boundary)   ~(OpenMaze)   #(SolverPath)   @(SolverLocation)\n\n";
	std::cout << "% Testing Double Backup %";

	std::vector<char> row1 = { '%','~','%','%','%' };
	std::vector<char> row2 = { '%','~','~','~','%' };
	std::vector<char> row3 = { '%','~','%','%','%' };
	std::vector<char> row4 = { '%','~','~','~','%' };
	std::vector<char> row5 = { '%','~','%','~','%' };
	std::vector<char> row6 = { '%','~','%','~','%' };
	std::vector<char> row7 = { '%','%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);
	outline.push_back(row5);
	outline.push_back(row6);
	outline.push_back(row7);

	Maze* maze = new Maze(5, 7, outline);

	MazeSolver solver(maze, maze->GetStartPoint());

	while (solver.GetHasSolvedMaze() != true)
	{
		maze->Display();
		solver.Move();
	}

	maze->Display();

	if (solver.GetHasSolvedMaze())
	{
		std::cout << "\nPassed User Story 5 Alt!\n";
		std::cout << "\n\n%%% End UserStory 5 Alt %%%\n\n";
		return true;
	}
	else
	{
		std::cout << "\nFailed User Story 5 Alt!\n";
		std::cout << "\n\n%%% End UserStory 5 Alt %%%\n\n";
		return false;
	}
}

bool UserStoryTesting::UserStoryBackgroundMaze()
{
	std::cout << "%%% User Story Background Maze %%%\n\n";
	std::cout << "Legend: %(Boundary)   ~(OpenMaze)   #(SolverPath)   @(SolverLocation)\n\n";

	std::vector<char> row1  = { '%','%','%','%','~','%','%','%','%','%' };
	std::vector<char> row2  = { '%','~','~','~','~','~','~','~','~','%' };
	std::vector<char> row3  = { '%','~','%','%','%','~','%','%','~','%' };
	std::vector<char> row4  = { '%','%','%','~','~','~','~','%','~','%' };
	std::vector<char> row5  = { '%','~','~','~','%','%','%','%','~','%' };
	std::vector<char> row6  = { '%','%','%','~','~','~','%','~','~','%' };
	std::vector<char> row7  = { '%','~','%','%','%','~','%','%','%','%' };
	std::vector<char> row8  = { '%','~','~','~','~','~','%','%','~','%' };
	std::vector<char> row9  = { '%','%','~','%','%','~','~','~','~','%' };
	std::vector<char> row10 = { '%','%','%','%','%','%','%','~','%','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);
	outline.push_back(row5);
	outline.push_back(row6);
	outline.push_back(row7);
	outline.push_back(row8);
	outline.push_back(row9);
	outline.push_back(row10);

	Maze* maze = new Maze(10, 10, outline);

	MazeSolver solver(maze, maze->GetStartPoint());

	while (solver.GetHasSolvedMaze() != true)
	{
		maze->Display();
		solver.Move();
	}

	maze->Display();

	if (solver.GetHasSolvedMaze())
	{
		std::cout << "\nPassed User Story Background Maze!\n";
		std::cout << "\n\n%%% End UserStory Background Maze %%%\n\n";
		return true;
	}
	else
	{
		std::cout << "\nFailed User Story Background Maze!\n";
		std::cout << "\n\n%%% End UserStory Background Maze %%%\n\n";
		return false;
	}
}