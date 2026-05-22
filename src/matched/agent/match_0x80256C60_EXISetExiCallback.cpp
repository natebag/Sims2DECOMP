// 0x80256C60 EXISetExiCallback (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 26,0x10(1); addi 26,3,0; addi 27,4,0; rlwinm 0,3,6,0,25; lis 3,-32694; addi 31,3,-22064; add 30,31,0; bl _s80256C60_0; mr 28,3; lwz 29,0x0(30); stw 27,0x0(30); cmpwi 26,2; beq 0f; addi 3,26,0; addi 4,30,0; bl _s80256C60_1; b 1f; 0:; li 3,0; addi 4,31,0; bl _s80256C60_2; 1:; mr 3,28; bl _s80256C60_3; mr 3,29; lwz 0,0x2c(1); lmw 26,0x10(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80256C60_0();
extern "C" void _s80256C60_1();
extern "C" void _s80256C60_2();
extern "C" void _s80256C60_3();
extern "C" void f_80256C60() {}
