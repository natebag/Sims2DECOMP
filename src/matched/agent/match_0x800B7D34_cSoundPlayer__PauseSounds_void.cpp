// 0x800B7D34 cSoundPlayer::PauseSounds(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 0,1; lwz 9,0x0(31); stw 0,0xc(31); cmpwi 9,0; beq 1f; lwz 0,0x8(31); cmpwi 0,0; beq 1f; lwz 3,-24508(13); cmpwi 3,0; beq 0f; lis 30,-32706; li 4,47; lfs f1,-25860(30); li 5,0; li 6,0; li 7,0; bl _s800B7D34_0; lfs f1,-25860(30); li 4,21; lwz 3,-24508(13); li 5,0; li 6,0; li 7,0; bl _s800B7D34_1; 0:; mr 3,31; bl _s800B7D34_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B7D34_0();
extern "C" void _s800B7D34_1();
extern "C" void _s800B7D34_2();
extern "C" void f_800B7D34() {}
