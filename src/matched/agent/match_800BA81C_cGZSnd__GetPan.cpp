// 0x800BA81C (8 bytes) — lwz 3, 36(3); blr
// cGZSnd::GetPan(void)

class cGZSnd {
public:
    void GetPan(void);
};

__attribute__((naked))
void cGZSnd::GetPan(void) {
    asm volatile(
        "lwz 3, 36(3)\n"
        "blr\n"
    );
}
