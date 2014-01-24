#pragma once
#include "stdafx.hpp"

class DirectInput
{
public:
	DirectInput();
	~DirectInput();

public:
	LPDIRECTINPUT8 const &Get() const;

protected:
	LPDIRECTINPUT8 directInput;
};

