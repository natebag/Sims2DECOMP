// 0x8025FCC4 cbForCancelAllSync (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; addi 3,13,-23488; stw 0,0x4(1); li 0,1; stwu 1,-8(1); stw 0,-23420(13); bl _s8025FCC4_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025FCC4_0();
extern "C" void f_8025FCC4() {}
