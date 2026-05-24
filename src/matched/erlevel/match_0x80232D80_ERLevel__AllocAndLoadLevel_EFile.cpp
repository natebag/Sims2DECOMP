// 0x80232D80 ERLevel::AllocAndLoadLevel(EFile (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; addi 4,1,8; lwz 9,0x28(30); li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; addi 4,1,12; mr 3,30; bl _s80232D80_0; lwz 9,0x28(30); addi 4,1,16; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; lwz 3,0xc(1); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"

extern "C" void _s80232D80_0();

struct ERLevel {
    void AllocAndLoadLevel_EFile();
};

void ERLevel::AllocAndLoadLevel_EFile() {
}
