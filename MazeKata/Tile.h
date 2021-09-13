/*
Author: Evan Newton

Description: This class holds information about each tile piece in the maze.
*/

#pragma once
class Tile
{
public:
	// Constructor 
	Tile();
	Tile(int column, int row, bool isBoundary);

	int GetColumn();
	int GetRow();

	// Display char used for printing out maze
	char GetDisplayChar();

	// Identify boundary tiles
	bool IsBoundary();

	// Allow non-boundary tiles to be filled with solver location or path history.
	// Return true if display char is set. Will return false if boundary char is 
	// attempted to be changed
	bool SetDisplayChar(char c);

private:

	int column;
	int row;
	bool isBoundary;
	char displayChar;
};

