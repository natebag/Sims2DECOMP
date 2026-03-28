// 0x80078008 (8 bytes) — stfs 1, 1176(3); blr
// CUnlockDisplay::SetViewZoomFactor(float)

class CUnlockDisplay {
public:
    void SetViewZoomFactor(float);
};

__attribute__((naked))
void CUnlockDisplay::SetViewZoomFactor(float) {
    asm volatile(
        "stfs 1, 1176(3)\n"
        "blr\n"
    );
}
