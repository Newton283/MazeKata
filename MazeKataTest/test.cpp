#include "pch.h"
#include "../MazeKata/Tile.cpp"
#include "../MazeKata/Maze.cpp"

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

TEST(TestMazeObject, TwoDimensionalMazeInitializesCorrectly)
{
	std::vector<char> row1 = { '%','~','%'};
	std::vector<char> row2 = { '~','~','%'};
	std::vector<char> row3 = { '%','~','%'};
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