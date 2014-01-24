#pragma once
#include "stdafx.hpp"

class DirectInputKeyboard
{
public:
	DirectInputKeyboard(HWND const &hwnd, LPDIRECTINPUT8 const &directInput);
	~DirectInputKeyboard();

public:
	const std::vector<unsigned char const> &Key() const;

public:
	void Update();

protected:
	static int const KEY_LENGTH;

protected:
	LPDIRECTINPUTDEVICE8 keyboardDevice;
	
	std::vector<unsigned char const> key;
};
