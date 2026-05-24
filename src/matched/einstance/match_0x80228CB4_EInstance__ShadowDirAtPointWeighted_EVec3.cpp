// 0x80228CB4 EInstance::ShadowDirAtPointWeighted(EVec3 (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-208(1); mfspr 0,8; stfd f28,0xb0(1); stfd f29,0xb8(1); stfd f30,0xc0(1); stfd f31,0xc8(1); stmw 23,0x8c(1); stw 0,0xd4(1); lis 9,-32704; addi 11,1,8; lfs f0,-6140(9); mr 30,5; lis 9,-32704; mr 27,11; stfs f0,0x8(11); addi 8,1,24; stfs f0,0x4(11); mr 31,8; stfs f0,0x8(1); mr 29,4; lfs f0,-6136(9); mr 5,6; lwz 9,0x4(11); li 7,-1; lwz 0,0x8(11); lwz 10,0x8(1); li 11,12; stw 9,0x4(30); mtspr 9,11; stw 10,0x0(30); stw 0,0x8(30); lwz 9,0x4(3); addi 26,9,56; 0:; sth 7,0x0(8); stfs f0,0x4(8); addi 8,8,8; bdnz 0b; lwz 3,0x4(3); mr 6,31; mr 4,29; li 24,0; addi 3,3,24; bl _s80228CB4_0; lha 0,0x10(27); cmpwi 0,-1; beq 3f; lis 9,-32704; lis 11,-32704; lfs f31,-6140(9); lis 10,-32704; lis 9,-32704; lfs f28,-6132(11); lfs f29,-6128(10); addi 28,27,16; lfs f30,-6124(9); li 25,0; addi 23,1,28; 1:; rlwinm 0,0,5,0,26; add 31,26,0; lfs f9,0x8(31); fcmpu 0,f9,f31; cror 3,2,1; bns 2f; lfsx f10,26,0; mr 3,27; lfs f11,0x4(31); lfs f0,0x0(29); lfs f13,0x4(29); lfs f12,0x8(29); fsubs f0,f0,f10; fsubs f13,f13,f11; stfs f0,0x8(1); fsubs f12,f12,f9; stfs f13,0xc(1); stfs f12,0x10(1); bl _s80228CB4_1; fcmpu 0,f1,f31; ble 2f; addi 9,31,16; lfs f12,0x10(31); lfs f0,0x4(9); lfs f11,0x8(9); fmuls f0,f0,f29; lfsx f13,23,25; fmadds f12,f12,f28,f0; lfs f9,0xc(31); fmadds f11,f11,f30,f12; lfs f10,0x8(1); fmuls f13,f13,f11; lfs f12,0x4(27); fmuls f13,f13,f9; lfs f11,0x8(27); fdivs f13,f13,f1; lfs f0,0x0(30); lfs f9,0x4(30); lfs f8,0x8(30); fmuls f11,f11,f13; fmuls f10,f10,f13; stfs f11,0x80(1); fmuls f12,f12,f13; stfs f10,0x78(1); stfs f12,0x7c(1); fadds f0,f0,f10; fadds f9,f9,f12; stfs f0,0x0(30); fadds f8,f8,f11; stfs f9,0x4(30); stfs f8,0x8(30); 2:; addi 24,24,1; addi 25,25,8; cmpwi 24,11; bgt 3f; lhzu 0,0x8(28); extsh 0,0; cmpwi 0,-1; bne 1b; 3:; lwz 0,0xd4(1); mtspr 8,0; lmw 23,0x8c(1); lfd f28,0xb0(1); lfd f29,0xb8(1); lfd f30,0xc0(1); lfd f31,0xc8(1); addi 1,1,208"

extern "C" void _s80228CB4_0();
extern "C" void _s80228CB4_1();

struct EInstance {
    void ShadowDirAtPointWeighted_EVec3();
};

void EInstance::ShadowDirAtPointWeighted_EVec3() {
}
