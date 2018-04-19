#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"
#include "OrdinaryBullet.h"
#include "Physics.h"

//#include "Pool.h"

class Spaceship : public RigidBody //, public PoolElement //
{
public:
	Spaceship(sf::Vector2f position, sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager& input,
		AnimationPlayer& spaceshipAnimation, AnimationPlayer& ordinaryShotAnimation, AnimationPlayer& powerfulShotAnimation);

	void Accelerate();
	void Decelerate();
	void PowerfulShoot();
	void OrdinaryShoot();
	void RotateSpaceship(float angle);	
	void Update(sf::Time deltaTime);

	~Spaceship();

private:
	//Pool<OrdinaryBullet> _bulletStorage;
	//sf::Vector2f _speed;  //remove when include physics
	sf::Vector2f _spaceshipDirection;

	const float _rotationAngle;
	float _currentAngle;
	const sf::Vector2f _deltaSpeed;
	const sf::Time _rechargeTime;
	bool _isRecharged;	
	sf::Time _timeAfterPowerfulShot;
	const float _rebound;
	const float _powerfulRebound;
	const sf::Time _inputTime;
	sf::Time _inputAccumulatedTime;
	const float _bulletDeltaAngle;
	const float _maxSquareSpeed;

	sf::Sprite* _spaceshipSprite;
	sf::Sprite* _ordinaryShootSprite;
	sf::Sprite* _powerfulShootSprite;
	AnimationPlayer& _spaceshipAnimation;
	AnimationPlayer& _ordinaryShotAnimation;
	AnimationPlayer& _powerfulShotAnimation;

	InputManager& _input;

	void ChangeSpeed(float deltaSpeed);
	float GetSquareSpeed(sf::Vector2f speed) const;
	sf::Vector2f NormalizedDirection();
};