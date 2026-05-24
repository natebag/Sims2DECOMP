// 0x800D60A0 NghResFile::WriteToMemoryBlock(void (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 25,4; mr 24,5; mr 28,3; bl _s800D60A0_0; mr 30,3; bl _s800D60A0_1; mr 4,3; li 5,0; mr 3,30; bl _s800D60A0_2; mr 29,3; bl _s800D60A0_3; mr 5,3; li 4,0; mr 3,29; bl _s800D60A0_4; lis 11,-32696; mr 3,28; addi 31,11,25388; lwz 9,0x4(31); lwz 4,0x38(9); add 4,29,4; bl _s800D60A0_5; cmpwi 3,1; bne 0f; lwz 9,0x4(31); mr 3,28; lwz 4,0x50(9); add 4,29,4; bl _s800D60A0_6; cmpwi 3,1; bne 0f; lwz 9,0x4(31); mr 3,28; lwz 4,0x68(9); add 4,29,4; bl _s800D60A0_7; cmpwi 3,1; beq 1f; 0:; bl _s800D60A0_8; mr 4,29; bl _s800D60A0_9; li 3,0; b 4f; 1:; lwz 9,0x24(28); mr 26,31; li 31,0; addi 27,9,1; 2:; addi 30,31,1; mr 3,28; mr 4,30; li 5,0; li 6,0; bl _s800D60A0_10; cmpwi 3,1; bne 0b; lwz 9,0x4(26); mr 3,28; mr 4,30; addi 9,9,120; lwz 0,0x4(9); lwz 5,0x8(9); mullw 0,31,0; add 5,29,5; add 5,5,0; bl _s800D60A0_11; cmpwi 3,1; bne 0b; cmpw 30,27; beq 3f; mr 3,28; mr 4,30; bl _s800D60A0_12; 3:; mr 31,30; cmpwi 31,15; ble 2b; stw 29,0x0(25); bl _s800D60A0_13; stw 3,0x0(24); li 3,1; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s800D60A0_0();
extern "C" void _s800D60A0_1();
extern "C" void _s800D60A0_2();
extern "C" void _s800D60A0_3();
extern "C" void _s800D60A0_4();
extern "C" void _s800D60A0_5();
extern "C" void _s800D60A0_6();
extern "C" void _s800D60A0_7();
extern "C" void _s800D60A0_8();
extern "C" void _s800D60A0_9();
extern "C" void _s800D60A0_10();
extern "C" void _s800D60A0_11();
extern "C" void _s800D60A0_12();
extern "C" void _s800D60A0_13();

struct NghResFile {
    void WriteToMemoryBlock();
};

void NghResFile::WriteToMemoryBlock() {
}
