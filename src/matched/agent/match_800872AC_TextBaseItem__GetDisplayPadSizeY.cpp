// 0x800872AC (8 bytes) — lfs 1, 56(3); blr
// TextBaseItem::GetDisplayPadSizeY(void)

class TextBaseItem {
public:
    void GetDisplayPadSizeY(void);
};

__attribute__((naked))
void TextBaseItem::GetDisplayPadSizeY(void) {
    asm volatile(
        "lfs 1, 56(3)
"
        "blr
"
    );
}
