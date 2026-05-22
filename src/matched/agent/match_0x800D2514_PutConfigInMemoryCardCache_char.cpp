// 0x800D2514 PutConfigInMemoryCardCache(char (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; lwz 3,-32056(13); bl _s800D2514_0; mr 4,30; mr 5,29; bl _s800D2514_1; subfic 0,3,0; adde 3,0,3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800D2514_0();
extern "C" void _s800D2514_1();
extern "C" void f_800D2514() {}
