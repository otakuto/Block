#pragma once
#include "stdafx.hpp"
#include "Game.hpp"
#include "Sprite.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include "BallSize.hpp"

int const Game::WINDOW_WIDTH = 800;
int const Game::WINDOW_HEIGHT = 600;

Game::Game(HWND const &hwnd)
:
directGraphics(hwnd),
directInput(),
directInputKeyboard(hwnd, directInput.Get()),
directInputMouse(hwnd, directInput.Get()),
playerVector(),
ballList(),
collisionManager(playerVector, ballList,
[](Player const &player, Ball const &ball)
{
	return ((player.Position().x - (player.Size().x / 2)) < (ball.Position().x + (ball.Size().x / 2))) && ((ball.Position().x - (ball.Size().x / 2)) < (player.Position().x + (player.Size().x / 2))) && ((player.Position().y - (player.Size().y / 2)) < (ball.Position().y + (ball.Size().y / 2))) && ((ball.Position().y - (ball.Size().y / 2)) < (player.Position().y + (player.Size().y / 2)));
},
[](Player &player, Ball &ball)
{
	ball.Collision();
}),
smallBallSprite(std::make_shared<Sprite const>(directGraphics.Device(), TEXT("Resource/Ball/Small.png"), RECT{0, 0, 8, 8}, D3DXVECTOR3(4, 4, 0), false)),
normalBallSprite(std::make_shared<Sprite const>(directGraphics.Device(), TEXT("Resource/Ball/Normal.png"), RECT{0, 0, 16, 16}, D3DXVECTOR3(8, 8, 0), false)),
bigBallSprite(std::make_shared<Sprite const>(directGraphics.Device(), TEXT("Resource/Ball/Big.png"), RECT{0, 0, 32, 32}, D3DXVECTOR3(16, 16, 0), false))
{
	playerVector.push_back(Player(std::make_shared<Sprite const>(directGraphics.Device(), TEXT("Resource/Body.png"), RECT{0, 0, 16, 16}, D3DXVECTOR3(8, 8, 0), false), std::make_shared<Sprite const>(directGraphics.Device(), TEXT("Resource/Edge.png"), RECT{0, 0, 16, 16}, D3DXVECTOR3(8, 8, 0), false), directInputMouse.MouseState(), Player::PLAYER_INITIAL_POSITION, 5));
	ballList.push_back(Ball(smallBallSprite, normalBallSprite, bigBallSprite, D3DXVECTOR3(50, 50, 0), D3DXVECTOR3(10, 10, 0), BallSize::NORMAL));
}

Game::~Game()
{
}

void Game::Run()
{
	directInputKeyboard.Update();
	directInputMouse.Update();
	collisionManager.Detection();
	for (auto &ball : ballList)
	{
		ball.Run();
	}

	playerVector.begin()->Run();
	if (directInputMouse.MouseState().rgbButtons[1])
	{
		ballList.push_back(Ball(smallBallSprite, normalBallSprite, bigBallSprite, playerVector[0].Position(), D3DXVECTOR3(10, 10, 0), BallSize::NORMAL));
	}
}

void Game::Draw()
{
	LPDIRECT3DDEVICE9 const device = directGraphics.Device();
	device->Clear(0, nullptr, (D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL), D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
	device->BeginScene();

	playerVector.begin()->Draw();

	for (auto const &ball : ballList)
	{
		ball.Draw();
	}

	device->EndScene();
	device->Present(nullptr, nullptr, nullptr, nullptr);
}
