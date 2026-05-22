// 0x80151DA4 cFixedWorldImpl::GetRoom(CTilePt (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x30(30); li 3,0; cmpwi 0,0; beq 2f; mr 3,31; bl _s80151DA4_0; cmpwi 3,0; blt 0f; mr 3,31; bl _s80151DA4_1; lwz 9,0x30(30); lwz 0,0x8(9); cmpw 3,0; bge 0f; mr 3,31; bl _s80151DA4_2; cmpwi 3,0; blt 0f; mr 3,31; bl _s80151DA4_3; lwz 29,0x30(30); lwz 0,0x4(29); cmpw 3,0; blt 1f; 0:; li 3,0; b 2f; 1:; mr 3,31; bl _s80151DA4_4; mr 30,3; mr 3,31; bl _s80151DA4_5; lwz 11,0xc(29); rlwinm 30,30,2,0,29; rlwinm 3,3,1,0,30; lwzx 9,30,11; lhzx 3,9,3; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80151DA4_0();
extern "C" void _s80151DA4_1();
extern "C" void _s80151DA4_2();
extern "C" void _s80151DA4_3();
extern "C" void _s80151DA4_4();
extern "C" void _s80151DA4_5();
extern "C" void f_80151DA4() {}
