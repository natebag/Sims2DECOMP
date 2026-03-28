// 0x800878BC (8 bytes) — lwz 3, 48(3); blr
// IconItem::GetShader(void)

class IconItem {
public:
    void GetShader(void);
};

__attribute__((naked))
void IconItem::GetShader(void) {
    asm volatile(
        "lwz 3, 48(3)
"
        "blr
"
    );
}
