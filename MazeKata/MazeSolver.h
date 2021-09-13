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
	MazeSolver(Maze* maze, Tile* currentTile);

	// Algorithm for moving, will move until end point reached
	void Move();

	// Return solved path of maze
	std::vector<Tile> GetPath();

	// Used to find the total distance that the solver can move in any given direction 
	// Will return 0 if input points to a boundary piece
	// TODO move these to private
	int GetOpenDistanceSouth();
	int GetOpenDistanceNorth();
	int GetOpenDistanceEast();
	int GetOpenDistanceWest();

	bool GetHasSolvedMaze();

private:
	Tile* currentTile;
	Maze* maze;
	const char pathChar = '#';
	const char currentChar = '@';
	const char openChar = '~';

	// The path is a stack to make backing up a simple process
	std::stack<Tile> path;

	bool hasSolvedMaze;
};

