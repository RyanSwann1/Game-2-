#include "Ball.h"
#include "CollisionManager.h"
#include "Game.h"

const std::string Ball::m_textureID = "Ball";
const std::string Ball::m_ID = "Ball";

Ball::Ball()
{
	//Initialize size
	sizeWidth = 30;
	sizeHeight = 30;

	//Initialize position
	m_position.m_x = 275;
	m_position.m_y = 225;

	//Initialize velocity
	m_velocity.m_x = -3;
	m_velocity.m_y = 0;
}


Ball::~Ball()
{

}

void Ball::update()
{
	handleMovement();
}

void Ball::draw()
{

}

void Ball::handleEvents()
{

}

void Ball::handleMovement()
{
	Vector2 newPos = m_position;
	newPos.m_x -= m_velocity.m_x;
	if (CollisionManager::checkPaddleGameBoundsWidth(newPos, Game::instance()->getPlayingFieldWidth()))
	{

	}
}
