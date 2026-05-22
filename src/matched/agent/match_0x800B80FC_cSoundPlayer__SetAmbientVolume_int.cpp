// 0x800B80FC cSoundPlayer::SetAmbientVolume(int) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32697; lwz 11,0x5f14(9); stb 4,0x29(11); lwz 0,0x0(3); cmpwi 0,0; beq 0f; lwz 0,0x8(3); cmpwi 0,0; beq 0f; lis 9,-32706; mr 5,4; lwz 3,-24508(13); li 4,44; lfs f1,-25828(9); li 6,0; li 7,0; bl _s800B80FC_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800B80FC_0();
extern "C" void f_800B80FC() {}
