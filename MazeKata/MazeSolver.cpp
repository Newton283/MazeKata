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
	lastTile = NULL;
}

void MazeSolver::Move()
{
	if (GetOpenDistanceSouth() > 0)
	{
		MoveSouth();
	} 
	else if (GetOpenDistanceNorth() > 0)
	{	
		MoveNorth();
	} 
	else if (GetOpenDistanceEast() > 0)
	{	
		MoveEast();
	} 
	else if (GetOpenDistanceWest() > 0)
	{
		MoveWest();
	}
	else
	{
		Backup();
	}

	if (maze->IsFinishPoint(currentTile))
	{
		path.push(currentTile);
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

void MazeSolver::MoveSouth()
{
	int currentRow = currentTile->GetRow();
	if (lastTile != NULL)
	{
		lastTile->SetDisplayChar(openChar);
		lastTile = NULL;
	}
	currentTile->SetDisplayChar(pathChar);
	path.push(currentTile);
	currentTile = maze->GetTile(currentTile->GetColumn(), (currentRow + 1));
	currentTile->SetDisplayChar(currentChar);
	std::cout << "Moving South \n";
}

void MazeSolver::MoveNorth()
{
	int currentRow = currentTile->GetRow();
	if (lastTile != NULL)
	{
		lastTile->SetDisplayChar(openChar);
		lastTile = NULL;
	}
	currentTile->SetDisplayChar(pathChar);
	path.push(currentTile);
	currentTile = maze->GetTile(currentTile->GetColumn(), (currentRow - 1));
	currentTile->SetDisplayChar(currentChar);
	std::cout << "Moving North \n";
}

void MazeSolver::MoveEast()
{
	int currentColumn = currentTile->GetColumn();
	if (lastTile != NULL)
	{
		lastTile->SetDisplayChar(openChar);
		lastTile = NULL;
	}
	currentTile->SetDisplayChar(pathChar);
	path.push(currentTile);
	currentTile = maze->GetTile((currentColumn + 1), currentTile->GetRow());
	currentTile->SetDisplayChar(currentChar);
	std::cout << "Moving East \n";
}

void MazeSolver::MoveWest()
{
	int currentColumn = currentTile->GetColumn();
	if (lastTile != NULL)
	{
		lastTile->SetDisplayChar(openChar);
		lastTile = NULL;
	}
	currentTile->SetDisplayChar(pathChar);
	path.push(currentTile);
	currentTile = maze->GetTile((currentColumn - 1), currentTile->GetRow());
	currentTile->SetDisplayChar(currentChar);
	std::cout << "Moving West \n";
}

void MazeSolver::Backup()
{
	if (lastTile != NULL)
	{
		lastTile->SetDisplayChar('~');
	}
	lastTile = currentTile;
	lastTile->SetDisplayChar(pathChar);

	currentTile = path.top();
	path.pop();
	currentTile->SetDisplayChar(currentChar);
	std::cout << "No valid move, backing up\n";
}

bool MazeSolver::GetHasSolvedMaze()
{
	return hasSolvedMaze;
}