struct E3DWindow {
    void CalcViewportInv();
    void InputCoordinatesChanged();
};

void E3DWindow::InputCoordinatesChanged()
{
    CalcViewportInv();
}
