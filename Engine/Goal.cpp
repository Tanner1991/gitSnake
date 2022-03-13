#include "Goal.h"

std::random_device rd;
std::mt19937 rng(rd());





void Goal::Spawn(Board& brd, Snake& snake)

{
	//int a = std::abs(brd.GetoffsetX() - brd.GetWidth() ); 
	//int b = std::abs(brd.GetoffsetY() - brd.GetHeight() ); 
	int c = brd.GetoffsetX() + brd.GetWidth() - 1; 
	int d = brd.GetoffsetY() + brd.GetHeight() - 1; 
		

	std::uniform_int_distribution<int> spawnX(brd.GetoffsetX(), c) ;
	std::uniform_int_distribution<int> spawnY(brd.GetoffsetY(), d);

	do {


		x = spawnX(rng);
		y = spawnY(rng);

		loc = { x,y };

	} while (snake.IsInTile(loc) );

	

}

void Goal::Draw(Board& brd)
{
	brd.DrawCell(loc, c); 
}

const Location Goal::GetLocation()
{
	return loc;
}

bool Goal::isInTile(Location& Target) 
{
	if (loc == Target) {
			return true;
		}

	else {

		return false;
	}
}

void Goal::FirstSpawn(Board& brd, Snake& snake)
{
	int c = brd.GetoffsetX() + brd.GetWidth() - 1;
	int d = brd.GetoffsetY() + brd.GetHeight() - 1;


	std::uniform_int_distribution<int> spawnX(brd.GetoffsetX(), c);
	std::uniform_int_distribution<int> spawnY(brd.GetoffsetY(), d);

	do {


		x = spawnX(rng);
		y = spawnY(rng);

		loc = { x,y };

	} while (snake.IsInTile(loc));

	Draw(brd);
}


	
