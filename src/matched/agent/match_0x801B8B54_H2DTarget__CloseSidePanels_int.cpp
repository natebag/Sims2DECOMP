// 0x801B8B54 H2DTarget::CloseSidePanels(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; rlwinm 29,4,2,0,29; addi 9,30,156; lwzx 3,9,29; bl _s801B8B54_0; addi 9,30,164; lwzx 3,9,29; bl _s801B8B54_1; addi 30,30,172; lwzx 3,30,29; bl _s801B8B54_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801B8B54_0();
extern "C" void _s801B8B54_1();
extern "C" void _s801B8B54_2();
extern "C" void f_801B8B54() {}
