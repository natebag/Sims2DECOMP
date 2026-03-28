// 0x8008725C (8 bytes) — lfs 1, 48(3); blr
// TextBaseItem::GetDisplaySizeY(void)

class TextBaseItem {
public:
    void GetDisplaySizeY(void);
};

__attribute__((naked))
void TextBaseItem::GetDisplaySizeY(void) {
    asm volatile(
        "lfs 1, 48(3)
"
        "blr
"
    );
}
