// 0x8015228C CreateTheWorld(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,68; bl _s8015228C_0; li 4,39; li 5,39; bl _s8015228C_1; stw 3,-21488(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8015228C_0();
extern "C" void _s8015228C_1();
extern "C" void f_8015228C() {}
