#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"



// finish this code; add functions, data as needed

class SettingsUI
{
private:
	CircleShape CirBtn;
	CircleShape RedBtn;
	CircleShape BlueBtn;
	CircleShape GreenBtn;
	RectangleShape squareBtn;
	bool Sqselected = false;
	bool RedSelected = false;
	bool GreenSelected = false;
public:
	SettingsUI(SettingsMgr *mgr)
	{

	}
	void handleMouseUp(Vector2f mouse, SettingsMgr *mgr)
	{
		ShapeEnum Value;
		Color CurrColor;
		if (CirBtn.getGlobalBounds().contains(mouse)) // mouse is a vector2f
	// mouse is currently over CircleBtn
		{
			Sqselected = false;
			Value = ShapeEnum :: CIRCLE;
			mgr->SetCurShape(Value);
			cout << "Circle Selected" << endl;

		}

		else if (squareBtn.getGlobalBounds().contains(mouse)) // mouse is a vector2f
	// mouse is currently over SquareBtn
		{
			Sqselected = true;
			Value = ShapeEnum::SQUARE;
			mgr->SetCurShape(Value);
			cout << "Square Selected." << endl;
		}

		else if (RedBtn.getGlobalBounds().contains(mouse)) // mouse is a vector2f
	// mouse is currently over SquareBtn
		{
			RedSelected = true;
			GreenSelected = false;
			CurrColor = Color::Red;
			mgr->SetCurColor(CurrColor);
			cout << "Red Selected." << endl;
		}

		else if (GreenBtn.getGlobalBounds().contains(mouse)) // mouse is a vector2f
	// mouse is currently over SquareBtn
		{
			GreenSelected = true;
			RedSelected = false;
			CurrColor = Color::Green;
			mgr->SetCurColor(CurrColor);
			cout << "Green Selected." << endl;
		}
		else if (BlueBtn.getGlobalBounds().contains(mouse)) // mouse is a vector2f
	// mouse is currently over SquareBtn
		{
			RedSelected = false;
			GreenSelected = false;
			CurrColor = Color::Blue;
			mgr->SetCurColor(CurrColor);
			cout << "Blue Selected." << endl;
		}
	}

