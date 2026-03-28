// 0x80087204 (8 bytes) — stfs 1, 40(3); blr
// TextBaseItem::SetPosY(float)

class TextBaseItem {
public:
    void SetPosY(float);
};

__attribute__((naked))
void TextBaseItem::SetPosY(float) {
    asm volatile(
        "stfs 1, 40(3)
"
        "blr
"
    );
}
