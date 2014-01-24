#pragma once
#include "stdafx.h"

class DirectGraphics
{
public:
	DirectGraphics(HWND const &hwnd);
	~DirectGraphics();

public:
	LPDIRECT3DDEVICE9 const &Device() const;

public:
	void createDirect3DDeviceObject(HWND const &hwnd);
	void setRenderingConfiguration();
	void setFogConfiguration();

protected:
	LPDIRECT3D9	direct3D;
	LPDIRECT3DDEVICE9 device;
	float fogStart;
	float fogEnd;
};
