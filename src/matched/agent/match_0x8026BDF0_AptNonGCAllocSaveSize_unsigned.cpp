// 0x8026BDF0 AptNonGCAllocSaveSize(unsigned (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 3,-23020(13); addi 4,30,4; bl _s8026BDF0_0; stw 30,0x0(3); addi 3,3,4; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8026BDF0_0();
extern "C" void f_8026BDF0() {}
