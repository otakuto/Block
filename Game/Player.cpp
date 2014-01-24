#pragma once
#include "stdafx.h"
#include "Player.h"
#include "Sprite.h"
#include "Game.h"

D3DXVECTOR3 const Player::PLAYER_INITIAL_POSITION((Game::WINDOW_WIDTH / 2), Game::WINDOW_HEIGHT - 40, 0);

Player::Player(std::shared_ptr<Sprite const> const bodySprite, std::shared_ptr<Sprite const> const edgeSprite, DIMOUSESTATE2 const &mouseState, D3DXVECTOR3 const &position, int const length)
:
bodySprite(bodySprite),
edgeSprite(edgeSprite),
mouseState(mouseState),
position(position),
size(static_cast<float>(length * 16), static_cast<float>(16), 0),
length(length),
movement(0, 0, 0)
{
}

Player::~Player()
{
}

D3DXVECTOR3 const &Player::Size() const
{
	return size;
}

D3DXVECTOR3 &Player::Position()
{
	return position;
}

D3DXVECTOR3 const &Player::Position() const
{
	return position;
}

D3DXVECTOR3 const &Player::Movement() const
{
	return movement;
}

void Player::Run()
{
	{
		int x = position.x + mouseState.lX;
		if (x < (size.x / 2))
		{
			position.x = (size.x / 2);
		}
		else if (x > static_cast<float>(Game::WINDOW_WIDTH) - (size.x / static_cast<float>(2)))
		{
			position.x = static_cast<float>(Game::WINDOW_WIDTH) - (size.x / static_cast<float>(2));
		}
		else
		{
			position.x = x;
		}
	}

	if (mouseState.rgbButtons[0])
	{
		if (Game::WINDOW_HEIGHT >= position.y + 16)
		{
			position.y += 8;
		}
	}
	else
	{
		if (Player::PLAYER_INITIAL_POSITION.y < position.y)
		{
			position.y -= 8;
		}
	}
}

void Player::Draw() const
{
	edgeSprite->Draw(position + D3DXVECTOR3(-(size.x / 2), 0, 0));
	edgeSprite->Draw(position + D3DXVECTOR3((size.x / 2), 0, 0));

	//for (int i = 0; i < length; ++i)
	{
		bodySprite->Draw(position);
	}
}
