#pragma once
#include "SDLGameObject.h"
#include "Vector2.h"
#include <SDL.h>
#include <string>
class Player :
	public SDLGameObject
{
public:
	Player();
	~Player();

	void update() override;
	void draw() override;
	void handleEvents() override;
	Vector2 getPos() const override { return m_position; }
	std::string getTextureID() const override;
	std::string getID() const override;

private:
	int sizeWidth;
	int sizeHeight;
	Vector2 m_position; //Position of player
	Vector2 m_velocity; //Velocity of player
	static const std::string m_textureID;
	static const std::string m_ID;
};

