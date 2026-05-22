// 0x8025B5A0 DVDClose (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8025B5A0_0; li 3,1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025B5A0_0();
extern "C" void f_8025B5A0() {}
