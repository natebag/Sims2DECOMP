// 0x800160B8 (88 bytes) — Copies three EVec3s into struct at offsets 0x8, 0x14, 0x20
// CameraMotionSystem::SetRig(EVec3 &, EVec3 &, EVec3 &)

struct EVec3 { float x, y, z; };

class CameraMotionSystem {
public:
    void SetRig(EVec3& eye, EVec3& target, EVec3& up);
};

__attribute__((naked))
void CameraMotionSystem::SetRig(EVec3& eye, EVec3& target, EVec3& up) {
    asm volatile(
        "lwz 0, 0(4)\n"
        "addi 9, 3, 8\n"
        "lwz 11, 8(4)\n"
        "addi 8, 3, 20\n"
        "lwz 10, 4(4)\n"
        "addi 7, 3, 32\n"
        "stw 0, 8(3)\n"
        "stw 11, 8(9)\n"
        "stw 10, 4(9)\n"
        "lwz 0, 0(5)\n"
        "lwz 9, 8(5)\n"
        "lwz 11, 4(5)\n"
        "stw 0, 20(3)\n"
        "stw 9, 8(8)\n"
        "stw 11, 4(8)\n"
        "lwz 0, 0(6)\n"
        "lwz 9, 8(6)\n"
        "lwz 11, 4(6)\n"
        "stw 0, 32(3)\n"
        "stw 9, 8(7)\n"
        "stw 11, 4(7)\n"
        "blr\n"
    );
}
