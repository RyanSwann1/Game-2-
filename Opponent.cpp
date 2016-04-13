#include "Opponent.h"
#include "TextureManager.h"
#include "Game.h"
#include "CollisionManager.h"
#include "Player.h"
#include <iostream>
#include <string>

const std::string Opponent::m_textureID = "Opponent";
const std::string Opponent::m_ID = "Opponent";

Opponent::Opponent()
{
	//Initialize size
	sizeHeight = 80;
	sizeWidth = 25;

	//Initialize Starting position
	m_position.setX(450);
	m_position.setY(200);

	//Initialize velocity
	m_velocity.setX(0);
	m_velocity.setY(3);
}


Opponent::~Opponent()
{
}

void Opponent::update()
{
	
	handleMovement();
}

void Opponent::draw()
{
	TextureManager::instance()->draw(m_position.m_x, m_position.m_y, sizeWidth, sizeHeight, Game::instance()->getRenderer(), m_textureID);
}

void Opponent::handleEvents()
{
}

void Opponent::handleMovement()
{
	Vector2 pos = m_position; //Get current position
	for (auto &gameObject : Game::instance()->getGameObjects())
	{
		//std::cout << gameObject->getID();
		//std::cout << "Hello World";
		////std::cout << "Player not found.";
		if (gameObject->getID() == "Player")
		{
			if (gameObject->getPos().m_y < pos.m_y) 
			{
				Vector2 newPos;
				newPos.m_y = m_position.m_y - m_velocity.m_y;
				if (CollisionManager::checkPaddleGameBoundsHeight(newPos, Game::instance()->getPlayingFieldHeight())) {
					m_position.m_y -= m_velocity.m_y;
				}
			}

			if (gameObject->getPos().m_y > pos.m_y) 
			{
				Vector2 newPos;
				newPos.m_y = m_position.m_y + m_velocity.m_y;
				if (CollisionManager::checkPaddleGameBoundsHeight(newPos, Game::instance()->getPlayingFieldHeight())) {
					m_position.m_y += m_velocity.m_y;
				}
			}
		}
	}
}

std::string Opponent::getTextureID() const
{
	return m_textureID;
}

std::string Opponent::getID() const
{
	return m_ID;
}
