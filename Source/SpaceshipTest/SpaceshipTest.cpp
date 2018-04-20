#include "Input.h"
#include "Spaceship.h"
#include "DrawableManager.h"

int main()
{
	ResourceManager *rm = new ResourceManager();
	int counterImageSequence = 0;

	ImageSequenceResource* spaceshipImgseq = rm->GetResource<ImageSequenceResource>("spaceshipNormal");
	ImageSequenceResource* bulletImgseq = rm->GetResource<ImageSequenceResource>("fire");

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML works!");
	window.clear();
	sf::Sprite* spaceshipSprite = new sf::Sprite();
	sf::Sprite* bulletLeft = new sf::Sprite();
	sf::Sprite* bulletRight = new sf::Sprite();

	InputManager* input = new InputManager();
	
	Spaceship* spaceship = new Spaceship(sf::Vector2f(200.0f, 200.0f), sf::Vector2f(0.0f, 1.0f), *input, *spaceshipImgseq, *bulletImgseq, *bulletImgseq);

	sf::Clock clock;
	sf::Time timer = clock.getElapsedTime();
	sf::Time deltaTime;

	float currentAngle = 0.0f;

	DrawableManager& drawableManager = DrawableManager::getInstance();

	while (window.isOpen())
	{
		auto now = clock.getElapsedTime();
		deltaTime = now - timer;
		timer = now;

		//bulletRightAnimationPlayer->Update(deltaTime);

		spaceship->Update(deltaTime);

		window.clear();
		drawableManager.DrawScene(window);

		
		//window.draw(*spaceshipSprite);
		//window.draw(*bulletRight);
		window.display();
	}


	return 0;
}