// 0x8006EBCC (8 bytes) — stw 4, 136(3); blr
// SimImageMaker::SetGender(bool)

class SimImageMaker {
public:
    void SetGender(bool);
};

__attribute__((naked))
void SimImageMaker::SetGender(bool) {
    asm volatile(
        "stw 4, 136(3)\n"
        "blr\n"
    );
}
