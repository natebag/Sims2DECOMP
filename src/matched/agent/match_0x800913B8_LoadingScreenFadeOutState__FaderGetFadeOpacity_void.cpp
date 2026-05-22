// 0x800913B8 LoadingScreenFadeOutState::FaderGetFadeOpacity(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x8(3); addi 9,11,168; lwz 0,0xc(9); andi. 10,0,1; beq 0f; lfs f0,0xa8(11); lfs f13,0x8(9); lfs f12,0x4(9); fsubs f0,f0,f13; fmuls f1,f0,f12; blr; 0:; andi. 11,0,2; beq 1f; lfs f13,0x4(9); lfs f0,0x8(9); fmuls f1,f0,f13; blr; 1:; andi. 9,0,4; beq 2f; lis 9,-32706; lfs f1,-32492(9); blr; 2:; andi. 10,0,8; beq 3f; lis 9,-32706; lfs f1,-32488(9); blr; 3:; lis 9,-32706; lfs f1,-32488(9)"
extern "C" float f_800913B8() {}
