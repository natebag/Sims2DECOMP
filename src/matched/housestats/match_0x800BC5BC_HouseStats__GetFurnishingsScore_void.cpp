// 0x800BC5BC HouseStats::GetFurnishingsScore(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f28,0x18(1); stfd f29,0x20(1); stfd f30,0x28(1); stfd f31,0x30(1); stmw 30,0x10(1); stw 0,0x3c(1); lwz 11,-21496(13); lis 30,17200; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-21496(13); xoris 3,3,32768; lis 8,-32706; lwz 11,0x0(10); stw 3,0xc(1); lha 3,0x130(11); stw 30,0x8(1); lwz 0,0x134(11); add 3,10,3; lfd f0,0x8(1); lfd f31,-25096(8); mtspr 8,0; fsub f0,f0,f31; frsp f28,f0; blrl; xoris 3,3,32768; stw 3,0xc(1); lis 9,-32706; lfs f30,-25084(9); lis 10,-32706; stw 30,0x8(1); lfs f29,-25088(10); lfd f0,0x8(1); fsub f0,f0,f31; frsp f0,f0; fcmpu 0,f0,f30; beq 0f; fdivs f29,f28,f0; 0:; lwz 3,-21424(13); lwz 9,0x0(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x8(3); cmpwi 0,0; bne 1f; fmr f0,f30; b 6f; 1:; mr 10,0; fmr f11,f30; lwz 8,0x0(3); addic. 11,0,-1; blt 3f; rlwinm 9,11,3,0,28; lfsx f0,9,8; fsubs f11,f29,f0; fcmpu 0,f11,f30; bgt 3f; fmr f13,f30; add 9,9,8; 2:; addic. 11,11,-1; blt 3f; lfsu f0,-8(9); fsubs f11,f29,f0; fcmpu 0,f11,f13; ble 2b; 3:; addi 0,10,-1; cmpw 11,0; bne 4f; rlwinm 9,11,3,0,28; add 9,9,8; lfs f0,0x4(9); b 6f; 4:; cmpwi 11,-1; bne 5f; lfs f0,0x4(8); b 6f; 5:; rlwinm 9,11,3,0,28; lwz 10,0x4(3); add 9,9,8; rlwinm 11,11,2,0,29; lfs f13,0x4(9); lfsx f12,11,10; lfs f0,0xc(9); fmuls f11,f11,f12; fsubs f0,f0,f13; fmadds f0,f11,f0,f13; 6:; fctiwz f13,f0; stfd f13,0x8(1); lwz 3,0xc(1); lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x10(1); lfd f28,0x18(1); lfd f29,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"

struct HouseStats {
    void GetFurnishingsScore();
};

void HouseStats::GetFurnishingsScore() {
}
