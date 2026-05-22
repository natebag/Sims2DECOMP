// 0x801B71B4 UIDialog::SpawnDialog(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; lis 9,-32697; lwz 3,0x5f08(9); bl _s801B71B4_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B71B4_0();
extern "C" void f_801B71B4() {}
