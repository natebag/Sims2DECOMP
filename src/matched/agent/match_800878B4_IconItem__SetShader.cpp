// 0x800878B4 (8 bytes) — stw 4, 48(3); blr
// IconItem::SetShader(ERShader *)

class IconItem {
public:
    void SetShader(ERShader *);
};

__attribute__((naked))
void IconItem::SetShader(ERShader *) {
    asm volatile(
        "stw 4, 48(3)
"
        "blr
"
    );
}
