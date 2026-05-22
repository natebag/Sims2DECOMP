// 0x800B0F70 cSoundModeManager::StartMusicTrack(char (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 28,0x28(1); stw 0,0x44(1); mr 28,3; li 0,0; stw 0,0x4(28); fmr f31,f1; lwz 29,-26564(13); li 5,0; addi 3,1,8; lwz 30,0x0(29); lha 0,0x40(30); addi 30,30,64; add 29,29,0; bl _s800B0F70_0; lwz 0,0x4(30); mr 3,29; addi 4,1,8; mtspr 8,0; blrl; lwz 0,0x8(28); cmpwi 0,0; bne 0f; lis 9,-32697; lwz 11,0x5f14(9); lis 6,17200; lwz 7,-26564(13); lis 9,-32706; lbz 0,0x1d(11); lis 8,-32706; lfd f0,-26672(9); extsb 0,0; lwz 9,0x0(7); xoris 0,0,32768; lfs f13,-26664(8); stw 0,0x24(1); lha 3,0x60(9); stw 6,0x20(1); lwz 0,0x64(9); add 3,7,3; lfd f1,0x20(1); mtspr 8,0; fsub f1,f1,f0; frsp f1,f1; fmuls f1,f31,f1; fdivs f1,f1,f13; blrl; 0:; lwz 0,0x44(1); mtspr 8,0; lmw 28,0x28(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s800B0F70_0();
extern "C" void f_800B0F70() {}
