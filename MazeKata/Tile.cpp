#include "Tile.h"

Tile::Tile()
{
	this->column = 0;
	this->row = 0;
	this->isBoundary = true;
	this->displayChar = '%';
}

Tile::Tile(int column, int row, bool isBoundary)
{
	this->column = column;
	this->row = row;
	this->isBoundary = isBoundary;
	this->displayChar = (this->isBoundary) ? '%' : '~';
}

int Tile::GetColumn()
{
	return this->column;
}

int Tile::GetRow()
{
	return this->row;
}

char Tile::GetDisplayChar()
{
	return this->displayChar;
}

bool Tile::IsBoundary()
{
	return this->isBoundary;
}

bool Tile::SetDisplayChar(char c)
{
	if (this->isBoundary)
	{
		return false;
	}
	else // Able to set non boundary char
	{
		this->displayChar = c;
		return true;
	}
}