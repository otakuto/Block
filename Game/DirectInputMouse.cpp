#pragma once
#include "stdafx.h"
#include "DirectInputMouse.h"

DirectInputMouse::DirectInputMouse(HWND const &hwnd, LPDIRECTINPUT8 const &directInput)
{
	directInput->CreateDevice(GUID_SysMouse, &mouseDevice, nullptr);
	mouseDevice->SetDataFormat(&c_dfDIMouse2);
	mouseDevice->SetCooperativeLevel(hwnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY));
	{
		DIPROPDWORD diprop;
		diprop.diph.dwSize = sizeof(diprop);
		diprop.diph.dwHeaderSize = sizeof(diprop.diph);
		diprop.diph.dwObj = 0;
		diprop.diph.dwHow = DIPH_DEVICE;
		diprop.dwData = DIPROPAXISMODE_REL;
		mouseDevice->SetProperty(DIPROP_AXISMODE, &diprop.diph);
	}
	mouseDevice->Acquire();
}

DirectInputMouse::~DirectInputMouse()
{
	mouseDevice->Unacquire();
	SAFE_RELEASE(mouseDevice);
}

DIMOUSESTATE2 const &DirectInputMouse::MouseState()
{
	return mouseState;
}

void DirectInputMouse::Update()
{
	if (FAILED(mouseDevice->GetDeviceState(sizeof(mouseState), &mouseState)))
	{
		mouseDevice->Acquire();
		mouseState = {};
	}
}
