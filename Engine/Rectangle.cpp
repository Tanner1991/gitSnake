#include "Rectangle.h"
#include "Graphics.h"

void Rec::DrawRectangle()

{
	;

}

void Rec::EdgeGuard()
{
	
	

	if (y <= 0 ) {
		y = 0;
	}
	

	else if (y + length >= Graphics::ScreenHeight && length < Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - length - 1;


	}

	else if(length >= Graphics::ScreenHeight){
		y = 0; 
		length = Graphics::ScreenHeight - 1; 

	}

	if (x <= 0 && !(width >= Graphics::ScreenWidth)) {
		x = 0;
	}

	else if (x + width >= Graphics::ScreenWidth && width < Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth - width - 1;


	}

	else if (width >= Graphics::ScreenWidth) {
		x = 0;
		width = Graphics::ScreenWidth - 1;

	}

}

void Rec::UpdateRec(Keyboard& kbd, Mouse&mouse)
{
	//change shape6

	
	
	if (kbd.KeyIsPressed(VK_RIGHT)) {
		width += 1;
	}
	if (kbd.KeyIsPressed(VK_LEFT)) {
		width -= 1;
	}

	if (kbd.KeyIsPressed(VK_DOWN)) {
		length += 1;
	}
	if (kbd.KeyIsPressed(VK_UP)) {
		length -= 1;
	}



	//move shape 
	if (kbd.KeyIsPressed('D')) {
		x += 1;
		width += 1; 
	}
	if (kbd.KeyIsPressed('A')) {
		x -= 1;
		width -= 1;
	}  

	if (kbd.KeyIsPressed('S')) {
		y += 1;
		length += 1;
	}
	if (kbd.KeyIsPressed('W')) {
		y -= 1;
		length -= 1;
	}

	if (mouse.LeftIsPressed()) {
		width = mouse.GetPosX();
		length = mouse.GetPosY();
	}
	
}
