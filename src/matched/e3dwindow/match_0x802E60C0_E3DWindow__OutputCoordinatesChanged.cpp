struct E3DWindow {
    void CalcViewport();
    void OutputCoordinatesChanged();
};

void E3DWindow::OutputCoordinatesChanged()
{
    CalcViewport();
}
