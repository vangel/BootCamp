#include "UI.h"



UI::UI(sf::VideoMode screen,const std::string &name):
	_space(screen,name,sf::Style::Default)
{
}

void UI::addButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string &name)
{
	_widgets[name] = new SfmlButton(size, pos, name, _space);
}

Widget* UI::GetWidget(const std::string &key) const
{
	auto iter = _widgets.find(key);
	assert(iter != _widgets.end() && "Widget not found");

	Widget* wid = iter->second;

	return wid;
}


UI::~UI()
{
}
