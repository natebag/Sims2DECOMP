// 0x800D255C GetConfigFromMemoryCardCache(char (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; lwz 3,-32056(13); mr 29,5; bl _s800D255C_0; mr 4,30; mr 5,28; mr 6,29; bl _s800D255C_1; subfic 0,3,0; adde 3,0,3; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800D255C_0();
extern "C" void _s800D255C_1();
extern "C" void f_800D255C() {}
