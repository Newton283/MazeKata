/*
Author: Evan Newton

Description: This class holds the maze itself.
	It will be generated by data passed in from the input file parser.
	The maze will be built with a 2D vector of Tile objects.
	0,0 will be in the top left hand (NW) corner of the maze.
	The maze will find the beginning and end points upon creation.
	Once created the maze will be passed to the solver object to solve the maze.
*/

#pragma once
#include <vector>
#include "Tile.h"

class Maze
{

public:
	// Constructor
	Maze(int columns, int rows, std::vector<std::vector <char> > const& outline);

	// Return reference to pointer to a Tile at location column,row indexed from 0
	Tile* GetTile(int column, int row);

	// Print out maze
	void Display();

	int GetColumns();
	int GetRows();
	Tile* GetStartPoint();

	// Allow the solver object to check for finish point
	bool IsFinishPoint(Tile* currentTile);

private:

	// Internal dimensions
	int columns, rows;

	// Stores maze outline with Tiles
	std::vector<std::vector<Tile>> outline;

	// Used to hold path taken to solve the maze
	std::vector<Tile> finalPath;

	// Store start and end tiles once found
	Tile *startTile, *finishTile;

	// Search through top row for open location, set start point
	bool FindStart();
	// Search through bottom row for open location, set end point
	bool FindFinish();
};

