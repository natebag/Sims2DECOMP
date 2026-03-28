// 0x8008729C (8 bytes) — addi 3, 3, 52; blr
// TextBaseItem::GetDisplayPadSize(void)

class TextBaseItem {
public:
    void GetDisplayPadSize(void);
};

__attribute__((naked))
void TextBaseItem::GetDisplayPadSize(void) {
    asm volatile(
        "addi 3, 3, 52\n"
        "blr\n"
    );
}
