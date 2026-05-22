// 0x800B08AC cSoundModeManager::UpdateSFXVolume(void) (596 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; li 4,1; lwz 3,-24136(13); bl _s800B08AC_0; lwz 29,0x4(3); li 4,3; lwz 3,-24136(13); bl _s800B08AC_1; lwz 31,0x4(3); lwz 3,-24508(13); bl _s800B08AC_2; lwz 0,0x10(28); mr 30,3; li 6,0; cmpwi 0,0; beq 3f; lwz 0,0x18(28); subf. 29,0,29; bgt 0f; li 29,0; 0:; subf. 31,0,31; bgt 1f; li 31,0; 1:; subf. 30,0,30; bgt 2f; li 30,0; 2:; add 0,31,31; add. 9,0,30; bgt 10f; lis 9,-32706; lwz 3,-24508(13); stw 6,0x10(28); li 4,20; lfs f1,-26816(9); li 5,0; li 6,0; li 7,0; bl _s800B08AC_3; b 10f; 3:; lwz 0,0x14(28); cmpwi 0,0; beq 7f; lis 9,-32697; lis 11,26214; lwz 8,0x5f14(9); ori 11,11,26215; lwz 10,0x18(28); li 7,0; lbz 0,0x1c(8); add 29,29,10; extsb 0,0; rlwinm 0,0,10,0,21; mulhw 9,0,11; srawi 0,0,31; srawi 9,9,2; subf 9,0,9; cmpw 29,9; blt 4f; mr 29,9; li 7,1; 4:; lbz 0,0x28(8); add 31,31,10; extsb 0,0; rlwinm 0,0,10,0,21; mulhw 9,0,11; srawi 0,0,31; srawi 9,9,2; subf 9,0,9; cmpw 31,9; blt 5f; mr 31,9; ori 7,7,2; 5:; lbz 0,0x29(8); add 30,30,10; extsb 0,0; rlwinm 0,0,10,0,21; mulhw 9,0,11; srawi 0,0,31; srawi 9,9,2; subf 9,0,9; cmpw 30,9; blt 6f; mr 30,9; ori 7,7,4; 6:; cmpwi 7,7; bne 10f; stw 6,0x14(28); b 10f; 7:; lis 9,-32697; lis 11,26214; lwz 10,0x5f14(9); ori 11,11,26215; lbz 0,0x1c(10); extsb 0,0; rlwinm 0,0,10,0,21; mulhw 9,0,11; srawi 0,0,31; srawi 9,9,2; subf 9,0,9; cmpw 29,9; beq 8f; mr 29,9; li 6,1; 8:; lbz 0,0x28(10); extsb 0,0; rlwinm 0,0,10,0,21; mulhw 9,0,11; srawi 0,0,31; srawi 9,9,2; subf 9,0,9; cmpw 31,9; beq 9f; mr 31,9; li 6,1; 9:; lbz 0,0x29(10); extsb 0,0; rlwinm 0,0,10,0,21; mulhw 9,0,11; srawi 0,0,31; srawi 9,9,2; subf 9,0,9; cmpw 30,9; beq 11f; mr 30,9; 10:; li 6,1; 11:; cmpwi 6,0; beq 12f; lwz 3,-24136(13); li 4,1; bl _s800B08AC_4; mr 4,29; bl _s800B08AC_5; lwz 3,-24136(13); li 4,3; bl _s800B08AC_6; mr 4,31; bl _s800B08AC_7; lwz 3,-24508(13); mr 4,30; bl _s800B08AC_8; 12:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800B08AC_0();
extern "C" void _s800B08AC_1();
extern "C" void _s800B08AC_2();
extern "C" void _s800B08AC_3();
extern "C" void _s800B08AC_4();
extern "C" void _s800B08AC_5();
extern "C" void _s800B08AC_6();
extern "C" void _s800B08AC_7();
extern "C" void _s800B08AC_8();
extern "C" void f_800B08AC() {}
