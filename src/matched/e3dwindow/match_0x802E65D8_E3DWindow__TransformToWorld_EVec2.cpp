// 0x802E65D8 E3DWindow::TransformToWorld(EVec2 (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stfd f30,0x60(1); stfd f31,0x68(1); stmw 30,0x58(1); stw 0,0x74(1); mr 31,3; lfs f0,0x0(4); lfs f11,0x250(31); lis 9,-32702; lfs f13,0x4(4); mr 30,5; lfs f12,0x240(31); fsubs f0,f0,f11; lfs f10,0x254(31); lfs f11,0x244(31); fdivs f12,f0,f12; lfd f9,-4984(9); fsubs f13,f13,f10; stfs f12,0x8(1); fdivs f13,f13,f11; fmr f0,f12; stfs f13,0xc(1); fcmpu 0,f0,f9; blt 0f; lis 9,-32702; lfs f11,-4976(9); fcmpu 0,f12,f11; bgt 0f; fmr f0,f13; fcmpu 0,f0,f9; blt 0f; fcmpu 0,f13,f11; ble 1f; 0:; li 3,0; b 4f; 1:; mr 3,31; addi 4,1,80; addi 5,1,84; bl _s802E65D8_0; lfs f11,0x54(1); addi 9,31,224; lfs f13,0xc(1); addi 11,31,240; lfs f12,0x50(1); addi 10,31,256; fmuls f13,f13,f11; lfs f0,0x8(1); lfs f5,0xc(9); addi 8,1,16; lfs f4,0xc(11); fmuls f0,f0,f12; lfs f11,0x4(9); fmuls f5,f5,f0; lfs f10,0x8(9); fmuls f4,f4,f13; lfs f6,0x4(11); fmuls f11,f11,f0; lfs f7,0x8(11); fmuls f10,f10,f0; lfs f8,0xe0(31); fmuls f6,f6,f13; lfs f3,0xf0(31); fmuls f7,f7,f13; lfs f12,0x100(31); fmuls f8,f8,f0; fmuls f3,f3,f13; lfs f9,0xc(10); lfs f0,0x4(10); fadds f30,f8,f3; lfs f13,0x8(10); fadds f1,f11,f6; fadds f31,f10,f7; stfs f8,0x30(1); fadds f2,f5,f4; stfs f11,0x34(1); fsubs f12,f30,f12; stfs f10,0x38(1); stfs f12,0x10(1); fsubs f0,f1,f0; fsubs f13,f31,f13; stfs f0,0x14(1); fsubs f9,f2,f9; stfs f13,0x18(1); stfs f9,0x1c(1); lis 10,-32702; stfs f5,0x3c(1); stfs f3,0x40(1); stfs f6,0x44(1); stfs f7,0x48(1); stfs f4,0x4c(1); stfs f30,0x20(1); stfs f1,0x24(1); stfs f31,0x28(1); stfs f2,0x2c(1); lwz 9,0x10(1); lwz 11,0x8(8); lwz 0,0x4(8); stw 9,0x0(30); stw 0,0x4(30); stw 11,0x8(30); lfs f0,0x0(30); lfs f13,-4972(10); fcmpu 0,f0,f13; bne 2f; lfs f0,0x4(30); fcmpu 0,f0,f13; bne 2f; lfs f0,0x8(30); fcmpu 0,f0,f13; beq 3f; 2:; mr 3,30; mr 4,3; bl _s802E65D8_1; 3:; li 3,1; 4:; lwz 0,0x74(1); mtspr 8,0; lmw 30,0x58(1); lfd f30,0x60(1); lfd f31,0x68(1); addi 1,1,112"

extern "C" void _s802E65D8_0();
extern "C" void _s802E65D8_1();

struct E3DWindow {
    void TransformToWorld();
};

void E3DWindow::TransformToWorld() {
}
