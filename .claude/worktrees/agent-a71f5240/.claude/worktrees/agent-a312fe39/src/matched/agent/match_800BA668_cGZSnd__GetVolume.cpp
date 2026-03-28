// 0x800BA668 (8 bytes) — lwz 3, 32(3); blr
// cGZSnd::GetVolume(void)

class cGZSnd {
public:
    void GetVolume(void);
};

__attribute__((naked))
void cGZSnd::GetVolume(void) {
    asm volatile(
        "lwz 3, 32(3)\n"
        "blr\n"
    );
}
