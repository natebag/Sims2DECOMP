// 0x800D3F84 NghResFile::FlushHouseData(unsigned (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); addi 4,4,-1; addi 28,3,316; rlwinm 30,4,2,0,29; li 27,0; li 31,0; li 29,6; 0:; lwzx 9,28,30; lwzx 3,31,9; bl _s800D3F84_0; lwzx 9,28,30; addic. 29,29,-1; stwx 27,31,9; addi 31,31,4; bne 0b; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800D3F84_0();

struct NghResFile {
    void FlushHouseData();
};

void NghResFile::FlushHouseData() {
}
