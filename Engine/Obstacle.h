#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>
#include "Graphics.h"
#include "Location.h"
#include <cmath>
#include "Goal.h"






class Obstacle
{
public:
	void Spawn(Board& brd, Snake& snake, Goal& goal);
	void Draw(Board& brd);
	const Location GetLocation();
	bool isInTile(Location& Target);
	Color c = Colors::Gray;
	static constexpr int segmentMax = 100;
	int x;
	int y;
private:

	Location loc;
	
	



};

