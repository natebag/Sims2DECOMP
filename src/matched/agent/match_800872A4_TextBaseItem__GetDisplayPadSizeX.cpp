// 0x800872A4 (8 bytes) — lfs 1, 52(3); blr
// TextBaseItem::GetDisplayPadSizeX(void)

class TextBaseItem {
public:
    void GetDisplayPadSizeX(void);
};

__attribute__((naked))
void TextBaseItem::GetDisplayPadSizeX(void) {
    asm volatile(
        "lfs 1, 52(3)\n"
        "blr\n"
    );
}
