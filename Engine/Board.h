#pragma once
#include "Graphics.h"
#include "Rectangle.h"
#include "Location.h"

class Board
{
public:
	 Board(Graphics& gfx); 
	 int GetDiemension(); 
	 int GetWidth();
	 int GetHeight(); 
	 int GetoffsetX();
	 int GetoffsetY(); 
	 void DrawCell( const Location &in_loc, Color c); 
	 bool IsInsideBoard(const Location& loc_in) const; 
	 void DrawEdge(); 
private: 
	static constexpr int diemension = 20; 
	static constexpr int width = 25;
	static constexpr int height = 25; 
	Graphics& gfx; 
	Color border = Colors::Blue; 
	int offsetX = 7;
	int offsetY = 2; 

};

