class E3DWindow {
public:
    void CalcViewportInv();
    void InputCoordinatesChanged();
};
void E3DWindow::InputCoordinatesChanged() { CalcViewportInv(); }
