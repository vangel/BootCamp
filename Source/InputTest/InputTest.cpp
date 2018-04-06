#include "Input.h"
#include <cassert>
#include <iostream>
#include <map>

std::map<int, int> init() {

	std::map<int,int> customActions = {
		{ static_cast<int>(GameActions::Up) ,   static_cast<int>(sf::Keyboard::Up)},
		{ static_cast<int>(GameActions::Down),  static_cast<int>(sf::Keyboard::Down)},
		{ static_cast<int>(GameActions::Left),  static_cast<int>(sf::Keyboard::Left)},
		{ static_cast<int>(GameActions::Right), static_cast<int>(sf::Keyboard::Right)},
		{ static_cast<int>(GameActions::Escape),static_cast<int>(sf::Keyboard::Escape)},
		{ static_cast<int>(GameActions::Enter), static_cast<int>(sf::Keyboard::Return)},
		{ static_cast<int>(GameActions::Space), static_cast<int>(sf::Keyboard::Space)}
	};


	return customActions;
}

std::string getNameForAction(int action) {
	switch (action)
	{
	case 0:
		return "Up";
	case 1:
		return "Down";
	case 2:
		return "Left";
	case 3:
		return "Right";
	case 4:
		return "Escape";
	case 5:
		return "Enter";
	case 6:
		return "Space";
	default: 
		return "unknown :(((";
		break;
	}
}

std::string getNameForState(int bState) {
	switch (bState)
	{
	case 0:
		return "JustPressed";
	case 1:
		return "Pressed";
	case 2:
		return "JustReleased";
	case 3:
		return "Released";
	default:
		return "indefined";
		break;
	}
}


int main()
{
	std::map<int, int> actions = init();

	if (actions.empty())
	{
		std::cout << "Failed: Actions from Config is empty!" << std::endl;
		return 1;
	}

	InputManager *input = new InputManager(actions);

	if (input == nullptr)
	{
		std::cout << "Failed: Input is null!" << std::endl;
		return 2;
	}
	std::map<int, int> previousState = input->GetState();


	while (true)
	{
		input->Update();
		std::map<int, int> buttonsState = input->GetState();

		if (buttonsState.empty())
		{
			std::cout << "Failed: Buttons state after update is empty!" << std::endl;
			return 3;
		} 

		for (int action = static_cast<int> (GameActions::Up), lastAction = static_cast<int> (GameActions::Space); action <= lastAction; ++action)
		{
			std::map<int, int>::iterator it = buttonsState.find(action);
			if (it->second != previousState.find(action)->second)
			{
				std::cout << "action - " << getNameForAction(it->first) << ", state - " << getNameForState(it->second) << std::endl;
				previousState.find(action)->second = it->second;
			}
		}
	}
    return 0;
}

