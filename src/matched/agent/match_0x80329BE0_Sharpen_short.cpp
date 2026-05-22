// 0x80329BE0 Sharpen(short (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 28,3; mr 25,4; lis 29,-32700; mr 30,7; mr 27,5; mr 26,6; li 4,9; addi 3,29,-4580; bl _s80329BE0_0; lhz 0,0x0(30); addi 9,1,16; lbz 11,0x2(30); mr 8,3; sth 0,0x10(1); mr 3,28; stb 11,0x2(9); mr 4,25; stw 9,0x8(1); mr 5,27; mr 6,26; addi 7,29,-4580; li 9,3; li 10,3; bl _s80329BE0_1; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s80329BE0_0();
extern "C" void _s80329BE0_1();
extern "C" void f_80329BE0() {}
