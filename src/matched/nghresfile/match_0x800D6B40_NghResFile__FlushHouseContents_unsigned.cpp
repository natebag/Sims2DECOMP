// 0x800D6B40 NghResFile::FlushHouseContents(unsigned (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); addi 30,4,-1; addi 29,3,316; rlwinm 30,30,2,0,29; li 28,0; lwzx 9,29,30; lwz 3,0x8(9); bl _s800D6B40_0; lwzx 9,29,30; stw 28,0x8(9); lwzx 11,29,30; lwz 3,0xc(11); bl _s800D6B40_1; lwzx 9,29,30; stw 28,0xc(9); lwzx 11,29,30; lwz 3,0x10(11); bl _s800D6B40_2; lwzx 9,29,30; stw 28,0x10(9); lwzx 11,29,30; lwz 3,0x14(11); bl _s800D6B40_3; lwzx 9,29,30; stw 28,0x14(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800D6B40_0();
extern "C" void _s800D6B40_1();
extern "C" void _s800D6B40_2();
extern "C" void _s800D6B40_3();

struct NghResFile {
    void FlushHouseContents();
};

void NghResFile::FlushHouseContents() {
}
