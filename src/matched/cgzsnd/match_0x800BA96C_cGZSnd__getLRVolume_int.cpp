// 0x800BA96C cGZSnd::getLRVolume(int, (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32706; lfs f10,-25324(9); lis 0,17200; lis 9,-32706; lis 11,-32706; stfs f10,0x0(6); lis 10,-32706; stfs f10,0x0(5); lfd f13,-25320(9); lwz 9,0x24(3); lfs f11,-25312(11); addi 9,9,-512; lfs f12,-25308(10); xoris 9,9,32768; li 11,0; stw 9,0xc(1); stw 0,0x8(1); lfd f0,0x8(1); fsub f0,f0,f13; frsp f0,f0; fmuls f13,f0,f11; fcmpu 0,f13,f12; bge 0f; lis 9,-32706; li 11,1; lfs f0,-25304(9); b 1f; 0:; fcmpu 0,f13,f10; ble 2f; lis 9,-32706; li 11,1; lfs f0,-25300(9); 1:; fsubs f13,f0,f13; 2:; lis 9,-32706; lfs f0,-25296(9); fcmpu 0,f13,f0; cror 3,2,1; bns 3f; lfs f0,0x0(5); fsubs f0,f0,f13; stfs f0,0x0(5); b 4f; 3:; lfs f0,0x0(6); fadds f0,f0,f13; stfs f0,0x0(6); 4:; lis 9,-32706; lfs f13,0x28(3); lfs f0,-25296(9); fcmpu 0,f13,f0; bge 5f; lis 9,-32706; lfs f11,-25308(9); b 6f; 5:; lis 9,-32706; lfs f11,-25324(9); 6:; lis 9,-32706; lfs f13,0x2c(3); lfs f0,-25296(9); fcmpu 0,f13,f0; bge 7f; lis 9,-32706; lfs f10,-25308(9); b 8f; 7:; lis 9,-32706; lfs f10,-25324(9); 8:; lis 9,-32706; fmuls f13,f11,f10; lfs f0,-25296(9); lfs f12,0x0(5); fcmpu 7,f13,f0; mfcr 0; rlwinm 0,0,29,31,31; cmpw 11,0; beq 10f; lfs f0,0x0(6); fcmpu 0,f12,f0; cror 3,2,0; bns 9f; fneg f11,f11; b 10f; 9:; fneg f10,f10; 10:; fmuls f0,f12,f11; stfs f0,0x0(5); xoris 0,4,32768; stw 0,0xc(1); lis 11,17200; lfs f13,0x0(6); lis 10,-32706; stw 11,0x8(1); lis 8,-32706; fmuls f13,f13,f10; lfd f12,-25320(10); stfs f13,0x0(6); lfd f0,0x8(1); lfs f13,0x0(5); fsub f0,f0,f12; lfs f11,-25292(8); stfs f13,0x28(3); frsp f0,f0; fmuls f0,f0,f11; lfs f12,0x0(6); stfs f12,0x2c(3); lfs f13,0x0(5); fmuls f13,f13,f0; stfs f13,0x0(5); lfs f12,0x0(6); fmuls f12,f12,f0; stfs f12,0x0(6); addi 1,1,16"

struct cGZSnd {
    void getLRVolume();
};

void cGZSnd::getLRVolume() {
}
