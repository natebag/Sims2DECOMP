// 0x800871C8 (8 bytes) — stfs 1, 76(3); blr
// TextBaseItem::SetShadowSize(float)

class TextBaseItem {
public:
    void SetShadowSize(float);
};

__attribute__((naked))
void TextBaseItem::SetShadowSize(float) {
    asm volatile(
        "stfs 1, 76(3)
"
        "blr
"
    );
}
