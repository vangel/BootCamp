#include "Asteroid.h"
#include "ResourceManager.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

int main()
{
	srand(time(0));

	sf::Rect<int> border;
	border.top = 0;
	border.left = 0;
	border.width = WINDOW_WIDTH;
	border.height = WINDOW_HEIGHT;

	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	PictureResource* asteroid = rm->GetResource<PictureResource>("asteroid");
	sf::Image image(*asteroid->Get());
	image.createMaskFromColor(sf::Color(0, 35, 57, 255), 0);

	sf::Sprite sprite;
	sf::Texture asteroidTexture;
	asteroidTexture.loadFromImage(image, sf::IntRect(300,90,85,85));
	sprite.setTexture(asteroidTexture);

	std::vector<Asteroid *> asteroids;
	Asteroid *asteroid1 = new Asteroid(sprite, border, 1);
	Asteroid *asteroid2 = new Asteroid(sprite, border, 2);
	Asteroid *asteroid3 = new Asteroid(sprite, border, 3);
	Asteroid *asteroid4 = new Asteroid(sprite, border, 4);
	Asteroid *asteroid5 = new Asteroid(sprite, border, 5);
	Asteroid *asteroid6 = new Asteroid(sprite, border, 6);

	asteroids.push_back(asteroid1);
	asteroids.push_back(asteroid2);
	asteroids.push_back(asteroid3);
	asteroids.push_back(asteroid4);
	asteroids.push_back(asteroid5);
	asteroids.push_back(asteroid6);

	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Asteroid!");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
				window.close();
			}
		}

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		window.clear();
		for (Asteroid *asteroid : asteroids) {
			asteroid->Update(time);
			window.draw(asteroid->GetSprite());
		}

		window.display();
	}

	return 0;
}