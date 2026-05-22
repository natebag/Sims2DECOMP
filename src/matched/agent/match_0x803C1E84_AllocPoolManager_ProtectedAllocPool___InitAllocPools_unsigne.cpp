// 0x803C1E84 AllocPoolManager<ProtectedAllocPool>::InitAllocPools(unsigned (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 0,0x0(31); cmpwi 0,0; bne 1f; li 0,8; li 29,0; mtspr 9,0; li 11,1; mr 9,30; 0:; lwz 0,0x0(9); addi 9,9,4; rlwinm 0,0,3,0,28; mullw 0,0,11; addi 11,11,1; add 29,29,0; bdnz 0b; bl _s803C1E84_0; li 7,0; mr 4,29; li 5,64; li 6,0; bl _s803C1E84_1; mr 6,3; stw 3,0x0(31); li 4,7; mr 5,30; mr 3,31; bl _s803C1E84_2; mr 6,3; li 4,3; mr 5,30; mr 3,31; bl _s803C1E84_3; mr 6,3; li 4,5; mr 5,30; mr 3,31; bl _s803C1E84_4; mr 6,3; li 4,1; mr 5,30; mr 3,31; bl _s803C1E84_5; mr 6,3; li 4,0; mr 5,30; mr 3,31; bl _s803C1E84_6; mr 6,3; li 4,2; mr 5,30; mr 3,31; bl _s803C1E84_7; mr 6,3; li 4,4; mr 5,30; mr 3,31; bl _s803C1E84_8; mr 6,3; mr 5,30; mr 3,31; li 4,6; bl _s803C1E84_9; stw 3,0x4(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803C1E84_0();
extern "C" void _s803C1E84_1();
extern "C" void _s803C1E84_2();
extern "C" void _s803C1E84_3();
extern "C" void _s803C1E84_4();
extern "C" void _s803C1E84_5();
extern "C" void _s803C1E84_6();
extern "C" void _s803C1E84_7();
extern "C" void _s803C1E84_8();
extern "C" void _s803C1E84_9();
extern "C" void f_803C1E84() {}
