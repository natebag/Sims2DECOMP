// FLAGS: -fno-elide-constructors -fno-schedule-insns2
// 0x80088FC8 DialogPaneBase::SetBodyDisplaySize(EVec2&) (56B)

struct EVec2 { int x, y; };

struct TextBlock {
    char pad[12];
    void SetDirty();
};

struct Body {
    char pad1[32];
    TextBlock m_tb;
    volatile int size_x;
    volatile int size_y;
};

struct DialogPaneBase {
    char pad[100];
    Body *m_body;
    void SetBodyDisplaySize(EVec2& vec);
};

void DialogPaneBase::SetBodyDisplaySize(EVec2& vec) {
    Body *b = m_body;
    int y = vec.y;
    int x = vec.x;
    b->size_y = y;
    b->size_x = x;
    b->m_tb.SetDirty();
}
