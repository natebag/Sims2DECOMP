// 0x801B1128 FAMTarget::OnBackoutToMainMenuDialogClose(int) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,1; bne 0f; lis 3,-32705; addi 3,3,1700; bl _s801B1128_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B1128_0();
extern "C" void f_801B1128() {}
