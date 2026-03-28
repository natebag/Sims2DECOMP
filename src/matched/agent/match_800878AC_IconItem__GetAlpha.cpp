// 0x800878AC (8 bytes) — lfs 1, 44(3); blr
// IconItem::GetAlpha(void)

class IconItem {
public:
    void GetAlpha(void);
};

__attribute__((naked))
void IconItem::GetAlpha(void) {
    asm volatile(
        "lfs 1, 44(3)
"
        "blr
"
    );
}
