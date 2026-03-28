// 0x800878A4 (8 bytes) — stfs 1, 44(3); blr
// IconItem::SetAlpha(float)

class IconItem {
public:
    void SetAlpha(float);
};

__attribute__((naked))
void IconItem::SetAlpha(float) {
    asm volatile(
        "stfs 1, 44(3)
"
        "blr
"
    );
}
