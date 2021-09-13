#include "pch.h"
#include "../MazeKata/Tile.cpp"
#include "../MazeKata/Maze.cpp"
#include "../MazeKata/MazeSolver.cpp"

/////////////////////////////////////////////////////////////////////////////////////
// Tile /////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
TEST(TestTileObject, LocationIsZero_Zero)
{
	Tile tile(0, 0, false);
	EXPECT_EQ(0, tile.GetColumn());
	EXPECT_EQ(0, tile.GetRow());
}

TEST(TestTileObject, LocationIsOne_Two)
{
	Tile tile(1, 2, false);
	EXPECT_EQ(1, tile.GetColumn());
	EXPECT_EQ(2, tile.GetRow());
}

TEST(TestTileObject, IsBoundaryIsFalse)
{
	Tile tile(1, 2, false);
	EXPECT_EQ(false, tile.IsBoundary());
}

TEST(TestTileObject, IsBoundaryIsTrue)
{
	Tile tile(1, 2, true);
	EXPECT_EQ(true, tile.IsBoundary());
}

TEST(TestTileObject, IsNonBoundaryCharacter)
{
	Tile tile(1, 2, false);
	EXPECT_EQ('~', tile.GetDisplayChar());
}

TEST(TestTileObject, IsBoundaryCharacter)
{
	Tile tile(1, 2, true);
	EXPECT_EQ('%', tile.GetDisplayChar());
}

TEST(TestTileObject, FailsToSetDisplayChar)
{
	Tile tile(1, 2, true);
	bool setDisplayCharSuccess = tile.SetDisplayChar('@');
	EXPECT_EQ(false, setDisplayCharSuccess);
	// Ensure the original display char didn't change
	EXPECT_EQ('%', tile.GetDisplayChar());
}

TEST(TestTileObject, SetsDisplayCharToAtSign)
{
	Tile tile(1, 2, false);
	bool setDisplayCharSuccess = tile.SetDisplayChar('@');
	EXPECT_EQ(true, setDisplayCharSuccess);
	// Ensure the original display char changed
	EXPECT_EQ('@', tile.GetDisplayChar());
}

