// 0x800D6204 NghResFile::XBoxReadFromMemoryBlock(void (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32696; mr 30,4; addi 31,9,25388; mr 29,3; lwz 9,0x4(31); li 5,0; lwz 4,0x38(9); add 4,30,4; bl _s800D6204_0; cmpwi 3,1; bne 0f; lwz 9,0x4(31); mr 3,29; li 5,0; lwz 4,0x50(9); add 4,30,4; bl _s800D6204_1; cmpwi 3,1; bne 0f; lwz 9,0x4(31); mr 3,29; li 5,0; lwz 4,0x68(9); add 4,30,4; bl _s800D6204_2; cmpwi 3,1; beq 1f; 0:; li 3,0; b 3f; 1:; mr 28,31; li 11,0; 2:; lwz 9,0x4(28); addi 31,11,1; mr 3,29; mr 4,31; addi 9,9,120; li 6,0; lwz 0,0x4(9); lwz 5,0x8(9); mullw 0,11,0; add 5,30,5; add 5,5,0; bl _s800D6204_3; cmpwi 3,1; bne 0b; mr 11,31; cmpwi 11,15; ble 2b; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800D6204_0();
extern "C" void _s800D6204_1();
extern "C" void _s800D6204_2();
extern "C" void _s800D6204_3();

struct NghResFile {
    void XBoxReadFromMemoryBlock();
};

void NghResFile::XBoxReadFromMemoryBlock() {
}
