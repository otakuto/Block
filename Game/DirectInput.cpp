#pragma once
#include "stdafx.hpp"
#include "DirectInput.hpp"

DirectInput::DirectInput()
{
	DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, reinterpret_cast<void**>(&directInput), nullptr);
}

DirectInput::~DirectInput()
{
	SAFE_RELEASE(directInput);
}

LPDIRECTINPUT8 const &DirectInput::Get() const
{
	return directInput;
}