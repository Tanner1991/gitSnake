#include "Obstacle.h"


std::random_device re;
std::mt19937 rngg(re());

void Obstacle::Spawn(Board& brd, Snake& snake, Goal& goal)

{

	int c = brd.GetoffsetX() + brd.GetWidth()-1;
	int d = brd.GetoffsetY() + brd.GetHeight()-1;


	
	 
	do {

		std::uniform_int_distribution<int> spawnX(brd.GetoffsetX(), c);
		std::uniform_int_distribution<int> spawnY(brd.GetoffsetY(), d);

		x = spawnX(rngg);
		y = spawnY(rngg);

		loc = { x,y };

	} while (snake.IsInTile(loc) || goal.isInTile(loc)); 
	

	
	

}

void Obstacle::Draw(Board& brd)
{
	brd.DrawCell(loc, c);
}

const Location Obstacle::GetLocation()
{
	return loc;
}

bool Obstacle::isInTile(Location& Target)
{
	if (loc == Target) {
		return true;
	}

	else {

		return false;
	}
}




