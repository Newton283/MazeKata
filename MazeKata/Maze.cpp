#include <iostream>
#include "Maze.h"
#include "Tile.h"

Maze::Maze(int columns, int rows, std::vector<std::vector <char> > const& outline)
{
	if (rows != outline.size() || columns != outline[0].size())
	{
		this->columns = 0;
		this->rows = 0;
		std::cout << "Size mismatch\n";
		return;
	}
	this->columns = columns;
	this->rows = rows;

	this->outline.resize(rows);
	for (int i = 0; i < outline.size(); i++)
	{
		this->outline[i].resize(columns);
		for (int j = 0; j < outline[i].size(); j++)
		{
			bool boundary = outline[i][j] == '%' ? true : false;
			Tile tile(j, i, boundary);
			this->outline[i][j] = tile;
		}
	}
	

	FindStart();
}

Tile* Maze::GetTile(int column, int row)
{
	if ((column > (columns - 1) ) ||
		(column < 0) ||
		(row > (rows -1) ) ||
		(row < 0))
	{
		return NULL;
	}
	else
	{
		return &outline[row][column];
	}
	
}

void Maze::Display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << outline[i][j].GetDisplayChar();
		}
		std::cout << "\n";
	}
}

bool Maze::FindStart()
{
	if (outline.size() > 0 && outline[0].size() > 0)
	{
		for (int i = 0; i < columns; i++)
		{
			if (outline[0][i].IsBoundary() == false)
			{
				startTile = &outline[0][i];
				return true;
			}
		}
	}
	
	startTile = NULL;
	return false;
}

Tile* Maze::GetStartPoint()
{
	return startTile;
}

int Maze::GetRows()
{
	return rows;
}

int Maze::GetColumns()
{
	return columns;
}
