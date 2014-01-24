#pragma once
#include "stdafx.h"
#include "DirectInputKeyboard.h"

int const DirectInputKeyboard::KEY_LENGTH = 256;

DirectInputKeyboard::DirectInputKeyboard(HWND const &hwnd, LPDIRECTINPUT8 const &directInput)
:
key(std::vector<unsigned char const>(KEY_LENGTH))
{
	directInput->CreateDevice(GUID_SysKeyboard, &keyboardDevice, nullptr);
	keyboardDevice->SetDataFormat(&c_dfDIKeyboard);
	keyboardDevice->SetCooperativeLevel(hwnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY));
	keyboardDevice->Acquire();
}

DirectInputKeyboard::~DirectInputKeyboard()
{
	keyboardDevice->Unacquire();
	SAFE_RELEASE(keyboardDevice);
}

const std::vector<unsigned char const> &DirectInputKeyboard::Key() const
{
	return key;
}

void DirectInputKeyboard::Update()
{
	if (FAILED(keyboardDevice->GetDeviceState((sizeof(unsigned char const)* KEY_LENGTH), key.data())))
	{
		keyboardDevice->Acquire();
	}
}