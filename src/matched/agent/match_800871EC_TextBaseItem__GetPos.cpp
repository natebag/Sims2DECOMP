// 0x800871EC (8 bytes) — addi 3, 3, 36; blr
// TextBaseItem::GetPos(void)

class TextBaseItem {
public:
    void GetPos(void);
};

__attribute__((naked))
void TextBaseItem::GetPos(void) {
    asm volatile(
        "addi 3, 3, 36
"
        "blr
"
    );
}
