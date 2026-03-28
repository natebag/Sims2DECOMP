// 0x8003FA1C (8 bytes) — lwz 3, 208(3); blr
// EGlobal::GetCam(void)

class EGlobal {
public:
    void GetCam(void);
};

__attribute__((naked))
void EGlobal::GetCam(void) {
    asm volatile(
        "lwz 3, 208(3)
"
        "blr
"
    );
}
