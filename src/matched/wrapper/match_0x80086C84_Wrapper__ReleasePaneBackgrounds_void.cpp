// 0x80086C84 Wrapper::ReleasePaneBackgrounds(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 9,3,140; lwz 31,0x8c(3); lwz 0,0x4(9); cmpw 31,0; beq 1f; mr 30,9; 0:; lwz 3,0x0(31); addi 31,31,4; bl _s80086C84_0; lwz 0,0x4(30); cmpw 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80086C84_0();

struct Wrapper {
    void ReleasePaneBackgrounds();
};

void Wrapper::ReleasePaneBackgrounds() {
}
