// 0x8008730C (8 bytes) — lwz 3, 32(3); blr
// TextBaseItem::GetText(void) const

class TextBaseItem {
public:
    void GetText(void) const;
};

__attribute__((naked))
void TextBaseItem::GetText(void) const {
    asm volatile(
        "lwz 3, 32(3)
"
        "blr
"
    );
}
