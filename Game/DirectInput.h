#pragma once
#include "stdafx.h"

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

