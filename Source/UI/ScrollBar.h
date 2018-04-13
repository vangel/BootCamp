#pragma once
#include "SfmlButton.h"

class ScrollBar :
	public SfmlButton
{
public:
	ScrollBar(const float length, const sf::Vector2f pos, const std::string & name);
	void ChangeStateGrab(const sf::Vector2i position);
	void UnGrab();
	void SetSliderPosition(const float position);
	float GetSliderPosition() const;
	
	void SetFillColor(const sf::Color & color) override;
	void SetOutlineColor(const sf::Color & color) override {};
	void SetLength(const float size);

	float GetLength() const;

	void UpdateControl() override;
	void Draw() override;

	~ScrollBar();
private:
	float _sliderValue;
	void UpdatePosition();
	bool _isGrab;
	sf::RectangleShape _rail;
};

