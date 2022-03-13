#include "Board.h"


Board::Board(Graphics& gfx)
	:
	gfx (gfx)
{}

int Board::GetDiemension()
{
	return diemension;
}

int Board::GetWidth()
{
	return width;
}

int Board::GetHeight()
{
	return height;
}

int Board::GetoffsetX()
{
	return offsetX;
}

int Board::GetoffsetY()
{
	return offsetY;
}


void Board::DrawCell(const Location& in_loc, Color c)
{
	gfx.DrawRecDim(in_loc.x * diemension, in_loc.y * diemension, diemension, diemension, c);
}

bool Board::IsInsideBoard(const Location& loc_in) const
{
	return loc_in.x >= offsetX  && loc_in.x < offsetX + width && loc_in.y >= offsetY && loc_in.y < height+offsetY; 
}

void Board::DrawEdge()
{
	gfx.DrawBorder(offsetX *diemension, offsetY * diemension, width * diemension, height* diemension, border);
}
