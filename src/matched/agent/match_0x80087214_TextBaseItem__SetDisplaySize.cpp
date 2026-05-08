// FLAGS: -fno-elide-constructors -fno-schedule-insns2
// 0x80087214 TextBaseItem::SetDisplaySize(EVec2&) (56B)
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
    volatile int size_x;
    volatile int size_y;
    int pad_x;
    int pad_y;
    void SetDisplaySize(EVec2& vec);
};

void TextBaseItem::SetDisplaySize(EVec2& vec) {
    int y = vec.y;
    int x = vec.x;
    size_y = y;
    size_x = x;
    m_tb.SetDirty();
}
