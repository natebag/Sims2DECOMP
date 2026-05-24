// 0x8001CB00 CameraDirector::CalcCancelCam(void) (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-192(1); mfspr 0,8; stfd f31,0xb8(1); stmw 24,0x98(1); stw 0,0xc4(1); mr 30,3; addi 25,1,24; addi 24,1,40; lwz 3,0x170(30); addi 4,1,8; mr 5,25; mr 6,24; li 29,0; bl _s8001CB00_0; lwz 3,0x170(30); addi 28,1,56; addi 27,1,120; addi 26,1,136; bl _s8001CB00_1; lis 9,-32707; addi 5,1,72; lfs f0,-6784(9); addi 6,1,88; stw 29,0x160(30); mr 3,30; stw 29,0x24c(30); fmuls f31,f1,f0; mr 4,28; bl _s8001CB00_2; lwz 3,0x170(30); mr 4,28; addi 5,30,256; addi 6,30,268; bl _s8001CB00_3; lwz 11,0x170(30); lis 10,-32707; lfs f0,0x17c(30); lwz 9,0x0(11); lfs f1,-6780(10); stfs f0,0x64(9); lwz 11,0x170(30); lfs f0,0x178(30); lwz 9,0x0(11); stfs f0,0x60(9); lwz 11,0x170(30); lfs f0,0x180(30); lwz 9,0x0(11); stfs f0,0x70(9); lwz 11,0x170(30); lfs f0,0x184(30); lwz 9,0x0(11); stfs f0,0x6c(9); lwz 11,0x170(30); stw 29,0x540(11); lwz 3,0x170(30); bl _s8001CB00_4; lwz 9,0x170(30); li 0,1; addi 4,1,104; mr 5,27; stw 0,0x540(9); mr 6,26; lwz 3,0x170(30); bl _s8001CB00_5; lwz 3,0x170(30); addi 4,1,8; mr 5,27; mr 6,26; bl _s8001CB00_6; lwz 11,0x170(30); lwz 9,0x56c(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; mr 3,30; bl _s8001CB00_7; li 0,7; lwz 3,0x170(30); mr 5,25; mr 6,24; stw 0,0x160(30); addi 4,1,8; bl _s8001CB00_8; mr 3,30; fmr f1,f31; bl _s8001CB00_9; lwz 11,0x170(30); lwz 9,0x56c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x0(30); lwz 10,0x4(30); addi 8,30,128; lwz 11,0x8(30); lwz 12,0xc(30); stw 9,0x80(30); stw 10,0x84(30); stw 11,0x8(8); stw 12,0xc(8); lwz 9,0x10(30); lwz 10,0x14(30); stw 9,0x10(8); stw 10,0x14(8); lwz 11,0x18(30); lwz 12,0x1c(30); stw 11,0x18(8); stw 12,0x1c(8); lwz 9,0x20(30); lwz 10,0x24(30); stw 9,0x20(8); stw 10,0x24(8); lwz 11,0x28(30); lwz 12,0x2c(30); stw 11,0x28(8); stw 12,0x2c(8); lwz 9,0x30(30); lwz 10,0x34(30); stw 9,0x30(8); stw 10,0x34(8); lwz 11,0x38(30); lwz 12,0x3c(30); stw 11,0x38(8); stw 12,0x3c(8); lfs f0,0x174(30); stfs f0,0x1a0(30); lwz 0,0xc4(1); mtspr 8,0; lmw 24,0x98(1); lfd f31,0xb8(1); addi 1,1,192"

extern "C" void _s8001CB00_0();
extern "C" void _s8001CB00_1();
extern "C" void _s8001CB00_2();
extern "C" void _s8001CB00_3();
extern "C" void _s8001CB00_4();
extern "C" void _s8001CB00_5();
extern "C" void _s8001CB00_6();
extern "C" void _s8001CB00_7();
extern "C" void _s8001CB00_8();
extern "C" void _s8001CB00_9();

struct CameraDirector {
    void CalcCancelCam();
};

void CameraDirector::CalcCancelCam() {
}
