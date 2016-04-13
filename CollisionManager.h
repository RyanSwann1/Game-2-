#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "SDLGameObject.h"
#include "Vector2.h"
#include <SDL.h>
class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	static bool ballAndPaddleCollision(SDLGameObject& gameObject);

	static bool checkPaddleGameBoundsWidth(const Vector2& newPos, const int gameWidth);
	static bool checkPaddleGameBoundsHeight(const Vector2& newPos, const int gameHeight);

private:

};
#endif // !COLLISION_MANAGER_H
