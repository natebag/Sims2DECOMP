// 0x80090544 LoadingScreenUpdateState::DrawTopmost(ERC (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); lwz 9,-32160(13); mr 30,4; lwz 31,0x98(9); cmpwi 31,0; beq 4f; lwz 3,0x8(3); addi 9,3,168; lwz 0,0xc(9); andi. 11,0,1; beq 0f; lfs f0,0xa8(3); lfs f13,0x8(9); lfs f12,0x4(9); fsubs f0,f0,f13; fmuls f31,f0,f12; b 3f; 0:; andi. 11,0,2; beq 1f; lfs f13,0x4(9); lfs f0,0x8(9); fmuls f31,f0,f13; b 3f; 1:; andi. 9,0,4; beq 2f; lis 9,-32706; lfs f31,-32668(9); b 3f; 2:; andi. 11,0,8; lis 9,-32706; lfs f31,-32664(9); 3:; lis 3,-32706; fmr f1,f31; addi 3,3,-32712; creqv 6,6,6; bl _s80090544_0; mr 3,31; mr 4,30; fmr f1,f31; bl _s80090544_1; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s80090544_0();
extern "C" void _s80090544_1();
extern "C" void f_80090544() {}
