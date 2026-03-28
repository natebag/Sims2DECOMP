// 0x80005D2C (20 bytes)
// li r0, 1; stw r5, 0x4A4(r3); stw r0, 0x49C(r3); stw r4, 0x4A0(r3); blr

class ESimsApp {
public:
    void TakeBigScreenshot(int width, int height);
};

__attribute__((naked))
void ESimsApp::TakeBigScreenshot(int width, int height) {
    asm volatile(
        "li 0, 1\n"
        "stw 5, 0x4A4(3)\n"
        "stw 0, 0x49C(3)\n"
        "stw 4, 0x4A0(3)\n"
        "blr\n"
    );
}
