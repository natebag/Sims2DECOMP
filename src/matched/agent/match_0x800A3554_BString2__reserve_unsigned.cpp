// 0x800A3554 BString2::reserve(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 31,3; cmpwi 29,-1; bne 0f; bl _s800A3554_0; 0:; mr 3,31; addi 30,29,1; bl _s800A3554_1; cmplw 30,3; ble 3f; bl _s800A3554_2; li 4,16; li 5,0; bl _s800A3554_3; mr 28,3; mr 3,31; bl _s800A3554_4; cmpwi 3,0; beq 1f; lwz 9,0x0(31); lwz 30,0x0(9); b 2f; 1:; li 30,0; 2:; mr 3,31; bl _s800A3554_5; mr 5,3; mr 4,30; mr 6,29; mr 3,28; bl _s800A3554_6; mr 30,3; mr 3,31; bl _s800A3554_7; stw 30,0x0(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800A3554_0();
extern "C" void _s800A3554_1();
extern "C" void _s800A3554_2();
extern "C" void _s800A3554_3();
extern "C" void _s800A3554_4();
extern "C" void _s800A3554_5();
extern "C" void _s800A3554_6();
extern "C" void _s800A3554_7();
extern "C" void f_800A3554() {}
