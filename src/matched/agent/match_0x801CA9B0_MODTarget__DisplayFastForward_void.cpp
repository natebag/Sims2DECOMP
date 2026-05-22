// 0x801CA9B0 MODTarget::DisplayFastForward(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x94(31); cmpwi 0,0; bne 0f; lis 4,-32705; addi 3,31,200; addi 4,4,12648; li 5,1; li 6,0; bl _s801CA9B0_0; li 0,6; stw 0,0xe4(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801CA9B0_0();
extern "C" void f_801CA9B0() {}
