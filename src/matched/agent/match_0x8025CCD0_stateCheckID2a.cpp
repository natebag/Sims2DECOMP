// 0x8025CCD0 stateCheckID2a (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32730; stw 0,0x4(1); addi 5,3,-13052; stwu 1,-8(1); lwz 4,-23476(13); lbz 3,0x8(4); li 4,10; bl _s8025CCD0_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025CCD0_0();
extern "C" void f_8025CCD0() {}
