// 0x800BAEBC (8 bytes) — lwz 3, 20(3); blr
// cGZMusic::GetVolume(void)

class cGZMusic {
public:
    void GetVolume(void);
};

__attribute__((naked))
void cGZMusic::GetVolume(void) {
    asm volatile(
        "lwz 3, 20(3)
"
        "blr
"
    );
}
