// 0x800871FC (8 bytes) — lfs 1, 36(3); blr
// TextBaseItem::GetPosX(void)

class TextBaseItem {
public:
    void GetPosX(void);
};

__attribute__((naked))
void TextBaseItem::GetPosX(void) {
    asm volatile(
        "lfs 1, 36(3)\n"
        "blr\n"
    );
}
