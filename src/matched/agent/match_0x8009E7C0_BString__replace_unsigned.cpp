// 0x8009E7C0 BString::replace(unsigned (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; mr 29,4; mr 30,5; mr 31,6; bl _s8009E7C0_0; subf 3,29,3; cmplw 30,3; ble 0f; mr 3,28; bl _s8009E7C0_1; subf 30,29,3; 0:; cmpwi 31,0; beq 1f; mr 3,31; bl _s8009E7C0_2; b 2f; 1:; li 3,0; 2:; mr 7,3; mr 4,30; mr 3,28; mr 5,29; mr 6,31; bl _s8009E7C0_3; mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009E7C0_0();
extern "C" void _s8009E7C0_1();
extern "C" void _s8009E7C0_2();
extern "C" void _s8009E7C0_3();
extern "C" void f_8009E7C0() {}
