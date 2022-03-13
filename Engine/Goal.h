#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>
#include "Graphics.h"
#include "Location.h"
#include <cmath>





class Goal
{
public: 
	void Spawn(Board& vrd, Snake& snake);
	void Draw(Board& brd);
	const Location GetLocation (); 
	bool isInTile(Location& Target); 
	void FirstSpawn(Board& vrd, Snake& snake);

	Color c = Colors::Red; 
private:
	
	int x; 
	int y; 
	Location loc; 



};

