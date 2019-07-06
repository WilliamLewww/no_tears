#include "external_context.h"

HWND leagueWindow;

COLORREF getPixelGlobal(int x, int y) {
	HDC hdc = GetDC(NULL);
	COLORREF color = GetPixel(hdc, 0, 0);
	ReleaseDC(NULL, hdc);

	return color;
}

void printColorRef(COLORREF color) {
  	int red = GetRValue(color);
    int green = GetGValue(color);
    int blue = GetBValue(color);

    std::cout << red << ":" << green << ":" << blue << std::endl;
}

BOOL CALLBACK MatchTargetWindow(HWND hwnd, LPARAM lParam) {
	if(IsWindowVisible(hwnd)) {
		char wnd_title[256];
		GetWindowText(hwnd,wnd_title,sizeof(wnd_title));
		if (strcmp(wnd_title,"League of Legends (TM) Client") == 0) {
			std::cout << "Found Window \"League of Legends (TM) Client\"" << std::endl;
			leagueWindow = hwnd;
		}
	}
	
	return true;
}