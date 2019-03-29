#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> Shapes;
	struct SaveData 
	{
		Vector2f Position;
		Color color;
		enum ShapeEnum { CIRCLE, SQUARE };
	};
public:
	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			Circle *CirShape = new Circle(pos, color);
		
			
			Shapes.push_back(CirShape);
			cout << "We have pushed back a circle." << endl;
			
			
			
		}

		else
		{
			Square *SqrShape = new Square(pos, color);
			Shapes.push_back(SqrShape);
			cout << "We have pushed back a square." << endl;
			
		
		}

		
	}

	vector<DrawingShape*> SetShapeList()
	{

	}
	
	vector<DrawingShape*> GetShapeList()
	{
		return Shapes ;
	}

	void Save(fstream & Savefile)
	{
		ShapeLoadData Data;
		
		
		for (int count = 0; count < Shapes.size(); count++)
		{
			Data = Shapes[count]->GetData();
			Savefile.write((char*)&Data.Position, sizeof(Data.Position));
			Savefile.write((char*)&Data.WhichShape, sizeof(Data.WhichShape));
			Savefile.write((char*)&Data.color, sizeof(Data.color));
			
		}
		

	}
};
