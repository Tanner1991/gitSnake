#pragma once
#include "Keyboard.h"
#include "Mouse.h"
class Rec {
public:
	void DrawRectangle();
	void EdgeGuard();
	void UpdateRec(Keyboard& kbd, Mouse& mouse);

		int x = 50;
		int y = 50; 
		int length = 400; 
		int width = 300; 
		int red = 255; 
		int green = 255; 
		int blue = 255;
private:

};