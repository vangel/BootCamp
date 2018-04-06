#include "InputManager.h"
#include <iostream>

std::map<int, int > init() {

	std::map<int, int> customActions = {
		{ static_cast<int>(GameActions::Up) , static_cast<int>(sf::Keyboard::Up)},
		{ static_cast<int>(GameActions::Down), static_cast<int>(sf::Keyboard::Down)},
		{ static_cast<int>(GameActions::Left), static_cast<int>(sf::Keyboard::Left)},
		{ static_cast<int>(GameActions::Right),static_cast<int>(sf::Keyboard::Right)},
		{ static_cast<int>(GameActions::Escape),static_cast<int>(sf::Keyboard::Escape)},
		{ static_cast<int>(GameActions::Enter),static_cast<int>(sf::Keyboard::Return)},
		{ static_cast<int>(GameActions::Space),static_cast<int>(sf::Keyboard::Space)}
	};


	return customActions;
}


int main()
{
	std::map<int, int> actions = init();
	InputManager *input = new InputManager(actions);

	while (true)
	{
		sf::Event event;
		input->Update();
		//usage:
		std::map<int, int> buttonsState = input->GetState();
		std::cout << buttonsState.find(1)->second << std::endl;
	}
    return 0;
}

