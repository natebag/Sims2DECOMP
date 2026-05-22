// 0x800A4870 BString2::assignDebug(char (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 3,30; cmpwi 3,0; bne 0f; lis 9,-32706; addi 3,9,-28612; 0:; mr 30,3; bl _s800A4870_0; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s800A4870_1; mr 31,3; mr 4,30; bl _s800A4870_2; mr 3,29; mr 4,31; bl _s800A4870_3; cmpwi 31,0; beq 1f; mr 3,31; bl _s800A4870_4; 1:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800A4870_0();
extern "C" void _s800A4870_1();
extern "C" void _s800A4870_2();
extern "C" void _s800A4870_3();
extern "C" void _s800A4870_4();
extern "C" void f_800A4870() {}
