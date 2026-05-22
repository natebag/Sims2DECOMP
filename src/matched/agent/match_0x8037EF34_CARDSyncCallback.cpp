// 0x8037EF34 __CARDSyncCallback (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; mulli 4,3,272; stw 0,0x4(1); lis 3,-32688; stwu 1,-8(1); addi 0,3,-24000; add 3,0,4; addi 3,3,140; bl _s8037EF34_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8037EF34_0();
extern "C" void f_8037EF34() {}
