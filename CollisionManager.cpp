#include "CollisionManager.h"



CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

bool CollisionManager::ballAndPaddleCollision(SDLGameObject & gameObject)
{
	return true;
}

bool CollisionManager::checkPaddleGameBoundsWidth(const Vector2& newPos, const int gameWidth)
{
	//If new requested position isn't colliding with game bounds
	if (newPos.m_x >= 0 && newPos.m_x <= gameWidth) {
		return true;
	}
	//If new requested position exceeds game bounds
	return false;
}

bool CollisionManager::checkPaddleGameBoundsHeight(const Vector2& newPos, const int gameHeight)
{
	if (newPos.m_y >= 0 && newPos.m_y <= gameHeight) {
		return true;
	}

	return false;
}
