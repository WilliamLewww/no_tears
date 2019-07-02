#pragma once
#include <iostream>
#include <windows.h>

extern HWND leagueWindow;

COLORREF getPixelGlobal(int x, int y);
void printColorRef(COLORREF color);

BOOL CALLBACK MatchTargetWindow(HWND hwnd, LPARAM lParam);