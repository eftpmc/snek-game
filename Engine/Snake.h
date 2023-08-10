#pragma once
#include "Board.h"

class Snake
{
public:
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(Color newColor);
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	Color getBodyColor();
	void Grow();
	void Draw(Board& brd) const;
	bool IsInTile(const Location& target) const;
	bool IsInTileExceptEnd(const Location& target) const;
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr int patternCount = 3;
	int currentPattern = 0;
	static constexpr Color bodyColors[patternCount] = {Colors::Blue, Colors::Cyan, Colors::Magenta};
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};