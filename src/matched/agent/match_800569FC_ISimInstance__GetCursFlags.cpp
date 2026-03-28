// 0x800569FC (8 bytes) — lwz 3, 812(3); blr
// ISimInstance::GetCursFlags(void)

class ISimInstance {
public:
    void GetCursFlags(void);
};

__attribute__((naked))
void ISimInstance::GetCursFlags(void) {
    asm volatile(
        "lwz 3, 812(3)
"
        "blr
"
    );
}
