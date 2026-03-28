// 0x800187E8 (60 bytes) — Copy 6 words from target params to actual params

class ESimsCam {
public:
    void SnapActualCameraParamsToTarget();
};

__attribute__((naked))
void ESimsCam::SnapActualCameraParamsToTarget() {
    asm volatile(
        "lwz 7, 0x43C(3)\n"
        "addi 9, 3, 0x43C\n"
        "lwz 0, 8(9)\n"
        "addi 11, 3, 0x454\n"
        "lwz 10, 12(9)\n"
        "lwz 8, 4(9)\n"
        "stw 7, 0x454(3)\n"
        "stw 8, 4(11)\n"
        "stw 0, 8(11)\n"
        "stw 10, 12(11)\n"
        "lwz 0, 20(9)\n"
        "lwz 10, 16(9)\n"
        "stw 0, 20(11)\n"
        "stw 10, 16(11)\n"
        "blr\n"
    );
}
