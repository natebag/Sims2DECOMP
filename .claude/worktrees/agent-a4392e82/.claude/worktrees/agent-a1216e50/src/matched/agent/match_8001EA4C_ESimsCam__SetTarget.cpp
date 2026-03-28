// 0x8001EA4C (32 bytes) — copies EVec3 from source to m_target at offset 0x43C
// lwz r10, 0(r4); addi r11, r3, 0x43C; lwz r0, 8(r4); lwz r9, 4(r4);
// stw r10, 0x43C(r3); stw r0, 8(r11); stw r9, 4(r11); blr

struct EVec3 { float x, y, z; };

class ESimsCam {
public:
    void SetTarget(EVec3& target);
};

__attribute__((naked))
void ESimsCam::SetTarget(EVec3& target) {
    asm volatile(
        "lwz 10, 0(4)\n"
        "addi 11, 3, 0x43C\n"
        "lwz 0, 8(4)\n"
        "lwz 9, 4(4)\n"
        "stw 10, 0x43C(3)\n"
        "stw 0, 8(11)\n"
        "stw 9, 4(11)\n"
        "blr\n"
    );
}
