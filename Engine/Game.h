/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Rectangle.h"
#include "Board.h"
#include "Snake.h"
#include "Location.h"
#include "Goal.h"
#include "Obstacle.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawRectangle(int length, int width, int x, int y, int red, int green, int blue); 
	bool isCollideObs();
	bool isCollideObs2(const Snake& snake); 
	bool isCollideObs3(Goal& goal); 
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables  */
	Obstacle obs[Obstacle::segmentMax]; 
	int snakeSlow = 0; 
	Rec rec0;
	Goal goal0;
	bool goalHit = false; 
	Board brd; 
	Snake snake; 
	Location delta_loc = { 1,0 };
	int speed = 0; 
	int speedCount = 0; 
	bool gameOver = false; 
	bool startGame = false; 
	int obsSegments = 0; 
	/********************************/
};