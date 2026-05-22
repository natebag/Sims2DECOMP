// 0x800B7BE4 cSoundPlayer::ResumeSFX(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; lwz 3,-24508(13); cmpwi 3,0; beq 0f; lis 9,-32706; li 4,50; lfs f1,-25872(9); li 5,0; li 6,0; li 7,0; bl _s800B7BE4_0; 0:; mr 3,31; bl _s800B7BE4_1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800B7BE4_0();
extern "C" void _s800B7BE4_1();
extern "C" void f_800B7BE4() {}
