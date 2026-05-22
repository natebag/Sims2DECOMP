// 0x80151D18 cFixedWorldImpl::SetFloor(CTilePt (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 28,4; mr 27,3; mr 26,5; lwz 29,0x2c(27); mr 3,28; bl _s80151D18_0; mr 30,3; mr 3,28; bl _s80151D18_1; lwz 9,0xc(29); rlwinm 30,30,2,0,29; lwzx 0,30,9; lbzx 31,3,0; cmpw 31,26; beq 0f; lwz 29,0x2c(27); mr 3,28; bl _s80151D18_2; mr 30,3; mr 3,28; bl _s80151D18_3; lwz 9,0xc(29); rlwinm 30,30,2,0,29; lwzx 0,30,9; stbx 26,3,0; 0:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80151D18_0();
extern "C" void _s80151D18_1();
extern "C" void _s80151D18_2();
extern "C" void _s80151D18_3();
extern "C" void f_80151D18() {}
