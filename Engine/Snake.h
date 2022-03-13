#pragma once
#include "Board.h"
#include "Location.h"

class Snake
{
private:

	class Segment {
	public:
		void InitHead(const Location& loc_in);
		void InitBody(int count);
		void Follow(const Segment& next);
		void MoveBy(const Location& loc_delta);
		const Location& GetLocation()const; 
		 
		
		

		void Draw (Board& brd) const;
	private: 
		
		Location loc; 
		Color c; 
		int growCounter = 0;
	};


public: 
	Snake(const Location& in_loc); 
	Location GetHeadLocation() const;
	Location GetNextHeadLocation(const Location& loc_in) const; 
	void MoveBy(const Location& delta_loc); 
	void Grow(); 
	void Follow(); 
	void Draw(Board& brd) const;
	bool IsInTile(const Location& Target) const;
	


private: 
	
	static constexpr int segmentMax = 100; 
	Segment segments[segmentMax];
	int nsegments = 1; 
	static constexpr Color SnakeHead= Colors::Yellow;
	static constexpr Color SnakeBody = Colors::Green;
	int growCounter = 0;
	
};

