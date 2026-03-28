// 0x80087254 (8 bytes) — lfs 1, 44(3); blr
// TextBaseItem::GetDisplaySizeX(void)

class TextBaseItem {
public:
    void GetDisplaySizeX(void);
};

__attribute__((naked))
void TextBaseItem::GetDisplaySizeX(void) {
    asm volatile(
        "lfs 1, 44(3)
"
        "blr
"
    );
}
