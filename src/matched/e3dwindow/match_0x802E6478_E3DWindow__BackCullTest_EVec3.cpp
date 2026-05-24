// 0x802E6478 E3DWindow::BackCullTest(EVec3 (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stfd f30,0x80(1); stfd f31,0x88(1); stmw 23,0x5c(1); stw 0,0x94(1); li 0,3; mr 29,3; mtspr 9,0; addi 27,1,8; addi 23,1,56; addi 24,1,72; 0:; bdnz 0b; lis 9,-32702; lis 11,-32702; mr 31,27; lfs f31,-4996(9); lfs f30,-4992(11); addi 25,31,32; mr 30,4; addi 26,29,288; li 28,0; 1:; lfs f13,0x4(30); mr 3,23; lfs f0,0x8(30); mr 4,24; lfs f12,0x0(30); mr 5,26; stfs f13,0x4c(1); stfs f0,0x50(1); stfs f12,0x48(1); stfs f31,0x54(1); bl _s802E6478_0; lfs f0,0x38(1); stfs f0,0x0(31); lfs f13,0x3c(1); stfs f13,0x4(31); lfs f0,0x40(1); stfs f0,0x8(31); lfs f0,0x44(1); stfs f0,0xc(31); fcmpu 0,f0,f30; cror 3,2,0; bns 2f; li 3,1; b 3f; 2:; fdivs f10,f31,f0; lfs f12,0x240(29); lfsx f0,28,27; addi 30,30,12; lfs f13,0x250(29); lfs f9,0x244(29); lfs f11,0x254(29); fmuls f0,f0,f10; fmadds f0,f0,f12,f13; stfsx f0,28,27; addi 28,28,16; lfs f0,0x4(31); fmuls f0,f0,f10; fmadds f0,f0,f9,f11; stfs f0,0x4(31); addi 31,31,16; cmpw 31,25; ble 1b; lfs f11,0x18(1); lis 9,-32702; lfs f9,0x1c(1); lfs f12,0xc(1); lfs f0,0x28(1); lfs f8,0x8(1); fsubs f12,f9,f12; lfs f13,0x2c(1); fsubs f0,f0,f11; fmuls f12,f12,f0; lfs f10,-4992(9); fsubs f13,f13,f9; fsubs f11,f11,f8; fmsubs f11,f11,f13,f12; fcmpu 7,f11,f10; mfcr 3; rlwinm 3,3,29,31,31; 3:; lwz 0,0x94(1); mtspr 8,0; lmw 23,0x5c(1); lfd f30,0x80(1); lfd f31,0x88(1); addi 1,1,144"

extern "C" void _s802E6478_0();

struct E3DWindow {
    void BackCullTest();
};

void E3DWindow::BackCullTest() {
}
