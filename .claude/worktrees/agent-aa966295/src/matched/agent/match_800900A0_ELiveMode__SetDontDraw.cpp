// 0x800900A0 (8 bytes) — stw 4, 52(3); blr
// ELiveMode::SetDontDraw(bool)

class ELiveMode {
public:
    void SetDontDraw(bool);
};

__attribute__((naked))
void ELiveMode::SetDontDraw(bool) {
    asm volatile(
        "stw 4, 52(3)\n"
        "blr\n"
    );
}
