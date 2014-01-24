#pragma once
#include "stdafx.h"
#include "Ball.h"
#include "Sprite.h"
#include "Game.h"
#include "Player.h"

Ball::Ball(std::shared_ptr<Sprite const> const smallBallSprite, std::shared_ptr<Sprite const> const normalBallSprite, std::shared_ptr<Sprite const> const bigBallSprite, D3DXVECTOR3 const &position, D3DXVECTOR3 const &speed, BallSize const ballSize)
:
smallBallSprite(smallBallSprite),
normalBallSprite(normalBallSprite),
bigBallSprite(bigBallSprite),
position(position),
speed(speed),
size(static_cast<float>(ballSize), static_cast<float>(ballSize), 0),
ballSize(ballSize)
{

}

Ball::~Ball()
{
}

D3DXVECTOR3 const &Ball::Size() const
{
	return size;
}

D3DXVECTOR3 &Ball::Position()
{
	return position;
}

D3DXVECTOR3 const &Ball::Position() const
{
	return position;
}

void Ball::Run()
{
	D3DXVECTOR3 newPosition;
	D3DXVec3Add(&newPosition, &position, &speed);
	if (newPosition.x < 0)
	{
		newPosition.x = 0;
		speed.x = -speed.x;
	}
	if (Game::WINDOW_WIDTH < newPosition.x)
	{
		newPosition.x = static_cast<float>(Game::WINDOW_WIDTH);
		speed.x = -speed.x;
	}
	if (newPosition.y <= 0)
	{
		newPosition.y = 0;
		speed.y = -speed.y;
	}
	if (Game::WINDOW_HEIGHT <= newPosition.y)
	{
		newPosition.y = static_cast<float>(Game::WINDOW_HEIGHT);
		speed.y = -speed.y;
	}
	position = newPosition;
}

void Ball::Draw() const
{
	switch (ballSize)
	{
	case BallSize::SMALL:
		smallBallSprite->Draw(position);
		break;

	case BallSize::NORMAL:
		normalBallSprite->Draw(position);
		break;

	case BallSize::BIG:
		bigBallSprite->Draw(position);
		break;

	default:
		break;
	}
}

void Ball::Collision()
{
	speed = -speed;
}
