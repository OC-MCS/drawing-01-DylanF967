#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:

	ShapeEnum ShapeEnumValue;
	Color CurrColor;
	
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{

	}

	Color getCurColor()
	{
		return CurrColor; // just to make it compile 
	}


	ShapeEnum getCurShape()
	{
		return ShapeEnumValue; // just to make it compile;
	}

	void SetCurShape(ShapeEnum Shape)
	{
	
			ShapeEnumValue = Shape;
		
	}

	void SetCurColor(Color color)
	{
		CurrColor = color;
	}

	void Save(fstream & Savefile)
	{
		


		Savefile.write((char*)&CurrColor, sizeof(CurrColor));
		Savefile.write((char*)&ShapeEnumValue, sizeof(ShapeEnumValue));


	}
};

