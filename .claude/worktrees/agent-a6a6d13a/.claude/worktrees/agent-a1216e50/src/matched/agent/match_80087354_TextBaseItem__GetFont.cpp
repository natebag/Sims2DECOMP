// 0x80087354 (8 bytes) — lwz 3, 80(3); blr
// TextBaseItem::GetFont(void) const

class TextBaseItem {
public:
    void GetFont(void) const;
};

__attribute__((naked))
void TextBaseItem::GetFont(void) const {
    asm volatile(
        "lwz 3, 80(3)\n"
        "blr\n"
    );
}
