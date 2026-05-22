// 0x8029E150 AptAnimationPoolData::ProcessAptInput(unsigned (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,4; mr 8,5; li 0,0; mr 31,3; rlwinm 28,30,15,17,31; rlwinm 27,30,22,25,31; rlwinm 29,30,30,24,31; stw 0,0x8(1); mr 4,28; mr 5,27; mr 6,30; mr 7,29; bl _s8029E150_0; mr 6,30; mr 7,29; mr 3,31; mr 4,28; mr 5,27; bl _s8029E150_1; mr 3,31; mr 4,28; mr 5,27; addi 6,1,8; bl _s8029E150_2; cmpwi 3,0; bne 0f; lwz 4,0x8(1); mr 3,31; mr 5,28; mr 6,27; bl _s8029E150_3; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8029E150_0();
extern "C" void _s8029E150_1();
extern "C" void _s8029E150_2();
extern "C" void _s8029E150_3();
extern "C" void f_8029E150() {}
