// 0x8009E74C BString::replace(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 31,4; mr 29,5; mr 28,6; mr 27,7; bl _s8009E74C_0; subf 3,31,3; cmplw 29,3; ble 0f; mr 3,30; bl _s8009E74C_1; subf 4,31,3; b 1f; 0:; mr 4,29; 1:; mr 3,30; mr 5,31; mr 6,28; mr 7,27; bl _s8009E74C_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009E74C_0();
extern "C" void _s8009E74C_1();
extern "C" void _s8009E74C_2();
extern "C" void f_8009E74C() {}
