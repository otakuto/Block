#pragma once
#include "Sprite.h"

class Player
{
public:
	static D3DXVECTOR3 const PLAYER_INITIAL_POSITION;

public:
	Player(std::shared_ptr<Sprite const> const bodySprite, std::shared_ptr<Sprite const> const edgeSprite, DIMOUSESTATE2 const &mouseState, D3DXVECTOR3 const &position, int const length);
	~Player();

public:
	D3DXVECTOR3 const &Size() const;
	D3DXVECTOR3 &Position();
	D3DXVECTOR3 const &Position() const;
	D3DXVECTOR3 const &Movement() const;

public:
	void Run();
	void Draw() const;

protected:
	std::shared_ptr<Sprite const> const bodySprite;
	std::shared_ptr<Sprite const> const edgeSprite;
	DIMOUSESTATE2 const &mouseState;
	D3DXVECTOR3 position;
	D3DXVECTOR3 size;
	int length;
	D3DXVECTOR3 movement;
};
