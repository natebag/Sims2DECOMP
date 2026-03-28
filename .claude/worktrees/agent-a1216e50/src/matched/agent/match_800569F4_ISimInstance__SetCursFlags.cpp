// 0x800569F4 (8 bytes) — stw 4, 812(3); blr
// ISimInstance::SetCursFlags(unsigned int)

class ISimInstance {
public:
    void SetCursFlags(unsigned int);
};

__attribute__((naked))
void ISimInstance::SetCursFlags(unsigned int) {
    asm volatile(
        "stw 4, 812(3)\n"
        "blr\n"
    );
}
