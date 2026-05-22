// 0x80248C64 __swrite (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lhz 0,0xc(31); mr 29,5; andi. 9,0,256; beq 0f; lwz 3,0x5c(31); li 5,0; lha 4,0xe(31); li 6,2; bl _s80248C64_0; 0:; lhz 0,0xc(31); mr 5,30; lha 4,0xe(31); mr 6,29; rlwinm 0,0,0,20,18; lwz 3,0x5c(31); sth 0,0xc(31); bl _s80248C64_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80248C64_0();
extern "C" void _s80248C64_1();
extern "C" void f_80248C64() {}
