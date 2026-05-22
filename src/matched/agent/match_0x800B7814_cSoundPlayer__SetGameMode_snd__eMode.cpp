// 0x800B7814 cSoundPlayer::SetGameMode(snd::eMode) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x8(3); cmpwi 0,0; beq 1f; lwz 0,0x0(3); cmpwi 0,0; beq 1f; lwz 3,-24508(13); cmpwi 3,0; beq 1f; lwz 9,-26824(13); lwz 0,0x450(9); cmpwi 0,0; bne 1f; cmpwi 4,5; bne 0f; addi 3,3,48; li 4,5; bl _s800B7814_0; b 1f; 0:; lis 9,-32706; mr 5,4; lfs f1,-25900(9); li 4,36; li 6,0; li 7,0; bl _s800B7814_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800B7814_0();
extern "C" void _s800B7814_1();
extern "C" void f_800B7814() {}
