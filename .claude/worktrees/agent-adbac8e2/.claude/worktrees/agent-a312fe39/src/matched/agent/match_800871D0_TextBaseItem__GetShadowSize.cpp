// 0x800871D0 (8 bytes) — lfs 1, 76(3); blr
// TextBaseItem::GetShadowSize(void)

class TextBaseItem {
public:
    void GetShadowSize(void);
};

__attribute__((naked))
void TextBaseItem::GetShadowSize(void) {
    asm volatile(
        "lfs 1, 76(3)\n"
        "blr\n"
    );
}
