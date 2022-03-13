#include "Snake.h"
#include "Board.h"
#include "Location.h"

Snake::Snake(const Location& in_loc)
	
{
	segments[0].InitHead(in_loc); 
}

Location Snake::GetHeadLocation() const
{
	return segments[0].GetLocation();
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation()); 
	l.Add(delta_loc); 
	return l; 
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nsegments-1; i > 0; --i) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc); 
}

void Snake::Grow()
{

	if (nsegments < segmentMax) {
		segments[nsegments].InitBody(growCounter);
		nsegments++; 
	}
	growCounter++; 
}

void Snake::Draw(Board& brd) const
{ 
	for (int i = 0; i < nsegments; i++) {
		segments[i].Draw(brd); 
	}
}

bool Snake::IsInTile(const Location& Target) const
{
	for (int i = 0; i < nsegments-1; i++) {
		if (segments[i].GetLocation() == Target) {
			return true; 
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location& loc_in)
{
	loc = loc_in; 
	c = Snake::SnakeHead; 
}

void Snake::Segment::InitBody(int count)
{
	if (count % 2 == 0) {
		c = Colors::MakeRGB(0, 255, 0); 
}
	else {
		c = Colors::MakeRGB(0, 100, 0);
	}
	
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc; 
}

void Snake::Segment::MoveBy(const Location& loc_delta)
{
	loc.Add(loc_delta); 
}

const Location& Snake::Segment::GetLocation() const
{
	return loc; 
}







void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c); 
}
