// 0x800B0498 cSoundModeManager::SetMode(int) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 9,0x0(31); cmpw 4,9; beq 2f; stw 4,0x0(31); cmpwi 4,3; beq 0f; cmpwi 4,1; beq 0f; cmpwi 4,5; bne 2f; 0:; lwz 0,0x4(31); cmpwi 0,0; beq 1f; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26564(13); li 4,1; lwz 9,0x0(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x4(31); b 2f; 1:; cmpwi 9,6; bne 2f; lwz 0,0x0(31); cmpwi 0,1; bne 2f; mr 3,31; li 4,30; bl _s800B0498_0; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800B0498_0();
extern "C" void f_800B0498() {}
