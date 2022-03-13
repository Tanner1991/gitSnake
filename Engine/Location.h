#pragma once
struct Location
{
	void Add(const Location& val);
	int x;
	int y;
	bool operator == (const Location& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	/*bool operator != (const Location& rhs) const {
		return x!= rhs.x && y != rhs.y;
	}*/

}; 


