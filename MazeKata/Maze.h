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
	// Constructor
	Maze(int columns, int rows, std::vector<std::vector <char>>* outline);

	// Return reference to pointer to a Tile at location X,Y
	Tile* GetTile(int column, int row);

	// Print out maze
	void Display();
	// Used to display the path the solver took to solve the maze
	void DisplayResult();

	int GetWidth();
	int GetHeight();
	Tile GetStartPoint();

	// The following functions will be used by the solver object to know the total distance that the solver can move in any given direction 
	int GetOpenDistanceSouth(Tile currentTile);
	int GetOpenDistanceNorth(Tile currentTile);
	int GetOpenDistanceEast(Tile currentTile);
	int GetOpenDistanceWest(Tile currentTile);

	// Allow the solver object to check for finish point
	bool IsFinishPoint(Tile currentTile);

	// Once the solver object has finished, it gives the working demensions of the path
	void SetFinalPath(std::vector<Tile> finalPath);

private:

	// Internal dimensions
	int width, height;
	std::vector<std::vector<Tile>> outline;

	// Used to hold path taken to solve the maze
	Tile finalPath[];

	// Search through top row for open location, set start point
	bool FindStart();
	// Search through bottom row for open location, set end point
	bool FindFinish();
};

