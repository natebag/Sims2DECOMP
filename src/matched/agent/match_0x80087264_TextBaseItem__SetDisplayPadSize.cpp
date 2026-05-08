// FLAGS: -fno-elide-constructors -fno-schedule-insns2
// 0x80087264 TextBaseItem::SetDisplayPadSize(EVec2&) (56B)
// ASMPROC_swap_adj: a=mr b=lwz which=first
// ASMPROC_swap_adj: a=addi b=lwz which=first

struct EVec2 { int x, y; };

struct TextBlock {
    char pad[12];
    void SetDirty();
};

struct TextBaseItem {
    char pad1[32];
    TextBlock m_tb;
    int size_x;
    int size_y;
    volatile int pad_x;
    volatile int pad_y;
    void SetDisplayPadSize(EVec2& vec);
};

void TextBaseItem::SetDisplayPadSize(EVec2& vec) {
    int y = vec.y;
    int x = vec.x;
    pad_y = y;
    pad_x = x;
    m_tb.SetDirty();
}
