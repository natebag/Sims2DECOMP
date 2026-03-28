// 0x8008720C (8 bytes) — lfs 1, 40(3); blr
// TextBaseItem::GetPosY(void)

class TextBaseItem {
public:
    void GetPosY(void);
};

__attribute__((naked))
void TextBaseItem::GetPosY(void) {
    asm volatile(
        "lfs 1, 40(3)\n"
        "blr\n"
    );
}
