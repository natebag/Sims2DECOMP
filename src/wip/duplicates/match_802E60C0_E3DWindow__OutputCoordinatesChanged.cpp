class E3DWindow {
public:
    void CalcViewport();
    void OutputCoordinatesChanged();
};
void E3DWindow::OutputCoordinatesChanged() { CalcViewport(); }
