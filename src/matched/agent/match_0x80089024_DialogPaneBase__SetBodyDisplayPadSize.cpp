// FLAGS: -fno-elide-constructors -fno-schedule-insns2
// 0x80089024 DialogPaneBase::SetBodyDisplayPadSize(EVec2&) (56B)

struct EVec2 { int x, y; };

struct TextBlock {
    char pad[12];
    void SetDirty();
};

struct Body {
    char pad1[32];
    TextBlock m_tb;
    int size_x;
    int size_y;
    volatile int pad_x;
    volatile int pad_y;
};

struct DialogPaneBase {
    char pad[100];
    Body *m_body;
    void SetBodyDisplayPadSize(EVec2& vec);
};

void DialogPaneBase::SetBodyDisplayPadSize(EVec2& vec) {
    Body *b = m_body;
    int y = vec.y;
    int x = vec.x;
    b->pad_y = y;
    b->pad_x = x;
    b->m_tb.SetDirty();
}
