// 0x8008724C (8 bytes) — addi 3, 3, 44; blr
// TextBaseItem::GetDisplaySize(void)

class TextBaseItem {
public:
    void GetDisplaySize(void);
};

__attribute__((naked))
void TextBaseItem::GetDisplaySize(void) {
    asm volatile(
        "addi 3, 3, 44\n"
        "blr\n"
    );
}
