// 0x80087198 (8 bytes) — lwz 3, 68(3); blr
// TextBaseItem::GetColor(void)

class TextBaseItem {
public:
    void GetColor(void);
};

__attribute__((naked))
void TextBaseItem::GetColor(void) {
    asm volatile(
        "lwz 3, 68(3)
"
        "blr
"
    );
}
