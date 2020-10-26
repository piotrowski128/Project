#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "metody.cpp"
#include "klasy.h"

using namespace std; using namespace sf;
int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Manage!");
	RectangleShape shape1(Vector2f(1920.f,1080.f));
	RectangleShape shape2(Vector2f(192.f, 108.f));
	RectangleShape shape3(Vector2f(192.f, 108.f));

	shape2.setFillColor(Color::Blue);
	shape3.setFillColor(Color::Red);
	while (window.isOpen())
	{	Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.draw(shape3);
		shape2.setPosition(100.f, 180.f);
		shape3.setPosition(800.f, 900.f);
		window.display();







		
	}

	return 0;
}