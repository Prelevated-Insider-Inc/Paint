// mspaint/global.cpp

#include "stdafx.h"
#include "global.h"
#include "pbrush.h"

// Current zoom level
static int zoomLevel = 1;

// Increase the zoom level
void ZoomIn() {
    zoomLevel *= 2;
    // Re-render the image
    theApp.m_pMainWnd->Invalidate();
}

// Decrease the zoom level
void ZoomOut() {
    zoomLevel /= 2;
    // Re-render the image
    theApp.m_pMainWnd->Invalidate();
}

// Handle scroll events
void HandleScroll(int direction) {
    if (direction > 0) {
        ZoomIn();
    } else {
        ZoomOut();
    }
}

// Override the window procedure to handle WM_HOTKEY messages
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_HOTKEY:
        switch (wParam) {
        case ID_HOTKEY_ZOOMIN:
            ZoomIn();
            break;
        case ID_HOTKEY_ZOOMOUT:
            ZoomOut();
            break;
        }
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Register the hot keys
void RegisterHotKeys(HWND hWnd) {
    RegisterHotKey(hWnd, ID_HOTKEY_ZOOMIN, MOD_CONTROL, VK_OEM_PLUS);
    RegisterHotKey(hWnd, ID_HOTKEY_ZOOMOUT, MOD_CONTROL, VK_OEM_MINUS);
}

// mspaint/global.h

// Hot key identifiers
#define ID_HOTKEY_ZOOMIN 1
#define ID_HOTKEY_ZOOMOUT 2

// Function declarations
void ZoomIn();
void ZoomOut();
void HandleScroll(int direction);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void RegisterHotKeys(HWND hWnd);