/////////////////////////////////////////////////////////////////////////////////////
// Maze /////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
TEST(TestMazeObject, GetTileReturnsCorrectlyZero_Zero)
{
	std::vector<char> row = { '~' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(1, 1, outline);

	Tile* pTile = maze.GetTile(0, 0);
	EXPECT_EQ(0, pTile->GetColumn());
	EXPECT_EQ(0, pTile->GetRow());
	EXPECT_EQ('~', pTile->GetDisplayChar());
}

TEST(TestMazeObject, GetTileReturnsCorrectlyOne_Zero)
{
	std::vector<char> row = { '%','~','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(3, 1, outline);

	Tile* pTile = maze.GetTile(1, 0);
	EXPECT_EQ(1, pTile->GetColumn());
	EXPECT_EQ(0, pTile->GetRow());
	EXPECT_EQ('~', pTile->GetDisplayChar());
}

TEST(TestMazeObject, GetTileReturnsNull)
{
	std::vector<char> row = { '~' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(1, 1, outline);

	Tile* pTile = maze.GetTile(1, 0);
	EXPECT_EQ(NULL, pTile);
}

TEST(TestMazeObject, MazeRowColumnInitialCorrectlyThreeByOne)
{
	std::vector<char> row = { '%','~','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(3, 1, outline);

	EXPECT_EQ(3, maze.GetColumns());
	EXPECT_EQ(1, maze.GetRows());
}

TEST(TestMazeObject, MazeRowColumnInitialCorrectlyOneByThree)
{
	std::vector<char> row1 = { '%' };
	std::vector<char> row2 = { '~' };
	std::vector<char> row3 = { '%' };
	std::vector<std::vector<char>> outline;
	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze maze(1, 3, outline);

	EXPECT_EQ(1, maze.GetColumns());
	EXPECT_EQ(3, maze.GetRows());
}
TEST(TestMazeObject, SingleRowInitializesCorrectly)
{
	std::vector<char> row = { '%','~','%'};
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(3, 1, outline);

	Tile* pTile = maze.GetTile(0, 0);
	EXPECT_EQ(0, pTile->GetColumn());
	EXPECT_EQ(0, pTile->GetRow());
	EXPECT_EQ('%', pTile->GetDisplayChar());
	pTile = maze.GetTile(1, 0);
	EXPECT_EQ(1, pTile->GetColumn());
	EXPECT_EQ(0, pTile->GetRow());
	EXPECT_EQ('~', pTile->GetDisplayChar());
	pTile = maze.GetTile(2, 0);
	EXPECT_EQ(2, pTile->GetColumn());
	EXPECT_EQ(0, pTile->GetRow());
	EXPECT_EQ('%', pTile->GetDisplayChar());
}

TEST(TestMazeObject, SingleColumnInitializesCorrectly)
{
	std::vector<char> row1 = { '%' };
	std::vector<char> row2 = { '~' };
	std::vector<char> row3 = { '%' };
	std::vector<std::vector<char>> outline;
	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze maze(1, 3, outline);

	Tile* pTile = maze.GetTile(0, 0);
	EXPECT_EQ(0, pTile->GetColumn());
	EXPECT_EQ(0, pTile->GetRow());
	EXPECT_EQ('%', pTile->GetDisplayChar());
	pTile = maze.GetTile(0, 1);
	EXPECT_EQ(0, pTile->GetColumn());
	EXPECT_EQ(1, pTile->GetRow());
	EXPECT_EQ('~', pTile->GetDisplayChar());
	pTile = maze.GetTile(0, 2);
	EXPECT_EQ(0, pTile->GetColumn());
	EXPECT_EQ(2, pTile->GetRow());
	EXPECT_EQ('%', pTile->GetDisplayChar());
}

TEST(TestMazeObject, TwoDimensionalMazeInitializesCorrectly)
{
	std::vector<char> row1 = { '%','~','%' };
	std::vector<char> row2 = { '~','~','%' };
	std::vector<char> row3 = { '%','~','%' };
	std::vector<std::vector<char>> outline;
	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze maze(3, 3, outline);

	Tile* pTile = maze.GetTile(0, 0);
	EXPECT_EQ('%', pTile->GetDisplayChar());
	pTile = maze.GetTile(1, 0);
	EXPECT_EQ('~', pTile->GetDisplayChar());
	pTile = maze.GetTile(2, 0);
	EXPECT_EQ('%', pTile->GetDisplayChar());

	pTile = maze.GetTile(0, 1);
	EXPECT_EQ('~', pTile->GetDisplayChar());
	pTile = maze.GetTile(1, 1);
	EXPECT_EQ('~', pTile->GetDisplayChar());
	pTile = maze.GetTile(2, 1);
	EXPECT_EQ('%', pTile->GetDisplayChar());

	pTile = maze.GetTile(0, 2);
	EXPECT_EQ('%', pTile->GetDisplayChar());
	pTile = maze.GetTile(1, 2);
	EXPECT_EQ('~', pTile->GetDisplayChar());
	pTile = maze.GetTile(2, 2);
	EXPECT_EQ('%', pTile->GetDisplayChar());
}

TEST(TestMazeObject, MazeSafelyHandlesIncorrectColumnParameter)
{
	std::vector<char> row1 = { '%','~','%' };
	std::vector<char> row2 = { '~','~','%' };
	std::vector<char> row3 = { '%','~','%' };
	std::vector<std::vector<char>> outline;
	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze maze(1, 3, outline);

	EXPECT_EQ(0, maze.GetRows());
	EXPECT_EQ(0, maze.GetColumns());
}

TEST(TestMazeObject, MazeSafelyHandlesIncorrectRowParameter)
{
	std::vector<char> row1 = { '%','~','%' };
	std::vector<char> row2 = { '~','~','%' };
	std::vector<char> row3 = { '%','~','%' };
	std::vector<std::vector<char>> outline;
	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze maze(3, 1, outline);

	EXPECT_EQ(0, maze.GetRows());
	EXPECT_EQ(0, maze.GetColumns());
}

TEST(TestMazeObject, MazeSafelyHandlesEmptyOutline)
{
	std::vector<std::vector<char>> outline;

	Maze maze(1, 3, outline);

	EXPECT_EQ(0, maze.GetRows());
	EXPECT_EQ(0, maze.GetColumns());
}

TEST(TestMazeObject, FindStartFindsCorrectlyAtOne_Zero)
{
	std::vector<char> row = { '%','~','%','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	EXPECT_EQ(0, maze.GetStartPoint()->GetRow());
	EXPECT_EQ(1, maze.GetStartPoint()->GetColumn());
	EXPECT_EQ('~', maze.GetStartPoint()->GetDisplayChar());
}

TEST(TestMazeObject, FindStartFindsCorrectlyAtThree_Zero)
{
	std::vector<char> row = { '%','%','%','~' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	EXPECT_EQ(0, maze.GetStartPoint()->GetRow());
	EXPECT_EQ(3, maze.GetStartPoint()->GetColumn());
	EXPECT_EQ('~', maze.GetStartPoint()->GetDisplayChar());
}

TEST(TestMazeObject, FindStartReturnsNull)
{
	std::vector<char> row = { '%','%','%','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	EXPECT_EQ(NULL, maze.GetStartPoint());
}
TEST(TestMazeObject, IsFinishPointTrueAtOne_Zero)
{
	std::vector<char> row = { '%','~','%','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	Tile* tile = maze.GetTile(1, 0);
	EXPECT_EQ(true, maze.IsFinishPoint(tile));
}

TEST(TestMazeObject, IsFinishPointTrueAtThree_Zero)
{
	std::vector<char> row = { '%','%','%','~' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	Tile* tile = maze.GetTile(3, 0);
	EXPECT_EQ(true, maze.IsFinishPoint(tile));
}

TEST(TestMazeObject, IsFinishPointTrueAtTwo_Two)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze maze(4, 3, outline);

	Tile* tile = maze.GetTile(2, 2);
	EXPECT_EQ(true, maze.IsFinishPoint(tile));
}

TEST(TestMazeObject, IsFinishPointFalseAtThree_Zero)
{
	std::vector<char> row = { '%','%','~','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	Tile* tile = maze.GetTile(3, 0);
	EXPECT_EQ(false, maze.IsFinishPoint(tile));
}

TEST(TestMazeObject, IsFinishPointReturnsFalseNoActualFinish)
{
	std::vector<char> row = { '%','%','%','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	Tile* tile = maze.GetTile(0, 0);
	EXPECT_EQ(false, maze.IsFinishPoint(tile));
	tile = maze.GetTile(1, 0);
	EXPECT_EQ(false, maze.IsFinishPoint(tile));
	tile = maze.GetTile(2, 0);
	EXPECT_EQ(false, maze.IsFinishPoint(tile));
	tile = maze.GetTile(3, 0);
	EXPECT_EQ(false, maze.IsFinishPoint(tile));
}

TEST(TestMazeObject, IsFinishPointReturnsFalseNullPointer)
{
	std::vector<char> row = { '%','%','~','%' };
	std::vector<std::vector<char>> outline(1, row);

	Maze maze(4, 1, outline);

	Tile* tile = NULL;
	EXPECT_EQ(false, maze.IsFinishPoint(tile));
}

/////////////////////////////////////////////////////////////////////////////////////
// MazeSolver ///////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

TEST(TestMazeSolverObject, ConstructorSetsCurrentTileAtOne_Zero)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);
	Tile* tile = maze->GetTile(1, 0);
	EXPECT_EQ('~', tile->GetDisplayChar());
	MazeSolver solver(maze, maze->GetStartPoint());
	tile = maze->GetTile(1, 0);
	EXPECT_EQ('@', tile->GetDisplayChar());
}

TEST(TestMazeSolverObject, ConstructorSetsCurrentTileAtThree_Zero)
{
	std::vector<char> row1 = { '%','%','%','~' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);
	Tile* tile = maze->GetTile(3, 0);
	EXPECT_EQ('~', tile->GetDisplayChar());
	MazeSolver solver(maze, maze->GetStartPoint());
	tile = maze->GetTile(3, 0);
	EXPECT_EQ('@', tile->GetDisplayChar());
}

TEST(TestMazeSolverObject, ConstructorDoesntTryToAccessNullTilePointer)
{
	std::vector<char> row1 = { '%','%','%','~' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);
	Tile* tile = NULL;
	EXPECT_NO_FATAL_FAILURE(MazeSolver solver(maze, maze->GetStartPoint()));
}

TEST(TestMazeSolverObject, ConstructorDoesntTryToAccessNullMazePointer)
{
	std::vector<char> row1 = { '%','%','%','~' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = NULL;
	Tile* tile = new Tile(0, 0, false);
	EXPECT_NO_FATAL_FAILURE(MazeSolver solver(maze, tile));
}


// GetOpenDistanceSouth /////////////////////////////////////////////////////////////
TEST(TestMazeSolverObject, GetOpenDistanceSouthEqualsOne)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(1, 0);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceSouth());
}


TEST(TestMazeSolverObject, GetOpenDistanceSouthEqualsZero)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(1, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceSouth());
}

TEST(TestMazeSolverObject, GetOpenDistanceSouthEqualsTwo)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 0);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(2, solver.GetOpenDistanceSouth());
}

TEST(TestMazeSolverObject, GetOpenDistanceSouthEqualsZeroOnBoundary)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(2, 0);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceSouth());
}

TEST(TestMazeSolverObject, GetOpenDistanceSouthEqualsZeroAtSouthEdge)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 3);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceSouth());
}

