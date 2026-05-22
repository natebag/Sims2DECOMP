// 0x80383C78 CreateCallbackFat (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); addi 28,3,0; lis 3,-32688; mulli 5,28,272; addi 0,3,-24000; add 31,0,5; lwz 29,0xd0(31); li 27,0; mr. 30,4; stw 27,0xd0(31); blt 0f; mr 3,31; bl _s80383C78_0; lhz 0,0xbc(31); li 5,4; lwz 4,0x10c(31); rlwinm 0,0,6,0,25; add 30,3,0; addi 3,30,0; bl _s80383C78_1; lwz 4,0x10c(31); addi 3,30,4; li 5,2; addi 4,4,4; bl _s80383C78_2; li 0,4; stb 0,0x34(30); li 0,-1; lis 3,-32768; stb 27,0x35(30); lhz 4,0xbe(31); sth 4,0x36(30); stb 27,0x7(30); stw 0,0x2c(30); sth 27,0x30(30); sth 27,0x32(30); stw 0,0x3c(30); lhz 0,0x32(30); rlwinm 0,0,0,0,29; ori 0,0,1; sth 0,0x32(30); lwz 4,0xc0(31); stw 27,0x8(4); lhz 0,0x36(30); lwz 4,0xc0(31); sth 0,0x10(4); lwz 0,0xf8(3); rlwinm 27,0,30,2,31; bl _s80383C78_3; addi 6,27,0; li 5,0; bl _s80383C78_4; stw 4,0x28(30); addi 3,28,0; addi 4,29,0; bl _s80383C78_5; mr. 30,3; bge 1f; 0:; addi 3,31,0; addi 4,30,0; bl _s80383C78_6; cmplwi 29,0; beq 1f; addi 12,29,0; mtspr 8,12; addi 3,28,0; addi 4,30,0; blrl; 1:; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80383C78_0();
extern "C" void _s80383C78_1();
extern "C" void _s80383C78_2();
extern "C" void _s80383C78_3();
extern "C" void _s80383C78_4();
extern "C" void _s80383C78_5();
extern "C" void _s80383C78_6();
extern "C" void f_80383C78() {}
