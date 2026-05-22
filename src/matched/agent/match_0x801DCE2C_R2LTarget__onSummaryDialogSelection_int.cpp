// 0x801DCE2C R2LTarget::onSummaryDialogSelection(int) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; cmpwi 4,0; stw 0,0xb8(3); bne 0f; lis 5,-32705; lwz 4,0x94(3); addi 6,3,132; addi 5,5,20668; addi 3,3,324; li 7,0; li 8,0; bl _s801DCE2C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801DCE2C_0();
extern "C" void f_801DCE2C() {}
