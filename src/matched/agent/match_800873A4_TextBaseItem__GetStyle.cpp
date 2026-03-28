// 0x800873A4 (8 bytes) — lwz 3, 108(3); blr
// TextBaseItem::GetStyle(void) const

class TextBaseItem {
public:
    void GetStyle(void) const;
};

__attribute__((naked))
void TextBaseItem::GetStyle(void) const {
    asm volatile(
        "lwz 3, 108(3)
"
        "blr
"
    );
}
