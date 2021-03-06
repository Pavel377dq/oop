// shapeclass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "shape.h"


int main()
{
	Shape figure(5,5);
	Ellipse ellipse(5, 5, 3, 2, 4);
	Trap trap(5, 7, 5, 4, 7, 3);
	Shape* shapes[3] = { &figure, &ellipse, &trap };

	for (auto& p : shapes)
	{
		p->print(std::cout);

		std::cout << "New info" << std::endl << '\n';

		p->setCenter(3, 1);
		p->setAngle(65);
		p->setColour(255, 210, 255);
		p->setScale(3.4);

		std::cout << *p;

		std::cout << "Delete info" << std::endl << '\n';

		p->shape_clear();
		std::cout << *p;

		std::cout << "Next object ..." << std::endl << '\n';
	}
	system("pause");
    return 0;
}

