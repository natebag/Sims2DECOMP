// 0x8001C830 (16 bytes) — li r0, 2; stfs f1, 0x168(r3); stw r0, 0x160(r3); blr

class CameraDirector {
public:
    void SetHoldState(float duration);
};

__attribute__((naked))
void CameraDirector::SetHoldState(float duration) {
    asm volatile(
        "li 0, 2\n"
        "stfs 1, 0x168(3)\n"
        "stw 0, 0x160(3)\n"
        "blr\n"
    );
}
