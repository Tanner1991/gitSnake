/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include "board.h"
#include "Snake.h"
#include"SpriteCodex.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snake ({brd.GetoffsetX() +2 , brd.GetoffsetY() +2})



{
	goal0.FirstSpawn(brd, snake); 

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		startGame = true; 
}
	if (startGame) {

		if (!gameOver) {

			if (wnd.kbd.KeyIsPressed(VK_UP) && delta_loc.y != 1) {
				delta_loc = { 0, -1};
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN) && delta_loc.y != -1) {

				delta_loc = { 0, 1 };

			}

			if (wnd.kbd.KeyIsPressed(VK_LEFT) && delta_loc.x != 1) {
				delta_loc = { -1, 0 };

			}

			if (wnd.kbd.KeyIsPressed(VK_RIGHT) && delta_loc.x != -1) {
				delta_loc = { 1, 0 };

			}

			if (snakeSlow >= 20 - speed) {
				Location next = snake.GetNextHeadLocation(delta_loc);

				

				if (!brd.IsInsideBoard(next) || snake.IsInTile(next) ) {
					gameOver = true;
				}
				if (snake.GetHeadLocation() == goal0.GetLocation() ) {

					goalHit = true;
					snake.Grow();
					speedCount++; 

					if (speedCount % 2 == 0) {

						if (20 - speed > 3) {
							speed++;
						}

						do {
							obs[obsSegments].Spawn(brd, snake, goal0); 
						}

						while (isCollideObs());
						obsSegments++; 
					}


				}

				if (isCollideObs2(snake) ) {
					gameOver = true;
				}

				if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
					snake.Grow();
				}
				snake.MoveBy(delta_loc);
				snakeSlow = 0;
			}
			snakeSlow++;

			if (goalHit) {

				do {
					goal0.Spawn(brd, snake);
				} while (isCollideObs());
				goalHit = false;
			}

			


		} //end of gameOver
	}//end of start Game 
}



void Game::ComposeFrame()
{
	if (startGame) {
		brd.DrawEdge(); 

		

		snake.Draw(brd);
		
		
		for (int i = 0; i <= obsSegments-1; i++) {
				obs[i].Draw(brd);
			}

		goal0.Draw(brd);
		
		if (gameOver) {

			SpriteCodex::DrawGameOver(200, 200, gfx);

		}

	}

	else {
		SpriteCodex::DrawTitle(200, 200, gfx); 
	}
	
	} 

	


bool Game::isCollideObs()
{
	bool temp = false;

	for (int i = 0; i < obsSegments; i++) {

		if (obsSegments == 1) {
			return temp; 
		}

		if ((obs[obsSegments].x == obs[i].x) && (obs[obsSegments].y == obs[i].y)) {
			return true; 
		}
		
		
	}
	return temp;
}

bool Game::isCollideObs2(const Snake& snake)
{
	bool temp = false;
	Location temp2 = snake.GetHeadLocation(); 
	

	for (int i = 0; i < obsSegments; i++) {


		if ((obs[i].x == temp2.x) && (obs[i].y == temp2.y)) {
			return true;
		}


	}
	return temp;
}
		
	




		



