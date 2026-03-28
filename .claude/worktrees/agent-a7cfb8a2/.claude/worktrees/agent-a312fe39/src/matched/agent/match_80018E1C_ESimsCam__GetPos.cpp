// 0x80018E1C (88 bytes) — Copies three EVec3s from struct to output params
// ESimsCam::GetPos(EVec3 &, EVec3 &, EVec3 &)

struct EVec3 { float x, y, z; };

class ESimsCam {
public:
    void GetPos(EVec3& eye, EVec3& target, EVec3& up);
};

__attribute__((naked))
void ESimsCam::GetPos(EVec3& eye, EVec3& target, EVec3& up) {
    asm volatile(
        "addi 9, 3, 0x418\n"
        "lwz 8, 0x418(3)\n"
        "lwz 0, 8(9)\n"
        "addi 10, 3, 0x43C\n"
        "lwz 11, 4(9)\n"
        "addi 7, 3, 0x424\n"
        "stw 0, 8(4)\n"
        "stw 8, 0(4)\n"
        "stw 11, 4(4)\n"
        "lwz 0, 8(10)\n"
        "lwz 9, 0x43C(3)\n"
        "lwz 11, 4(10)\n"
        "stw 0, 8(5)\n"
        "stw 9, 0(5)\n"
        "stw 11, 4(5)\n"
        "lwz 10, 0x424(3)\n"
        "lwz 0, 8(7)\n"
        "lwz 9, 4(7)\n"
        "stw 0, 8(6)\n"
        "stw 10, 0(6)\n"
        "stw 9, 4(6)\n"
        "blr\n"
    );
}
