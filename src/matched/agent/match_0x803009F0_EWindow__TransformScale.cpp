// 0x803009F0 EWindow::TransformScale(EVec2&, EVec2&) (36 B)

struct EVec2 { float x, y; };

class EWindow {
public:
    float m_scaleX;
    char pad[0x10];
    float m_scaleY;
public:
    void TransformScale(EVec2&, EVec2&);
};

void EWindow::TransformScale(EVec2& src, EVec2& dst) {
    dst.x = src.x * m_scaleX;
    dst.y = src.y * m_scaleY;
}
