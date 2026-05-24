// 0x8030035C EWindow::CalcWindowMat(void) (324 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f29,0x20(1); stfd f30,0x28(1); stfd f31,0x30(1); stmw 30,0x18(1); stw 0,0x3c(1); mr 31,3; lis 9,-32702; lfs f12,0x48(31); lfs f0,0x40(31); lfs f13,-2200(9); fsubs f12,f12,f0; fcmpu 0,f12,f13; bne 0f; lis 9,-32702; lfs f29,-2196(9); b 1f; 0:; lfs f0,0x58(31); lfs f13,0x50(31); fsubs f0,f0,f13; fdivs f29,f0,f12; 1:; addi 9,31,64; lis 11,-32702; lfs f12,0x4(9); lfs f0,0xc(9); lfs f13,-2200(11); fsubs f12,f0,f12; fcmpu 0,f12,f13; bne 2f; lis 9,-32702; lfs f30,-2196(9); b 3f; 2:; addi 9,31,80; lfs f13,0x4(9); lfs f0,0xc(9); fsubs f0,f0,f13; fdivs f30,f0,f12; 3:; lfs f13,0x40(31); lis 9,-32702; lfs f0,0x44(31); addi 30,1,8; lfs f31,-2200(9); fneg f13,f13; fneg f0,f0; stfs f13,0x8(1); stfs f0,0xc(1); mr 4,30; stfs f31,0x8(30); mr 3,31; bl _s8030035C_0; lis 9,-32702; stfs f29,0x8(1); lfs f0,-2196(9); mr 4,30; stfs f30,0xc(1); mr 3,31; stfs f0,0x8(30); bl _s8030035C_1; lfs f13,0x50(31); mr 4,30; lfs f0,0x54(31); mr 3,31; stfs f13,0x8(1); stfs f0,0xc(1); stfs f31,0x8(30); bl _s8030035C_2; lwz 9,0x9c(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x18(1); lfd f29,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"

extern "C" void _s8030035C_0();
extern "C" void _s8030035C_1();
extern "C" void _s8030035C_2();

struct EWindow {
    void CalcWindowMat();
};

void EWindow::CalcWindowMat() {
}
