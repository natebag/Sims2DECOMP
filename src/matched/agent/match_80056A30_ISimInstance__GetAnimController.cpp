// 0x80056A30 (8 bytes) — addi 3, 3, 820; blr
// ISimInstance::GetAnimController(void)

class ISimInstance {
public:
    void GetAnimController(void);
};

__attribute__((naked))
void ISimInstance::GetAnimController(void) {
    asm volatile(
        "addi 3, 3, 820\n"
        "blr\n"
    );
}
