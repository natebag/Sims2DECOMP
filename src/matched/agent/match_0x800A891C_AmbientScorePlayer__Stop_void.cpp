// 0x800A891C AmbientScorePlayer::Stop(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; stw 0,0x0(3); bl _s800A891C_0; cmpwi 3,0; li 3,0; beq 0f; li 3,1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800A891C_0();
extern "C" void f_800A891C() {}