	void draw(RenderWindow& win)
	{
		
		
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// title
		Text title("Drawing Shape", font, 25);
		title.setPosition(30, 25);
		win.draw(title);

		Text Color("Drawing Color", font, 25);
		Color.setPosition(30, 225);
		win.draw(Color);

		if (Sqselected == true)
		{
			
			Vector2f pos(50, 60);
			CirBtn.setPosition(pos);
			CirBtn.setRadius(20);
			CirBtn.setOutlineThickness(2);
			CirBtn.setOutlineColor(Color::White);
			// for just an outlined button
			CirBtn.setFillColor(Color::Transparent);

			// The following renders the circle on the screen
			// win is a RenderWindow (see provided code)
			win.draw(CirBtn);

			// RectangleShape is Graphics lib class
			Vector2f sqPos(150, 60);
			squareBtn.setPosition(sqPos);
			squareBtn.setOutlineColor(Color::White);
			squareBtn.setOutlineThickness(2);
			squareBtn.setSize(Vector2f(40, 40));
			squareBtn.setFillColor(Color::White);

			// renders a RectangleShape
			win.draw(squareBtn);
		}

		else
		{
				
			Vector2f pos(50, 60);
			CirBtn.setPosition(pos);
			CirBtn.setRadius(20);
			CirBtn.setOutlineThickness(2);
			CirBtn.setOutlineColor(Color::White);
			// for just an outlined button
			CirBtn.setFillColor(Color::White);

			// The following renders the circle on the screen
			// win is a RenderWindow (see provided code)
			win.draw(CirBtn);

			
			Vector2f sqPos(150, 60);
			squareBtn.setPosition(sqPos);
			squareBtn.setOutlineColor(Color::White);
			squareBtn.setOutlineThickness(2);
			squareBtn.setSize(Vector2f(40, 40));
			squareBtn.setFillColor(Color::Transparent);

			// renders a RectangleShape
			win.draw(squareBtn);
		}

		if (RedSelected == true)
		{
			GreenSelected = false;
			Vector2f Redpos(50, 260);
			RedBtn.setPosition(Redpos);
			RedBtn.setRadius(20);
			RedBtn.setOutlineThickness(2);
			RedBtn.setOutlineColor(Color::Red);
			// for just an outlined button
			RedBtn.setFillColor(Color::Red);

			// The following renders the circle on the screen
			// win is a RenderWindow (see provided code)
			win.draw(RedBtn);

			Vector2f Greenpos(50, 360);
			GreenBtn.setPosition(Greenpos);
			GreenBtn.setRadius(20);
			GreenBtn.setOutlineThickness(2);
			GreenBtn.setOutlineColor(Color::Green);
			// for just an outlined button
			GreenBtn.setFillColor(Color::Transparent);

			// The following renders the circle on the screen
			// win is a RenderWindow (see provided code)
			win.draw(GreenBtn);

			Vector2f Bluepos(50, 460);
			BlueBtn.setPosition(Bluepos);
			BlueBtn.setRadius(20);
			BlueBtn.setOutlineThickness(2);
			BlueBtn.setOutlineColor(Color::Blue);
			// for just an outlined button
			BlueBtn.setFillColor(Color::Transparent);

			// The following renders the circle on the screen
			// win is a RenderWindow (see provided code)
			win.draw(BlueBtn);
		}
		else if (GreenSelected == true)
		{
			
				RedSelected = false;
				Vector2f pos(50, 360);
				GreenBtn.setPosition(pos);
				GreenBtn.setRadius(20);
				GreenBtn.setOutlineThickness(2);
				GreenBtn.setOutlineColor(Color::Green);
				// for just an outlined button
				GreenBtn.setFillColor(Color::Green);

				// The following renders the circle on the screen
				// win is a RenderWindow (see provided code)
				win.draw(GreenBtn);

				Vector2f Redpos(50, 260);
				RedBtn.setPosition(Redpos);
				RedBtn.setRadius(20);
				RedBtn.setOutlineThickness(2);
				RedBtn.setOutlineColor(Color::Red);
				// for just an outlined button
				RedBtn.setFillColor(Color::Transparent);
				win.draw(RedBtn);

				Vector2f Bluepos(50, 460);
				BlueBtn.setPosition(Bluepos);
				BlueBtn.setRadius(20);
				BlueBtn.setOutlineThickness(2);
				BlueBtn.setOutlineColor(Color::Blue);
				// for just an outlined button
				BlueBtn.setFillColor(Color::Transparent);

				// The following renders the circle on the screen
				// win is a RenderWindow (see provided code)
				win.draw(BlueBtn);
		}

		else
		{
			
			Vector2f pos(50, 360);
			GreenBtn.setPosition(pos);
			GreenBtn.setRadius(20);
			GreenBtn.setOutlineThickness(2);
			GreenBtn.setOutlineColor(Color::Green);
			// for just an outlined button
			GreenBtn.setFillColor(Color::Transparent);

			// The following renders the circle on the screen
			// win is a RenderWindow (see provided code)
			win.draw(GreenBtn);

			Vector2f Redpos(50, 260);
			RedBtn.setPosition(Redpos);
			RedBtn.setRadius(20);
			RedBtn.setOutlineThickness(2);
			RedBtn.setOutlineColor(Color::Red);
			// for just an outlined button
			RedBtn.setFillColor(Color::Transparent);
			win.draw(RedBtn);

			Vector2f Bluepos(50, 460);
			BlueBtn.setPosition(Bluepos);
			BlueBtn.setRadius(20);
			BlueBtn.setOutlineThickness(2);
			BlueBtn.setOutlineColor(Color::Blue);
			// for just an outlined button
			BlueBtn.setFillColor(Color::Blue);

			// The following renders the circle on the screen
			// win is a RenderWindow (see provided code)
			win.draw(BlueBtn);
		}
	}

	
	

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

};
