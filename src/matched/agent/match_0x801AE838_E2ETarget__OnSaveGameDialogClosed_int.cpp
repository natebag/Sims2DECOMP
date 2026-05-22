// 0x801AE838 E2ETarget::OnSaveGameDialogClosed(int) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 9,3; cmpwi 4,0; bne 0f; bl _s801AE838_0; b 1f; 0:; li 0,0; lis 3,-32705; stw 0,0xe0(9); addi 3,3,-2260; li 4,0; li 5,0; li 6,0; li 7,0; bl _s801AE838_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801AE838_0();
extern "C" void _s801AE838_1();
extern "C" void f_801AE838() {}
