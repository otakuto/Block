#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Player.h"
#include "BallSize.h"

class Ball
{
public:
	Ball(std::shared_ptr<Sprite const> const smallBallSprite, std::shared_ptr<Sprite const> const normalBallSprite, std::shared_ptr<Sprite const> const bigBallSprite, D3DXVECTOR3 const &position, D3DXVECTOR3 const &speed, BallSize const ballSize);
	~Ball();

public:
	D3DXVECTOR3 &Position();
	D3DXVECTOR3 const &Position() const;
	D3DXVECTOR3 const &Size() const;

public:
	void Run();
	void Draw() const;
	void Collision();

protected:
	std::shared_ptr<Sprite const> const smallBallSprite;
	std::shared_ptr<Sprite const> const normalBallSprite;
	std::shared_ptr<Sprite const> const bigBallSprite;
	D3DXVECTOR3 position;
	D3DXVECTOR3 speed;
	D3DXVECTOR3 size;
	BallSize ballSize;
};
