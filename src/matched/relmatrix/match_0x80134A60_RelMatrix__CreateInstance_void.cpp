// 0x80134A60 RelMatrix::CreateInstance(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); li 3,20; bl _s80134A60_0; lis 9,-32698; mr 11,3; li 0,0; addi 9,9,17112; stw 9,0x0(11); addi 10,11,12; stw 0,0x4(11); stw 0,0x8(11); stw 0,0x4(10); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

extern "C" void _s80134A60_0();

struct RelMatrix {
    void CreateInstance();
};

void RelMatrix::CreateInstance() {
}
