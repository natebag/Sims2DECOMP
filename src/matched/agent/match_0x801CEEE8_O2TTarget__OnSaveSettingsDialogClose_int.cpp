// 0x801CEEE8 O2TTarget::OnSaveSettingsDialogClose(int) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,1; bne 1f; lwz 0,0x88(31); cmpwi 0,1; bne 0f; bl _s801CEEE8_0; b 1f; 0:; cmpwi 0,2; bne 1f; mr 3,31; bl _s801CEEE8_1; 1:; lis 3,-32705; li 4,0; addi 3,3,15992; li 5,0; li 6,0; li 7,0; bl _s801CEEE8_2; li 0,0; stw 0,0x258(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801CEEE8_0();
extern "C" void _s801CEEE8_1();
extern "C" void _s801CEEE8_2();
extern "C" void f_801CEEE8() {}
