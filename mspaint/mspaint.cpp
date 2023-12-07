#include "stdafx.h"
#include "global.h"
#include "pbrush.h"
#include "pbrusfrm.h"
#include "ipframe.h"
#include "pbrusdoc.h"
#include "pbrusvw.h"
#include "bmobject.h"
#include "imgsuprt.h"
#include "imgwnd.h"
#include "imgwell.h"
#include "imgtools.h"
#include "ferr.h"
#include "cmpmsg.h"
#include "settings.h"
#include "undo.h"
#include "colorsrc.h"
#include "printres.h"
#include "loadimag.h"
#include "image.h"
#include <dlgs.h>
#include <shlobj.h>
#include "ofn.h"
#include "imaging.h"

// ... existing code ...

BOOL CPBApp::InitInstance()
{
    // ... existing code ...

    // Create the zoom slider
    HWND hwndSlider = CreateWindowEx(0, TRACKBAR_CLASS, NULL,
        WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_ENABLESELRANGE,
        0, 0, 100, 30, hwndStatusBar, NULL, AfxGetInstanceHandle(), NULL);

    // Set the range and initial position of the slider
    SendMessage(hwndSlider, TBM_SETRANGE, TRUE, MAKELONG(1, 100));
    SendMessage(hwndSlider, TBM_SETPOS, TRUE, 50);

    // ... existing code ...
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        // ... existing code ...

        case WM_HSCROLL:
        {
            // Get the new position of the slider
            int iPos = SendMessage(hwndSlider, TBM_GETPOS, 0, 0);

            // Calculate the new zoom level and update the paintbrush view
            double dZoom = iPos / 50.0;
            UpdatePaintbrushView(dZoom);

            break;
        }

        case WM_MOUSEWHEEL:
        case WM_KEYDOWN:
        case WM_KEYUP:
        {
            // Check if the Ctrl key is pressed
            if (GetKeyState(VK_CONTROL) & 0x8000)
            {
                // Adjust the position of the slider and the zoom level
                int iPos = SendMessage(hwndSlider, TBM_GETPOS, 0, 0);
                if (msg == WM_MOUSEWHEEL)
                    iPos += GET_WHEEL_DELTA_WPARAM(wParam) > 0 ? 1 : -1;
                else if (msg == WM_KEYDOWN)
                    iPos += wParam == VK_OEM_PLUS ? 1 : wParam == VK_OEM_MINUS ? -1 : 0;
                SendMessage(hwndSlider, TBM_SETPOS, TRUE, iPos);
                double dZoom = iPos / 50.0;
                UpdatePaintbrushView(dZoom);
            }

            break;
        }

        // ... existing code ...
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}

// ... existing code ...
