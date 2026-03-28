// 0x800871C0 (8 bytes) — lfs 1, 72(3); blr
// TextBaseItem::GetShadowAlpha(void)

class TextBaseItem {
public:
    void GetShadowAlpha(void);
};

__attribute__((naked))
void TextBaseItem::GetShadowAlpha(void) {
    asm volatile(
        "lfs 1, 72(3)\n"
        "blr\n"
    );
}
