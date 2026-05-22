// 0x80300A84 (100B) EWindow::ClipTest(TRect<float>&)

template<typename T> struct TRect {
    T x1;
    T y1;
    T x2;
    T y2;
};

class EWindow {
public:
    char m_pad[96];
    TRect<float> m_60_rect;
    int ClipTest(TRect<float>& other);
};

int EWindow::ClipTest(TRect<float>& other) {
    TRect<float>* myRect = &m_60_rect;
    int result = 0;
    if (other.x1 >= myRect->x1 &&
        other.x2 <= myRect->x2 &&
        other.y1 >= myRect->y1 &&
        other.y2 <= myRect->y2) {
        result = 1;
    }
    return result ^ 1;
}
