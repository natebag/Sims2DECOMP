// 0x800B7904 cSoundPlayer::QuietAll(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 11,3; lwz 0,0x0(11); cmpwi 0,0; beq 0f; lwz 0,0x8(11); cmpwi 0,0; beq 0f; lwz 0,0x1c(11); lis 9,-32706; lwz 3,-24508(13); li 4,20; stw 0,0x10(11); li 5,0; lfs f1,-25892(9); li 6,0; stw 0,0x8(1); li 7,0; bl _s800B7904_0; 0:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

extern "C" void _s800B7904_0();

struct cSoundPlayer {
    void QuietAll();
};

void cSoundPlayer::QuietAll() {
}
