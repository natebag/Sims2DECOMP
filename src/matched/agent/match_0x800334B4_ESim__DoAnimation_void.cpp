// 0x800334B4 ESim::DoAnimation(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s800334B4_0; cmpwi 3,0; bne 0f; lwz 5,-26812(13); addi 4,31,192; addi 3,31,820; bl _s800334B4_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800334B4_0();
extern "C" void _s800334B4_1();
extern "C" void f_800334B4() {}
