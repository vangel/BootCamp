#include "Input.h"
#include <cassert>
#include <iostream>
#include <map>

enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot
};

std::multimap<int, ButtonKey_t> init() {

	std::multimap<int, ButtonKey_t> customActions = {
	{ static_cast<int>(GameActions::MoveUp), sf::Keyboard::Up },
	{ static_cast<int>(GameActions::MoveUp), sf::Keyboard::W },
	{ static_cast<int>(GameActions::MoveDown), sf::Keyboard::Down },
	{ static_cast<int>(GameActions::MoveDown), sf::Keyboard::S },
	{ static_cast<int>(GameActions::MoveLeft), sf::Keyboard::Left },
	{ static_cast<int>(GameActions::MoveLeft), sf::Keyboard::A },
	{ static_cast<int>(GameActions::MoveRight), sf::Keyboard::Right },
	{ static_cast<int>(GameActions::MoveRight), sf::Keyboard::D },
	{ static_cast<int>(GameActions::Exit), sf::Keyboard::Escape },
	{ static_cast<int>(GameActions::Choose), sf::Keyboard::Return },
	{ static_cast<int>(GameActions::Shoot), sf::Keyboard::Space }
	};

	return customActions;
}

std::string GetNameForState(ButtonsState bState) {

	switch (bState)
	{
	case ButtonsState::JustPressed:
		return "JustPressed";
	case ButtonsState::Pressed:
		return "Pressed";
	case ButtonsState::JustReleased:
		return "JustReleased";
	case ButtonsState::Released:
		return "Released";
	default:
		return "Undefined";
		break;
	}
}

int main()
{
	std::multimap<int, ButtonKey_t> actions = init();

	if (actions.empty())
	{
		std::cout << "Failed: Actions from Config is empty!" << std::endl;
		return 1;
	}

	InputManager input(actions);

	// ~~~~~~~~~~~~ Only for test mode! ~~~~~~~~~~~~~~
	// We don't want to see "released" or "pressed" all the time - so let's print to the console only when state changes
	ButtonsState previousStateMoveUp = ButtonsState::Released;
	ButtonsState previousStateMoveDown = ButtonsState::Released;
	ButtonsState previousStateMoveLeft = ButtonsState::Released;
	ButtonsState previousStateMoveRight = ButtonsState::Released;
	ButtonsState previousStateExit = ButtonsState::Released;
	ButtonsState previousStateChoose = ButtonsState::Released;
	ButtonsState previousStateShoot = ButtonsState::Released;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	ButtonsState stateMoveUp;
	ButtonsState stateMoveDown;
	ButtonsState stateMoveLeft;
	ButtonsState stateMoveRight;
	ButtonsState stateExit;
	ButtonsState stateChoose;
	ButtonsState stateShoot;

	while (true)
	{
		input.Update();

		if (input.GetState(static_cast<int>(GameActions::MoveUp), stateMoveUp) && previousStateMoveUp != stateMoveUp)
		{
			std::cout << "MoveUp state - " << GetNameForState(stateMoveUp) << std::endl;
			previousStateMoveUp = stateMoveUp;
		}
		if (input.GetState(static_cast<int>(GameActions::MoveDown), stateMoveDown) && previousStateMoveDown != stateMoveDown)
		{
			std::cout << "MoveDown state - " << GetNameForState(stateMoveDown) << std::endl;
			previousStateMoveDown = stateMoveDown;
		}
		if (input.GetState(static_cast<int>(GameActions::MoveLeft), stateMoveLeft) && previousStateMoveLeft != stateMoveLeft)
		{
			std::cout << "MoveLeft state - " << GetNameForState(stateMoveLeft) << std::endl;
			previousStateMoveLeft = stateMoveLeft;
		}
		if (input.GetState(static_cast<int>(GameActions::MoveRight), stateMoveRight) && previousStateMoveRight != stateMoveRight)
		{
			std::cout << "MoveRight state - " << GetNameForState(stateMoveRight) << std::endl;
			previousStateMoveRight = stateMoveRight;
		}
		if (input.GetState(static_cast<int>(GameActions::Exit), stateExit) && previousStateExit != stateExit)
		{
			std::cout << "Exit state - " << GetNameForState(stateExit) << std::endl;
			previousStateExit = stateExit;
		}
		if (input.GetState(static_cast<int>(GameActions::Choose), stateChoose) && previousStateChoose != stateChoose)
		{
			std::cout << "Choose state - " << GetNameForState(stateChoose) << std::endl;
			previousStateChoose = stateChoose;
		}
		if (input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && previousStateShoot != stateShoot)
		{
			std::cout << "Shoot state - " << GetNameForState(stateShoot) << std::endl;
			previousStateShoot = stateShoot;
		}

	}
	return 0;
}

