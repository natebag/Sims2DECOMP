// 0x800578A4 (8 bytes) — lwz 3, 852(3); blr
// CLoadingScreen::GetMode(void) const

class CLoadingScreen {
public:
    void GetMode(void) const;
};

__attribute__((naked))
void CLoadingScreen::GetMode(void) const {
    asm volatile(
        "lwz 3, 852(3)
"
        "blr
"
    );
}
