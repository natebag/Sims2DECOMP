// 0x80343EA0 ENgcRenderer::Scissor(EDLEntry (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 10,0x4(4); lis 11,-32702; lis 9,-32702; lfd f8,0x1dd8(11); lfs f12,0x0(10); lfs f11,0x4(10); lfs f0,0x8(10); fmr f9,f12; lfs f13,0xc(10); fcmpu 0,f9,f8; lfs f10,0x1dd0(9); fsubs f0,f0,f12; fsubs f13,f13,f11; lwz 11,0x4d8(3); fadds f7,f0,f10; fadds f11,f13,f10; cror 3,2,1; bso 0f; fctiwz f0,f9; stfd f0,0x8(1); lwz 0,0xc(1); b 1f; 0:; fsub f0,f9,f8; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); xoris 0,0,32768; 1:; stw 0,0x9c8(11); lis 9,-32702; lfd f13,0x1dd8(9); lfs f0,0x4(10); lwz 11,0x4d8(3); fmr f12,f0; fcmpu 0,f12,f13; cror 3,2,1; bso 2f; fctiwz f0,f12; stfd f0,0x8(1); lwz 0,0xc(1); b 3f; 2:; fsub f0,f12,f13; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); xoris 0,0,32768; 3:; lis 9,-32702; stw 0,0x9cc(11); lfd f0,0x1dd8(9); fmr f13,f7; lwz 11,0x4d8(3); fcmpu 0,f13,f0; cror 3,2,1; bso 4f; fctiwz f0,f13; stfd f0,0x8(1); lwz 0,0xc(1); b 5f; 4:; fsub f0,f13,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); xoris 0,0,32768; 5:; lis 9,-32702; stw 0,0x9d0(11); lfd f0,0x1dd8(9); fmr f13,f11; lwz 11,0x4d8(3); fcmpu 0,f13,f0; cror 3,2,1; bso 6f; fctiwz f0,f13; stfd f0,0x8(1); lwz 0,0xc(1); b 7f; 6:; fsub f0,f13,f0; fctiwz f13,f0; stfd f13,0x8(1); lwz 0,0xc(1); xoris 0,0,32768; 7:; lis 9,-32702; stw 0,0x9d4(11); lfs f13,0x1de0(9); fcmpu 0,f7,f13; cror 3,2,0; bso 8f; fcmpu 0,f11,f13; cror 3,2,0; bns 9f; 8:; lwz 9,0x4d8(3); li 0,0; stw 0,0x9d0(9); lwz 11,0x4d8(3); stw 0,0x9d4(11); 9:; lwz 9,0x4d8(3); lwz 0,0x6cc(9); oris 0,0,32768; ori 0,0,1024; stw 0,0x6cc(9); addi 1,1,16"

struct ENgcRenderer {
    void Scissor_EDLEntry();
};

void ENgcRenderer::Scissor_EDLEntry() {
}