TEST(TestMazeSolverObject, GetOpenDistanceSouthEqualsOneAtOne_Zero_WithPathPiece)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 0);
	Tile* path = maze->GetTile(1, 2);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceSouth());
}

TEST(TestMazeSolverObject, GetOpenDistanceSouthEqualsZeroAtOne_One_WithPathPiece)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 1);
	Tile* path = maze->GetTile(1, 2);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceSouth());
}

// GetOpenDistanceNorth /////////////////////////////////////////////////////////////
TEST(TestMazeSolverObject, GetOpenDistanceNorthEqualsOne)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(1, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceNorth());
}

TEST(TestMazeSolverObject, GetOpenDistanceNorthEqualsZero)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(2, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceNorth());
}

TEST(TestMazeSolverObject, GetOpenDistanceNorthEqualsTwo)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 2);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(2, solver.GetOpenDistanceNorth());
}

TEST(TestMazeSolverObject, GetOpenDistanceNorthEqualsZeroOnBoundary)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 3);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceNorth());
}

TEST(TestMazeSolverObject, GetOpenDistanceNorthEqualsZeroAtNorthEdge)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 0);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceNorth());
}

TEST(TestMazeSolverObject, GetOpenDistanceNorthEqualsOneAtOne_Two_WithPathPiece)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 2);
	Tile* path = maze->GetTile(1, 0);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceNorth());
}

