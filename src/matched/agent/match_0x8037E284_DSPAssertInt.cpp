// 0x8037E284 DSPAssertInt (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8037E284_0; lis 4,-13312; addi 4,4,20480; lhz 5,0xa(4); li 0,-169; and 0,5,0; ori 0,0,2; sth 0,0xa(4); bl _s8037E284_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8037E284_0();
extern "C" void _s8037E284_1();
extern "C" void f_8037E284() {}
