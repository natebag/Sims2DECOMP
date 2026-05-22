// 0x800B7E5C cSoundPlayer::NotifyViewChange(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x0(3); cmpwi 0,0; beq 0f; lwz 0,0x8(3); cmpwi 0,0; beq 0f; lis 9,-32706; lwz 3,-24508(13); lfs f1,-25852(9); li 4,46; li 5,0; li 6,0; li 7,0; bl _s800B7E5C_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800B7E5C_0();
extern "C" void f_800B7E5C() {}
