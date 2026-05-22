// 0x801B0764 FAMTarget::UpdateShaders(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x88(3); cmpwi 0,0; bne 0f; bl _s801B0764_0; b 2f; 0:; cmpwi 0,4; bne 1f; bl _s801B0764_1; b 2f; 1:; cmpwi 0,1; bne 2f; bl _s801B0764_2; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801B0764_0();
extern "C" void _s801B0764_1();
extern "C" void _s801B0764_2();
extern "C" void f_801B0764() {}
