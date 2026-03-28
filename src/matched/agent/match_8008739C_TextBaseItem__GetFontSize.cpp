// 0x8008739C (8 bytes) — lfs 1, 84(3); blr
// TextBaseItem::GetFontSize(void) const

class TextBaseItem {
public:
    void GetFontSize(void) const;
};

__attribute__((naked))
void TextBaseItem::GetFontSize(void) const {
    asm volatile(
        "lfs 1, 84(3)
"
        "blr
"
    );
}
