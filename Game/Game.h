#pragma once
#include "stdafx.h"
#include "DirectGraphics.h"
#include "DirectInput.h"
#include "DirectInputKeyboard.h"
#include "DirectInputMouse.h"
#include "Sprite.h"
#include "CollisionManager.h"
#include "Player.h"
#include "Ball.h"

class Game
{
public:
	static int const WINDOW_WIDTH;
	static int const WINDOW_HEIGHT;

public:
	Game(HWND const &hwnd);
	~Game();

public:
	void Run();
	void Draw();

protected:
	DirectGraphics directGraphics;
	DirectInput directInput;
	DirectInputKeyboard directInputKeyboard;
	DirectInputMouse directInputMouse;

	//std::list<Block> blockList;
	std::vector<Player> playerVector;
	std::list<Ball> ballList;
	CollisionManager<std::vector<Player>, std::list<Ball>> collisionManager;
	std::shared_ptr<Sprite const> const smallBallSprite;
	std::shared_ptr<Sprite const> const normalBallSprite;
	std::shared_ptr<Sprite const> const bigBallSprite;
};
