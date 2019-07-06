#pragma once
#include <iostream>
#include <windows.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

extern int screenWidth, screenHeight;
extern glm::vec2 resolution;
extern HWND leagueWindow;

COLORREF getPixelGlobal(int x, int y);
void printColorRef(COLORREF color);
BOOL CALLBACK MatchTargetWindow(HWND hwnd, LPARAM lParam);

void setupResoultion(int screenWidthArg, int screenHeightArg);