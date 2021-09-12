/*
Author: Evan Newton

Description: This class will be passed in the maze object and solve the maze.

TODO elaborate on algorithm

*/

#pragma once
#include <stack>
#include "Tile.h"
#include "Maze.h"

class MazeSolver
{
public:
	// Pass in the maze object and starting tile
	MazeSolver(Maze* maze);

	// Algorithm for moving, will move until end point reached
	void Move();

	// Return solved path of maze
	std::vector<Tile> GetPath();

	bool GetHasSolvedMaze();

private:
	Tile currentTile;

	// The path is a stack to make backing up a simple process
	std::stack<Tile> path;

	bool hasSolvedMaze;
};

