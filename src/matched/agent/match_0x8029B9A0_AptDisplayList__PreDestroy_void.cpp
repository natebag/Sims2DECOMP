// 0x8029B9A0 AptDisplayList::PreDestroy(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 4,0; bl _s8029B9A0_0; lwz 3,0x0(31); cmpwi 3,0; beq 0f; li 4,3; bl _s8029B9A0_1; 0:; li 0,0; stw 0,0x0(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8029B9A0_0();
extern "C" void _s8029B9A0_1();
extern "C" void f_8029B9A0() {}
