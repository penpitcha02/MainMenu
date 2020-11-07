#include <SFML/Graphics.hpp>
#include "MainMenu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Main Menu");

	MainMenu mainmenu(1080, 720);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainmenu.moveUp();
					break;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainmenu.moveDown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					int x = mainmenu.mainMenuPressed();
					if (x == 0)
						printf("PLAY Button was pressed\n");
					if (x == 1)
						printf("SCORE Button was pressed\n");
					if (x == 2)
						printf("QUIT Button was pressed\n");
				}
				
			}
		}
		window.clear();
		mainmenu.Draw(window);
		window.display();
	}
	return 0;
}
