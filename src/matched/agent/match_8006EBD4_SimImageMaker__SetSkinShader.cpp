// 0x8006EBD4 (8 bytes) — stw 4, 140(3); blr
// SimImageMaker::SetSkinShader(EShader *)

class SimImageMaker {
public:
    void SetSkinShader(EShader *);
};

__attribute__((naked))
void SimImageMaker::SetSkinShader(EShader *) {
    asm volatile(
        "stw 4, 140(3)
"
        "blr
"
    );
}
