// 0x80110064 ObjFnTableQuickData::Load(unsigned (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,-21508(13); mr 30,3; mr 29,4; mr 28,5; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 5,28; mr 3,30; bl _s80110064_0; mr. 31,3; bne 0f; addi 30,30,4; mr 4,29; mr 3,30; bl _s80110064_1; mr 3,30; rlwinm 4,28,0,16,31; bl _s80110064_2; 0:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80110064_0();
extern "C" void _s80110064_1();
extern "C" void _s80110064_2();
extern "C" void f_80110064() {}
