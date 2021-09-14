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

	/* Call until GetHasSolvedMaze returns true.
	 Will move in any open direction available. Once a move has taken place,
	 the tile will be written with a path character. Open moves are any moves
	 that are not boundary OR path pieces. If the solver gets stuck at a dead
	 end, it will back up until a new path choice is available */
	void Move();

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
	Tile* lastTile;
	Maze* maze;
	const char pathChar = '#';
	const char currentChar = '@';
	const char openChar = '~';

	// Move current tile a single square in any direction
	// Save tile in path stack
	// Set current tile to pathChar before moving
	// Once moved, set currentTile with currentChar
	// Clear lastTile pathChar (used for backing up)
	void MoveSouth();
	void MoveNorth();
	void MoveEast();
	void MoveWest();
	// Continue to set currentTile to prevous tiles from path stack
	// Set lastTile to pathChar, this allows the solver to move in a
	// new direction once it has backed up to an area with a new opening
	void Backup();

	// The path is a stack to make backing up a simple process
	std::stack<Tile*> path;

	bool hasSolvedMaze;
};

