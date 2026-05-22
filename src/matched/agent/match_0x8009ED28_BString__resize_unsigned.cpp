// 0x8009ED28 BString::resize(unsigned (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,4; mr 31,3; stb 5,0x8(1); cmpwi 29,-1; bne 0f; bl _s8009ED28_0; 0:; mr 3,31; bl _s8009ED28_1; cmplwi 3,1; bgt 1f; mr 3,31; addi 30,29,1; bl _s8009ED28_2; cmplw 30,3; ble 4f; 1:; bl _s8009ED28_3; li 4,16; li 5,0; bl _s8009ED28_4; mr 28,3; mr 3,31; bl _s8009ED28_5; mr 30,3; mr 3,31; bl _s8009ED28_6; cmplw 29,3; ble 2f; mr 3,31; bl _s8009ED28_7; b 3f; 2:; mr 3,29; 3:; mr 5,3; mr 4,30; mr 6,29; mr 3,28; bl _s8009ED28_8; mr 30,3; mr 3,31; bl _s8009ED28_9; stw 30,0x0(31); 4:; lwz 9,0x0(31); lwz 0,0x4(9); cmplw 0,29; bge 6f; 5:; mr 3,31; bl _s8009ED28_10; lwz 9,0x0(31); lbz 11,0x8(1); lwz 0,0x0(9); stbx 11,3,0; lwz 10,0x0(31); lwz 9,0x4(10); addi 9,9,1; stw 9,0x4(10); lwz 11,0x0(31); lwz 0,0x4(11); cmplw 0,29; blt 5b; 6:; lwz 9,0x0(31); mr 3,31; stw 29,0x4(9); bl _s8009ED28_11; mr 29,3; lwz 30,0x0(31); bl _s8009ED28_12; lwz 9,0x0(30); stbx 3,9,29; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8009ED28_0();
extern "C" void _s8009ED28_1();
extern "C" void _s8009ED28_2();
extern "C" void _s8009ED28_3();
extern "C" void _s8009ED28_4();
extern "C" void _s8009ED28_5();
extern "C" void _s8009ED28_6();
extern "C" void _s8009ED28_7();
extern "C" void _s8009ED28_8();
extern "C" void _s8009ED28_9();
extern "C" void _s8009ED28_10();
extern "C" void _s8009ED28_11();
extern "C" void _s8009ED28_12();
extern "C" void f_8009ED28() {}
