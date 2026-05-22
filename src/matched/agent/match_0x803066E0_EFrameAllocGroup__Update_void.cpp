// 0x803066E0 EFrameAllocGroup::Update(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x34(3); subfic 9,0,0; adde 0,9,0; mulli 9,0,24; stw 0,0x34(3); addi 9,9,4; add 3,3,9; bl _s803066E0_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803066E0_0();
extern "C" void f_803066E0() {}