TEST(TestMazeSolverObject, GetOpenDistanceNorthEqualsZeroAtOne_One_WithPathPiece)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 1);
	Tile* path = maze->GetTile(1, 0);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceNorth());
}

// GetOpenDistanceEast /////////////////////////////////////////////////////////////

TEST(TestMazeSolverObject, GetOpenDistanceEastEqualsOne)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(1, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceEast());
}

TEST(TestMazeSolverObject, GetOpenDistanceEastEqualsZero)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(2, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceEast());
}

TEST(TestMazeSolverObject, GetOpenDistanceEastEqualsTwo)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(0, 2);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(2, solver.GetOpenDistanceEast());
}

TEST(TestMazeSolverObject, GetOpenDistanceEastEqualsZeroOnBoundary)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(0, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceEast());
}

TEST(TestMazeSolverObject, GetOpenDistanceEastEqualsZeroAtEastEdge)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','~' };
	std::vector<char> row3 = { '%','~','~','~' };
	std::vector<char> row4 = { '%','%','%','~' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(3, 2);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceEast());
}

TEST(TestMazeSolverObject, GetOpenDistanceEastEqualsOneAtZero_Two_WithPathPiece)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(0, 2);
	Tile* path = maze->GetTile(2, 2);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceEast());
}

TEST(TestMazeSolverObject, GetOpenDistanceEastEqualsOneAtOne_Two_WithPathPiece)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 2);
	Tile* path = maze->GetTile(2, 2);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceEast());
}


// GetOpenDistanceWest /////////////////////////////////////////////////////////////

TEST(TestMazeSolverObject, GetOpenDistanceWestEqualsOne)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(2, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceWest());
}

TEST(TestMazeSolverObject, GetOpenDistanceWestEqualsZero)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);

	Maze* maze = new Maze(4, 3, outline);

	Tile* tile = maze->GetTile(1, 1);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceWest());
}

TEST(TestMazeSolverObject, GetOpenDistanceWestEqualsTwo)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(2, 2);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(2, solver.GetOpenDistanceWest());
}

TEST(TestMazeSolverObject, GetOpenDistanceWestEqualsZeroOnBoundary)
{
	std::vector<char> row1 = { '%','~','%','%' };
	std::vector<char> row2 = { '%','~','~','%' };
	std::vector<char> row3 = { '%','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(3, 2);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceWest());
}

TEST(TestMazeSolverObject, GetOpenDistanceWestEqualsZeroAtWestEdge)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(0, 2);
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceWest());
}

TEST(TestMazeSolverObject, GetOpenDistanceWestEqualsOneAtTwo_Two_WithPathPiece)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(2, 2);
	Tile* path = maze->GetTile(0, 2);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(1, solver.GetOpenDistanceWest());
}

TEST(TestMazeSolverObject, GetOpenDistanceWestEqualsOneAtOne_Two_WithPathPiece)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);

	Tile* tile = maze->GetTile(1, 2);
	Tile* path = maze->GetTile(0, 2);
	path->SetDisplayChar('#');
	MazeSolver solver(maze, tile);
	EXPECT_EQ(0, solver.GetOpenDistanceWest());
}

TEST(TestMazeSolverObject, GetHasSolveMazeIsFalse)
{
	std::vector<char> row1 = { '~','%','%','%' };
	std::vector<char> row2 = { '~','~','~','%' };
	std::vector<char> row3 = { '~','~','~','%' };
	std::vector<char> row4 = { '%','%','~','%' };
	std::vector<std::vector<char>> outline;

	outline.push_back(row1);
	outline.push_back(row2);
	outline.push_back(row3);
	outline.push_back(row4);

	Maze* maze = new Maze(4, 4, outline);
	MazeSolver solver(maze, maze->GetStartPoint());
	EXPECT_EQ(false, solver.GetHasSolvedMaze());
}

TEST(TestMazeSolverObject, GetHasSolveMazeIsTrue)
{
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

	EXPECT_EQ(true, solver.GetHasSolvedMaze());
}
