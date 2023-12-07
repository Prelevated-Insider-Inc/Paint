// mspaint/imgtools.cpp

void CBrushTool::AdjustBrushSizeBasedOnZoomLevel(int zoomLevel) {
    // Adjust the size of the brush based on the zoom level
    m_nStrokeWidth = m_nStrokeWidth * zoomLevel;
}

void CBrushTool::OnDrag(CImgWnd* pImgWnd, MTI* pmti) {
    // Adjust the coordinates of the brush based on the zoom level
    int zoomLevel = pImgWnd->GetZoomLevel();
    pmti->pt.x = pmti->pt.x / zoomLevel;
    pmti->pt.y = pmti->pt.y / zoomLevel;

    // Call the original OnDrag function
    CFreehandTool::OnDrag(pImgWnd, pmti);
}

// mspaint/imgtools.h

class CBrushTool : public CFreehandTool {
    // ...
    void AdjustBrushSizeBasedOnZoomLevel(int zoomLevel);
    void OnDrag(CImgWnd* pImgWnd, MTI* pmti) override;
    // ...
};

// Unit tests

void TestAdjustBrushSizeBasedOnZoomLevel() {
    CBrushTool brushTool;
    brushTool.SetStrokeWidth(10);
    brushTool.AdjustBrushSizeBasedOnZoomLevel(2);
    assert(brushTool.GetStrokeWidth() == 20);
}

void TestOnDrag() {
    CImgWnd imgWnd;
    imgWnd.SetZoomLevel(2);
    MTI mti;
    mti.pt.x = 20;
    mti.pt.y = 20;
    CBrushTool brushTool;
    brushTool.OnDrag(&imgWnd, &mti);
    assert(mti.pt.x == 10);
    assert(mti.pt.y == 10);
}
