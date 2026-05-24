// 0x802EBBC8 EAnimController::CalcMatrix(EMat4 (1040 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-328(1); mfspr 0,8; stmw 24,0x128(1); stw 0,0x14c(1); mr 31,6; mr 26,4; lwz 0,0x0(31); mr 25,5; mr 24,7; andi. 9,0,1; beq 4f; andi. 9,0,2; beq 1f; andi. 9,0,4; beq 0f; lwz 0,0xb0(25); cmpwi 0,0; bne 0f; addi 3,1,72; addi 4,25,112; bl _s802EBBC8_0; addi 29,25,16; lfs f13,0x4(29); addi 27,1,72; lfs f12,0x8(29); addi 28,1,136; lfs f0,0x10(25); fneg f13,f13; fneg f12,f12; addi 30,1,152; fneg f0,f0; stfs f13,0x8c(1); stfs f12,0x90(1); mr 4,28; stfs f0,0x88(1); mr 3,27; bl _s802EBBC8_1; addi 11,25,28; addi 9,31,4; lfs f0,0x4(11); addi 3,1,216; lfs f5,0x4(9); mr 4,30; lfs f7,0xc(9); lfs f6,0x8(9); fmuls f3,f5,f0; lfs f10,0x4(31); fmuls f2,f7,f0; lfs f13,0x1c(25); fmuls f11,f6,f0; lfs f9,0x8(11); fmuls f0,f10,f0; fneg f4,f5; lfs f8,0xc(11); fneg f12,f10; fmadds f4,f4,f13,f0; fmsubs f12,f12,f13,f3; fmsubs f11,f7,f13,f11; fmuls f3,f6,f9; fmadds f13,f6,f13,f2; fmuls f0,f10,f9; fmadds f11,f5,f9,f11; fsubs f12,f12,f3; fmadds f9,f7,f9,f4; fsubs f13,f13,f0; fmadds f10,f10,f8,f11; fmadds f7,f7,f8,f12; stfs f10,0xd8(1); fmadds f5,f5,f8,f13; stfs f7,0xe4(1); fmadds f6,f6,f8,f9; stfs f5,0xdc(1); stfs f6,0xe0(1); bl _s802EBBC8_2; addi 4,31,32; mr 3,30; bl _s802EBBC8_3; addi 9,31,20; lfs f12,0x8(29); lfs f11,0x8(9); mr 4,28; lfs f10,0x14(31); mr 3,30; fadds f12,f12,f11; lfs f13,0x10(25); lfs f11,0x4(9); lfs f0,0x4(29); fadds f13,f13,f10; stfs f13,0x88(1); fadds f0,f0,f11; stfs f12,0x90(1); stfs f0,0x8c(1); bl _s802EBBC8_4; mr 4,27; mr 5,30; addi 3,1,232; bl _s802EBBC8_5; lwz 9,0xe8(1); lwz 10,0xec(1); addi 8,1,8; lwz 11,0xf0(1); lwz 12,0xf4(1); mr 4,8; stw 9,0x8(1); stw 10,0xc(1); stw 11,0x8(8); stw 12,0xc(8); lwz 9,0xf8(1); lwz 10,0xfc(1); stw 9,0x10(8); stw 10,0x14(8); lwz 11,0x100(1); lwz 12,0x104(1); stw 11,0x18(8); stw 12,0x1c(8); lwz 9,0x108(1); lwz 10,0x10c(1); stw 9,0x20(8); stw 10,0x24(8); lwz 11,0x110(1); lwz 12,0x114(1); stw 11,0x28(8); stw 12,0x2c(8); lwz 9,0x118(1); lwz 10,0x11c(1); stw 9,0x30(8); stw 10,0x34(8); lwz 11,0x120(1); lwz 12,0x124(1); stw 11,0x38(8); stw 12,0x3c(8); b 3f; 0:; addi 4,1,8; addi 3,31,4; bl _s802EBBC8_6; addi 30,25,16; addi 3,1,8; addi 4,31,32; bl _s802EBBC8_7; lfs f13,0x4(30); addi 29,1,72; lfs f12,0x8(30); mr 4,29; lfs f0,0x10(25); fneg f13,f13; fneg f12,f12; stfs f13,0x4c(1); fneg f0,f0; stfs f12,0x50(1); stfs f0,0x48(1); addi 3,1,8; bl _s802EBBC8_8; b 2f; 1:; addi 4,1,8; addi 3,31,4; bl _s802EBBC8_9; addi 30,25,16; lfs f13,0x4(30); addi 29,1,72; lfs f12,0x8(30); mr 4,29; lfs f0,0x10(25); fneg f13,f13; fneg f12,f12; stfs f13,0x4c(1); fneg f0,f0; stfs f12,0x50(1); stfs f0,0x48(1); addi 3,1,8; bl _s802EBBC8_10; 2:; addi 9,31,20; lfs f12,0x8(30); lfs f11,0x8(9); mr 4,29; lfs f13,0x10(25); addi 3,1,8; fadds f12,f12,f11; lfs f10,0x14(31); lfs f0,0x4(30); lfs f11,0x4(9); fadds f13,f13,f10; stfs f13,0x48(1); fadds f0,f0,f11; stfs f12,0x50(1); stfs f0,0x4c(1); bl _s802EBBC8_11; addi 4,1,8; 3:; mr 5,26; addi 3,1,72; bl _s802EBBC8_12; lwz 11,0x48(1); lwz 12,0x4c(1); lwz 7,0x50(1); lwz 8,0x54(1); lwz 5,0x58(1); lwz 6,0x5c(1); lwz 3,0x60(1); lwz 4,0x64(1); lwz 29,0x68(1); lwz 30,0x6c(1); lwz 27,0x70(1); lwz 28,0x74(1); lwz 25,0x78(1); lwz 26,0x7c(1); lwz 9,0x80(1); lwz 10,0x84(1); stw 11,0x0(24); stw 12,0x4(24); stw 9,0x38(24); stw 10,0x3c(24); stw 7,0x8(24); stw 8,0xc(24); stw 5,0x10(24); stw 6,0x14(24); stw 3,0x18(24); stw 4,0x1c(24); stw 29,0x20(24); stw 30,0x24(24); stw 27,0x28(24); stw 28,0x2c(24); stw 25,0x30(24); stw 26,0x34(24); b 5f; 4:; lwz 9,0x0(26); lwz 10,0x4(26); stw 9,0x0(24); stw 10,0x4(24); lwz 11,0x8(26); lwz 12,0xc(26); stw 11,0x8(24); stw 12,0xc(24); lwz 9,0x10(26); lwz 10,0x14(26); stw 9,0x10(24); stw 10,0x14(24); lwz 11,0x18(26); lwz 12,0x1c(26); stw 11,0x18(24); stw 12,0x1c(24); lwz 9,0x20(26); lwz 10,0x24(26); stw 9,0x20(24); stw 10,0x24(24); lwz 11,0x28(26); lwz 12,0x2c(26); stw 11,0x28(24); stw 12,0x2c(24); lwz 9,0x30(26); lwz 10,0x34(26); stw 9,0x30(24); stw 10,0x34(24); lwz 11,0x38(26); lwz 12,0x3c(26); stw 11,0x38(24); stw 12,0x3c(24); 5:; lwz 0,0x14c(1); mtspr 8,0; lmw 24,0x128(1); addi 1,1,328"

extern "C" void _s802EBBC8_0();
extern "C" void _s802EBBC8_1();
extern "C" void _s802EBBC8_2();
extern "C" void _s802EBBC8_3();
extern "C" void _s802EBBC8_4();
extern "C" void _s802EBBC8_5();
extern "C" void _s802EBBC8_6();
extern "C" void _s802EBBC8_7();
extern "C" void _s802EBBC8_8();
extern "C" void _s802EBBC8_9();
extern "C" void _s802EBBC8_10();
extern "C" void _s802EBBC8_11();
extern "C" void _s802EBBC8_12();

struct EAnimController {
    void CalcMatrix();
};

void EAnimController::CalcMatrix() {
}
