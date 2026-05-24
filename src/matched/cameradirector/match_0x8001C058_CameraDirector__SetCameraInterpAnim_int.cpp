// 0x8001C058 CameraDirector::SetCameraInterpAnim(int, (696 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 30,0x88(1); stw 0,0x94(1); mr 31,3; lwz 0,0x170(31); cmpwi 0,0; beq 3f; lwz 0,0x238(31); cmpwi 0,2; beq 3f; lwz 0,0x240(31); xori 0,0,1; andi. 9,0,1; beq 3f; lwz 9,0x1cc(31); cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpwi 0,0; beq 3f; lwz 10,0x170(31); addi 30,1,8; lwz 9,0x0(10); lfs f0,0x2c(9); stfs f0,0x328(31); lwz 9,0x0(10); lfs f0,0x28(9); stfs f0,0x324(31); lwz 11,0x0(10); lfs f0,0x30(11); stfs f0,0x28(11); lwz 9,0x170(31); lwz 11,0x0(9); lfs f0,0x34(11); stfs f0,0x2c(11); lwz 3,0x170(31); lfs f1,0x448(3); bl _s8001C058_0; addi 3,1,8; bl _s8001C058_1; lwz 8,0x118(31); cmpwi 8,0; beq 1f; lwz 9,0x0(8); lwz 10,0x4(8); stw 9,0x8(1); stw 10,0xc(1); lwz 11,0x8(8); lwz 12,0xc(8); stw 11,0x8(30); stw 12,0xc(30); lwz 9,0x10(8); lwz 10,0x14(8); stw 9,0x10(30); stw 10,0x14(30); lwz 11,0x18(8); lwz 12,0x1c(8); stw 11,0x18(30); stw 12,0x1c(30); lwz 9,0x20(8); lwz 10,0x24(8); stw 9,0x20(30); stw 10,0x24(30); lwz 11,0x28(8); lwz 12,0x2c(8); stw 11,0x28(30); stw 12,0x2c(30); lwz 9,0x30(8); lwz 10,0x34(8); stw 9,0x30(30); stw 10,0x34(30); lwz 11,0x38(8); lwz 12,0x3c(8); stw 11,0x38(30); stw 12,0x3c(30); 1:; lwz 5,0x11c(31); cmpwi 5,0; beq 2f; addi 3,1,72; mr 4,30; bl _s8001C058_2; lwz 9,0x48(1); lwz 10,0x4c(1); lwz 11,0x50(1); lwz 12,0x54(1); stw 9,0x8(1); stw 10,0xc(1); stw 11,0x8(30); stw 12,0xc(30); lwz 9,0x58(1); lwz 10,0x5c(1); stw 9,0x10(30); stw 10,0x14(30); lwz 11,0x60(1); lwz 12,0x64(1); stw 11,0x18(30); stw 12,0x1c(30); lwz 9,0x68(1); lwz 10,0x6c(1); stw 9,0x20(30); stw 10,0x24(30); lwz 11,0x70(1); lwz 12,0x74(1); stw 11,0x28(30); stw 12,0x2c(30); lwz 9,0x78(1); lwz 10,0x7c(1); stw 9,0x30(30); stw 10,0x34(30); lwz 11,0x80(1); lwz 12,0x84(1); stw 11,0x38(30); stw 12,0x3c(30); 2:; lwz 10,0x170(31); mr 3,31; lfs f6,0x8(1); lwz 9,0x0(10); addi 8,10,1084; lfs f8,0x40(9); addi 9,9,64; stfs f8,0x48(1); lfs f13,0x4(9); stfs f13,0x4c(1); lfs f0,0x8(9); stfs f0,0x50(1); lfs f12,0x10(30); lfs f9,0x14(30); lfs f7,0x18(30); fmuls f12,f13,f12; lfs f10,0x8(30); fmuls f9,f13,f9; lfs f5,0x4(30); fmadds f6,f8,f6,f12; fmuls f13,f13,f7; lfs f11,0x20(30); lfs f12,0x28(30); fmadds f10,f8,f10,f13; lfs f7,0x24(30); fmadds f8,f8,f5,f9; lfs f4,0x38(30); fmadds f11,f0,f11,f6; lfs f9,0x30(30); fmadds f12,f0,f12,f10; lfs f13,0x34(30); fmadds f0,f0,f7,f8; fadds f11,f11,f9; fadds f0,f0,f13; stfs f11,0x58(1); fadds f12,f12,f4; stfs f0,0x5c(1); stfs f12,0x60(1); lwz 9,0x58(1); lwz 11,0x5c(1); lwz 0,0x60(1); stw 9,0x48(1); stw 11,0x4c(1); stw 0,0x50(1); stw 9,0x43c(10); stw 0,0x8(8); stw 11,0x4(8); bl _s8001C058_3; bl _s8001C058_4; lwz 11,0x170(31); li 0,1; li 9,8; stw 0,0x564(11); stw 9,0x160(31); 3:; lwz 0,0x94(1); mtspr 8,0; lmw 30,0x88(1); addi 1,1,144"

extern "C" void _s8001C058_0();
extern "C" void _s8001C058_1();
extern "C" void _s8001C058_2();
extern "C" void _s8001C058_3();
extern "C" void _s8001C058_4();

struct CameraDirector {
    void SetCameraInterpAnim();
};

void CameraDirector::SetCameraInterpAnim() {
}
