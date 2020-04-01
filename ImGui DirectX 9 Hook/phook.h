#pragma once
#include "pch.h"

extern bool init_hook;
extern HWND window;
extern void* pDevice[119];
extern PTR EndSceneAddress;
extern EndScene oEndScene;
extern WNDPROC oWndProc;
extern bool initialized;
#if defined(ARCH_X86)
#define ENDSCENE_HOOK_LENGTH 7
#elif defined(ARCH_X64)
#define ENDSCENE_HOOK_LENGTH 15
#endif

namespace PHook
{
	void Init();
	void Shutdown();
	long __stdcall hkEndScene(LPDIRECT3DDEVICE9 device);
	LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
}