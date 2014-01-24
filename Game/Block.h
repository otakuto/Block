#pragma once
#include "stdafx.h"
#include "Sprite.h"
#include "Ball.h"

template<int id>
class Block
{
public:
	Block(std::shared_ptr<Sprite const> const sprite, D3DXVECTOR3 const &position, D3DXVECTOR3 const &size)
		:
		sprite(sprite),
		position(position),
		size(size)
	{
	}

	~Block()
	{
	}

public:
	void Run();
	void Draw() const;
	void Collision(Ball &ball);
	
protected:
	std::shared_ptr<Sprite const> const sprite;
	D3DXVECTOR3 position;
	D3DXVECTOR3 size;
};

template<>
void Block<0>::Run()
{
}

template<>
void Block<0>::Draw() const
{
	sprite->Draw(position);
}

template<>
void Block<0>::Collision(Ball &ball)
{
}