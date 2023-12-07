#include <iostream>
#include <cmath>
#include "app_view.h"
#include "zoom_slider.h"

void zoomIn(double currentZoomLevel) {
    double newZoomLevel = currentZoomLevel * 1.1;
    updateView(newZoomLevel);
    updateZoomSliderPosition(newZoomLevel);
}

void zoomOut(double currentZoomLevel) {
    double newZoomLevel = currentZoomLevel / 1.1;
    updateView(newZoomLevel);
    updateZoomSliderPosition(newZoomLevel);
}

void updateView(double zoomLevel) {
    AppView::getInstance().setZoomLevel(zoomLevel);
    AppView::getInstance().redraw();
}

void handleZoomSlider(int sliderPosition) {
    double newZoomLevel = sliderPosition / 100.0;
    updateView(newZoomLevel);
}

void updateZoomSliderPosition(double zoomLevel) {
    int newSliderPosition = static_cast<int>(zoomLevel * 100);
    ZoomSlider::getInstance().setPosition(newSliderPosition);
}
