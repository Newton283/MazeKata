#include <iostream>
#include "MazeSolver.h"

MazeSolver::MazeSolver(Maze* maze, Tile* currentTile)
{
	if (maze == NULL || currentTile == NULL)
	{
		std::cout << "MazeSolver not initialized\n";
		return;
	}
	this->maze = maze;
	this->currentTile = currentTile;
	this->currentTile->SetDisplayChar(currentChar);
	hasSolvedMaze = false;
}

void MazeSolver::Move()
{
	if (GetOpenDistanceSouth() > 0)
	{
		int currentRow = currentTile->GetRow();
		currentTile->SetDisplayChar(pathChar);
		currentTile = maze->GetTile(currentTile->GetColumn(), (currentRow + 1));
		currentTile->SetDisplayChar(currentChar);
		std::cout << "Moving South \n";
	} 
	else if (GetOpenDistanceNorth() > 0)
	{
		int currentRow = currentTile->GetRow();
		currentTile->SetDisplayChar(pathChar);
		currentTile = maze->GetTile(currentTile->GetColumn(), (currentRow - 1));
		currentTile->SetDisplayChar(currentChar);
		std::cout << "Moving North \n";
	} 
	else if (GetOpenDistanceEast() > 0)
	{
		int currentColumn = currentTile->GetColumn();
		currentTile->SetDisplayChar(pathChar);
		currentTile = maze->GetTile((currentColumn + 1), currentTile->GetRow());
		currentTile->SetDisplayChar(currentChar);
		std::cout << "Moving East \n";
	} 
	else if (GetOpenDistanceWest() > 0)
	{
		int currentColumn = currentTile->GetColumn();
		currentTile->SetDisplayChar(pathChar);
		currentTile = maze->GetTile((currentColumn - 1), currentTile->GetRow());
		currentTile->SetDisplayChar(currentChar);
		std::cout << "Moving West \n";
	}
	else
	{
		std::cout << "No valid move\n";
	}

	if (maze->IsFinishPoint(currentTile))
	{
		hasSolvedMaze = true;
	}
}

int MazeSolver::GetOpenDistanceSouth()
{
	if (currentTile == NULL)
	{
		return 0;
	}
	int currentRow = currentTile->GetRow();
	int currentColumn = currentTile->GetColumn();
	int distanceSouth = 0;

	Tile* tile = maze->GetTile(currentColumn, currentRow);

	if (tile->IsBoundary() == true)
	{
		return 0;
	}

	// Start looking for open spaces one row below current row
	for (int i = currentRow + 1; i < maze->GetRows(); i++)
	{
		tile = maze->GetTile(currentColumn, i);
		// Look for boundary OR path already taken
		if (tile->IsBoundary() == false &&
			tile->GetDisplayChar() != pathChar)
		{
			distanceSouth++;
		}
		else
		{
			break;
		}
	}

	return distanceSouth;
}

int MazeSolver::GetOpenDistanceNorth()
{
	if (currentTile == NULL)
	{
		return 0;
	}
	int currentRow = currentTile->GetRow();
	int currentColumn = currentTile->GetColumn();
	int distanceNorth = 0;

	Tile* tile = maze->GetTile(currentColumn, currentRow);

	if (tile->IsBoundary() == true)
	{
		return 0;
	}

	// Start looking for open spaces one row above current row
	for (int i = currentRow - 1; i >= 0; i--)
	{
		tile = maze->GetTile(currentColumn, i);
		if (tile->IsBoundary() == false &&
			tile->GetDisplayChar() != pathChar)
		{
			distanceNorth++;
		}
		else
		{
			break;
		}
	}

	return distanceNorth;
}

int MazeSolver::GetOpenDistanceEast()
{
	if (currentTile == NULL)
	{
		return 0;
	}
	int currentRow = currentTile->GetRow();
	int currentColumn = currentTile->GetColumn();
	int distanceEast = 0;

	Tile* tile = maze->GetTile(currentColumn, currentRow);

	if (tile->IsBoundary() == true)
	{
		return 0;
	}

	// Start looking for open spaces one row below current row
	for (int i = currentColumn + 1; i < maze->GetColumns(); i++)
	{
		tile = maze->GetTile(i, currentRow);
		if (tile->IsBoundary() == false &&
			tile->GetDisplayChar() != pathChar)
		{
			distanceEast++;
		}
		else
		{
			break;
		}
	}

	return distanceEast;
}

int MazeSolver::GetOpenDistanceWest()
{
	if (currentTile == NULL)
	{
		return 0;
	}
	int currentRow = currentTile->GetRow();
	int currentColumn = currentTile->GetColumn();
	int distanceWest = 0;

	Tile* tile = maze->GetTile(currentColumn, currentRow);

	if (tile->IsBoundary() == true)
	{
		return 0;
	}

	// Start looking for open spaces one row above current row
	for (int i = currentColumn - 1; i >= 0; i--)
	{
		tile = maze->GetTile(i, currentRow);
		if (tile->IsBoundary() == false &&
			tile->GetDisplayChar() != pathChar)
		{
			distanceWest++;
		}
		else
		{
			break;
		}
	}

	return distanceWest;
}

bool MazeSolver::GetHasSolvedMaze()
{
	return hasSolvedMaze;
}