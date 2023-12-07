#include "stdafx.h"
#include "zoom_slider.h"
#include "global.h"
#include <gdiplus.h>

class ZoomSlider : public Slider {
private:
    int zoomLevel;

public:
    int getZoomLevel() {
        return zoomLevel;
    }

    void setZoomLevel(int level) {
        zoomLevel = level;
        // Update the slider position based on the new zoom level
        setPosition(level);
    }

    void handleSliderEvent() {
        // If the slider is moved to the right, zoom in
        if (getPosition() > zoomLevel) {
            ZoomIn();
        }
        // If the slider is moved to the left, zoom out
        else if (getPosition() < zoomLevel) {
            ZoomOut();
        }
        // Update the zoom level to match the new slider position
        zoomLevel = getPosition();
    }

    void drawSlider() {
        // Use GDI+ functions to draw the slider
        Gdiplus::Graphics graphics(GetDC(NULL));
        Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 255));
        graphics.DrawLine(&pen, 0, 0, getPosition(), 0);
    }
};
