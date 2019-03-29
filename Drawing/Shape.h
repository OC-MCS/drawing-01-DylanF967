#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

struct ShapeLoadData
{
	Vector2f Position;
	Color color;
	ShapeEnum WhichShape;
};
// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
	private:
		

	public:
	virtual void Draw(RenderWindow &win) = 0;
	virtual ShapeLoadData GetData() = 0;
		

};

// add Circle, Square classes below. These are derived from DrawingShape


class Circle : public DrawingShape
{
	private:
		CircleShape Shape;
		
		
	public:

		Circle(Vector2f pos, Color color)
		{
			Shape.setPosition(pos);
			Shape.setRadius(5);
			Shape.setOutlineColor(color);
			Shape.setOutlineThickness(2);
			Shape.setFillColor(color);
		}

		void Draw(RenderWindow &win)
		{

			win.draw(Shape);
		}
	
		struct ShapeLoadData GetData()
		{
			ShapeLoadData Data;
			Data.Position = Shape.getPosition();
			Data.color = Shape.getFillColor();
			Data.WhichShape;
			return Data;
		}
		
};


class Square : public DrawingShape
{
	private:
		RectangleShape Shape;

	public:
		Square(Vector2f pos, Color color)
		{
			Shape.setPosition(pos);
			Shape.setSize(Vector2f(5,5));
			Shape.setOutlineColor(color);
			Shape.setOutlineThickness(2);
			Shape.setFillColor(color);

		}

		void Draw(RenderWindow &win)
		{
			win.draw(Shape);
		}

		struct ShapeLoadData GetData()
		{
			ShapeLoadData Data;
			Data.Position = Shape.getPosition();
			Data.color = Shape.getFillColor();
			Data.WhichShape;
			return Data;
		}

};