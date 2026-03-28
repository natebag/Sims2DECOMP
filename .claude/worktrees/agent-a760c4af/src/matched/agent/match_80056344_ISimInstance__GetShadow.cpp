// 0x80056344 (8 bytes) — li 3, 0; blr
// ISimInstance::GetShadow(void)

class ISimInstance {
public:
    void GetShadow(void);
};

__attribute__((naked))
void ISimInstance::GetShadow(void) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
