#include "Player.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "CollisionManager.h"
#include <iostream>

const std::string Player::m_textureID = "Player";
const std::string Player::m_ID = "Player";

Player::Player()
{
	//Initialize size
	sizeHeight = 80;
	sizeWidth = 25;

	//Initialize starting position
	m_position.setX(50);
	m_position.setY(200);

	//Initialize velocity
	m_velocity.setX(0);
	m_velocity.setY(3);
}


Player::~Player()
{
}

void Player::update()
{
	//Move onto the event 
	handleEvents();
}

void Player::draw()
{
	TextureManager::instance()->draw(m_position.getX(), m_position.getY(), sizeWidth, sizeHeight, Game::instance()->getRenderer(), m_textureID);
}

void Player::handleEvents()
{
	Vector2 newPos; //New position in which to move

	if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_W))
	{
		//Get position of requested move
		newPos.m_y = m_position.m_y - m_velocity.m_y;
		//Check requested movement is within bounds
		if (CollisionManager::checkPaddleGameBoundsHeight(newPos, Game::instance()->getPlayingFieldWidth())) {
			m_position.m_y -= m_velocity.m_y;
		}
	}

	else if (InputHandler::instance()->isKeyDown(SDL_SCANCODE_S)) 
	{
		//Get position of requested move
		newPos.m_y = (m_position.m_y + sizeHeight) + m_velocity.m_y;
		//Check for collision with bounds
		if (CollisionManager::checkPaddleGameBoundsHeight(newPos, Game::instance()->getPlayingFieldHeight())) {
			m_position.m_y += m_velocity.m_y;
		}
	}
}

std::string Player::getTextureID() const
{
	return m_textureID;
}

std::string Player::getID() const
{
	return m_ID;
}
