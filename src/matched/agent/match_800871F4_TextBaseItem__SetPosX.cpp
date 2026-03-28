// 0x800871F4 (8 bytes) — stfs 1, 36(3); blr
// TextBaseItem::SetPosX(float)

class TextBaseItem {
public:
    void SetPosX(float);
};

__attribute__((naked))
void TextBaseItem::SetPosX(float) {
    asm volatile(
        "stfs 1, 36(3)
"
        "blr
"
    );
}
