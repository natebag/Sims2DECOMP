// 0x800871B8 (8 bytes) — stfs 1, 72(3); blr
// TextBaseItem::SetShadowAlpha(float)

class TextBaseItem {
public:
    void SetShadowAlpha(float);
};

__attribute__((naked))
void TextBaseItem::SetShadowAlpha(float) {
    asm volatile(
        "stfs 1, 72(3)
"
        "blr
"
    );
}
