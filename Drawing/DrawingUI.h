#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape Canvas;
	vector<DrawingShape*> Shapes;
public:
	DrawingUI(Vector2f p)
	{

	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		Vector2f sqPos(300, 0);
		Canvas.setPosition(sqPos);
		Canvas.setOutlineColor(Color::White);
		Canvas.setOutlineThickness(2);
		Canvas.setSize(Vector2f(600, 600));
		Canvas.setFillColor(Color::Transparent);

		// renders a RectangleShape
		win.draw(Canvas);
		
		
		

		//THIS IS WHERE I'M TRYING TO GET THE POINTER TO THE SHAPES FROM SHAPE MANAGER

		Shapes = mgr->GetShapeList();
	
		for (int x = 0; x < Shapes.size(); x++)
		{
			Shapes[x]->Draw(win);
		}
		

		

	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{

		if (Canvas.getGlobalBounds().contains(mousePos))
		{
			return true;
		}

		else
		{
			return false; // just to make it compile
		}
	}



};

