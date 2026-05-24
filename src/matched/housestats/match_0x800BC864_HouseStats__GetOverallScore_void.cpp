// 0x800BC864 HouseStats::GetOverallScore(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 30,3; bl _s800BC864_0; mr 29,3; mr 3,30; bl _s800BC864_1; mr 28,3; mr 3,30; bl _s800BC864_2; mr 27,3; mr 3,30; bl _s800BC864_3; xoris 29,29,32768; stw 29,0x14(1); lis 0,17200; mr 11,9; xoris 28,28,32768; stw 0,0x10(1); mr 10,9; xoris 27,27,32768; mr 8,9; lfd f12,0x10(1); xoris 6,3,32768; stw 28,0x14(1); lis 9,-32706; lfd f11,-25048(9); lis 7,-32706; stw 0,0x10(1); lfs f10,-24308(13); fsub f12,f12,f11; lfd f0,0x10(1); frsp f12,f12; stw 27,0x14(1); fsub f0,f0,f11; lfs f9,-25040(7); stw 0,0x10(1); frsp f0,f0; fmadds f12,f10,f12,f0; lfd f13,0x10(1); fadds f10,f10,f9; stw 6,0x14(1); fsub f13,f13,f11; stw 0,0x10(1); frsp f13,f13; fadds f12,f12,f13; lfd f0,0x10(1); fsub f0,f0,f11; frsp f0,f0; fadds f12,f12,f0; fdivs f12,f12,f10; fmr f0,f12; fctiwz f8,f0; stfd f8,0x10(1); lwz 3,0x14(1); lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s800BC864_0();
extern "C" void _s800BC864_1();
extern "C" void _s800BC864_2();
extern "C" void _s800BC864_3();

struct HouseStats {
    void GetOverallScore();
};

void HouseStats::GetOverallScore() {
}
