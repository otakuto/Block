#pragma once
#include "stdafx.hpp"

class DirectInputMouse
{
public:
	DirectInputMouse(HWND const &hwnd, LPDIRECTINPUT8 const &directInput);
	~DirectInputMouse();

public:
	DIMOUSESTATE2 const &MouseState();

public:
	void Update();

protected:
	LPDIRECTINPUTDEVICE8 mouseDevice;

	DIMOUSESTATE2 mouseState;
};
