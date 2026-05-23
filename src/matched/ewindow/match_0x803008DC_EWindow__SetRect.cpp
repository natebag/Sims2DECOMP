template <class T> struct TRect {
    T left, top, right, bottom;
};

struct EWindow {
    void SetInputCoordinates(TRect<float> &rect);
    void SetOutputCoordinates(TRect<float> &rect);
    void SetClip(TRect<float> &rect);
    void SetRect(TRect<float> &rect);
};

void EWindow::SetRect(TRect<float> &rect) {
    SetInputCoordinates(rect);
    SetOutputCoordinates(rect);
    SetClip(rect);
}
