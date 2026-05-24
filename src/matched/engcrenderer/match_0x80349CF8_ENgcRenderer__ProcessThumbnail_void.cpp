// 0x80349CF8 ENgcRenderer::ProcessThumbnail(void (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f30,0x30(1); stfd f31,0x38(1); stmw 24,0x10(1); stw 0,0x44(1); mr 31,5; mr 30,4; mullw 4,31,31; fmr f31,f1; fmr f30,f2; mr 3,30; rlwinm 4,4,1,0,30; bl _s80349CF8_0; li 10,0; cmpw 10,31; bge 8f; lis 9,-32702; lis 11,-32702; lfs f7,0x1f48(9); addi 24,11,7976; lis 9,-32702; lis 11,-32702; addi 25,9,7984; addi 26,11,7988; lis 9,-32702; lis 11,-32702; addi 27,9,7992; addi 28,11,7996; lis 9,-32702; lis 11,-32702; addi 29,9,8000; addi 12,11,8004; 0:; cmpwi 31,0; addi 4,10,1; ble 7f; mullw 9,10,31; mtspr 9,31; lfd f8,0x0(24); lis 5,17200; lfs f6,0x0(25); li 3,0; lfs f1,0x0(26); add 0,30,9; lfs f2,0x0(27); lfs f3,0x0(28); add 6,0,9; lfs f4,0x0(29); lfs f5,0x0(12); 1:; lhz 11,0x0(6); mr 8,10; mr 7,10; rlwinm 9,11,0,16,31; rlwinm 0,9,21,11,31; rlwinm 11,11,0,27,31; xoris 0,0,32768; rlwinm 9,9,27,26,31; stw 0,0xc(1); xoris 9,9,32768; xoris 11,11,32768; stw 5,0x8(1); lfd f0,0x8(1); stw 9,0xc(1); fsub f0,f0,f8; stw 5,0x8(1); frsp f0,f0; fmuls f10,f0,f6; lfd f13,0x8(1); stw 11,0xc(1); fsub f13,f13,f8; stw 5,0x8(1); frsp f13,f13; fmuls f12,f13,f1; lfd f0,0x8(1); fmuls f13,f12,f3; fmadds f13,f10,f2,f13; fsub f0,f0,f8; frsp f0,f0; fmuls f11,f0,f6; fmadds f0,f11,f4,f13; fcmpu 0,f0,f31; bge 2f; sth 3,0x0(6); b 6f; 2:; fdivs f13,f5,f0; fsubs f0,f0,f31; fmr f9,f7; fmuls f0,f0,f30; fmuls f0,f0,f9; fmuls f10,f10,f13; fmuls f11,f11,f13; fmuls f12,f12,f13; fmuls f10,f10,f0; fmuls f11,f11,f0; fmuls f12,f12,f0; fcmpu 0,f10,f9; cror 3,2,1; bns 3f; fmr f10,f9; 3:; fcmpu 0,f12,f9; cror 3,2,1; bns 4f; fmr f12,f9; 4:; fcmpu 0,f11,f7; cror 3,2,1; bns 5f; fmr f11,f7; 5:; fmr f13,f10; fctiwz f0,f13; mr 11,10; stfd f0,0x8(1); fmr f13,f12; fctiwz f0,f13; lwz 10,0xc(1); fmr f13,f11; stfd f0,0x8(1); fctiwz f0,f13; rlwinm 10,10,8,16,20; lwz 11,0xc(1); stfd f0,0x8(1); rlwinm 11,11,3,21,26; lwz 9,0xc(1); or 10,10,11; rlwinm 9,9,29,27,31; or 9,9,10; sth 9,0x0(6); 6:; addi 6,6,2; bdnz 1b; 7:; mr 10,4; cmpw 10,31; blt 0b; 8:; mullw 4,31,31; mr 3,30; rlwinm 4,4,1,0,30; bl _s80349CF8_1; lwz 0,0x44(1); mtspr 8,0; lmw 24,0x10(1); lfd f30,0x30(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s80349CF8_0();
extern "C" void _s80349CF8_1();

struct ENgcRenderer {
    void ProcessThumbnail();
};

void ENgcRenderer::ProcessThumbnail() {
}
