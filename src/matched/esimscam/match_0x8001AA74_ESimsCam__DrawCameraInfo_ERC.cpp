// 0x8001AA74 ESimsCam::DrawCameraInfo(ERC (800 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-208(1); mfspr 0,8; stfd f31,0xc8(1); stmw 24,0xa8(1); stw 0,0xd4(1); mr 31,3; mr 25,4; lwz 9,0x0(31); lwz 0,0x1c0(9); cmpwi 0,0; beq 1f; lis 29,-32697; addi 30,1,152; addi 29,29,24012; lwz 3,0x104(29); lis 28,-32707; li 27,0; li 26,1; bl _s8001AA74_0; mr 24,30; lis 9,-32707; lwz 3,0x104(29); lfs f1,-6984(9); li 4,1; lfs f2,-6980(28); bl _s8001AA74_1; lfs f13,-6980(28); lis 4,-32707; lwz 11,0x104(29); addi 3,1,24; stfs f13,0x98(1); addi 4,4,-7096; stfs f13,0xc(30); addi 9,11,88; stfs f13,0x4(30); stfs f13,0x8(30); lfs f0,0x98(1); stfs f0,0x58(11); lfs f13,0x9c(1); stfs f13,0x4(9); lfs f0,0xa0(1); stfs f0,0x8(9); lfs f13,0xa4(1); stfs f13,0xc(9); lfs f1,0x418(31); lfs f2,0x41c(31); lfs f3,0x420(31); creqv 6,6,6; bl _s8001AA74_2; lis 9,-32707; lis 11,-32707; lfs f31,-6976(9); addi 5,1,24; lfs f0,-6972(11); li 9,0; lwz 3,0x104(29); mr 6,30; stfs f31,0x98(1); li 7,0; stfs f0,0x4(30); li 8,0; stw 27,0x8(1); li 10,0; stw 27,0xc(1); mr 4,25; stw 26,0x10(1); bl _s8001AA74_3; lfs f1,0x43c(31); lis 4,-32707; lfs f2,0x440(31); addi 3,1,24; lfs f3,0x444(31); addi 4,4,-7068; creqv 6,6,6; bl _s8001AA74_4; lis 9,-32707; lwz 3,0x104(29); lfs f0,-6968(9); addi 5,1,24; stfs f31,0x98(1); mr 6,30; stfs f0,0x4(30); li 7,0; stw 27,0x8(1); li 8,0; stw 27,0xc(1); li 9,0; stw 26,0x10(1); li 10,0; mr 4,25; bl _s8001AA74_5; mr 3,31; bl _s8001AA74_6; lis 4,-32707; addi 3,1,24; addi 4,4,-7040; creqv 6,6,6; bl _s8001AA74_7; lwz 3,0x104(29); addi 5,1,24; stfs f31,0x98(1); li 9,0; stw 27,0x8(1); mr 6,30; stw 27,0xc(1); li 7,0; stw 26,0x10(1); li 8,0; li 10,0; mr 4,25; stfs f31,0x4(30); bl _s8001AA74_8; lwz 9,0x0(31); lis 4,-32707; addi 3,1,24; addi 4,4,-7028; lfs f1,0x60(9); creqv 6,6,6; bl _s8001AA74_9; lis 9,-32707; lwz 3,0x104(29); lfs f0,-6964(9); addi 5,1,24; stfs f31,0x98(1); li 9,0; stfs f0,0x4(30); mr 6,30; stw 27,0x8(1); li 7,0; stw 27,0xc(1); li 8,0; stw 26,0x10(1); li 10,0; mr 4,25; bl _s8001AA74_10; lwz 9,0x0(31); lis 4,-32707; addi 4,4,-7012; addi 3,1,24; lfs f1,0x64(9); creqv 6,6,6; bl _s8001AA74_11; lis 9,-32707; lwz 3,0x104(29); lfs f0,-6960(9); addi 5,1,24; stfs f31,0x98(1); li 9,0; stfs f0,0x4(30); mr 4,25; stw 27,0xc(1); mr 6,30; stw 26,0x10(1); li 7,0; stw 27,0x8(1); li 8,0; li 10,0; bl _s8001AA74_12; lwz 0,0x4(31); addi 29,29,280; li 5,0; rlwinm 0,0,2,0,29; lwzx 9,29,0; lwz 3,0x160(9); cmpwi 3,0; beq 0f; cmpwi 3,8; beq 0f; li 5,1; 0:; lis 4,-32707; addi 3,1,24; addi 4,4,-6996; crxor 6,6,6; bl _s8001AA74_13; lis 9,-32707; lis 11,-32707; lfs f0,-6976(9); lis 10,-32697; lfs f13,-6956(11); li 9,0; stfs f0,0x98(1); li 0,1; stfs f13,0x4(24); mr 4,25; lwz 3,0x5ed0(10); mr 6,24; stw 9,0xc(1); addi 5,1,24; stw 0,0x10(1); li 7,0; stw 9,0x8(1); li 8,0; li 10,0; bl _s8001AA74_14; 1:; lwz 0,0xd4(1); mtspr 8,0; lmw 24,0xa8(1); lfd f31,0xc8(1); addi 1,1,208"

extern "C" void _s8001AA74_0();
extern "C" void _s8001AA74_1();
extern "C" void _s8001AA74_2();
extern "C" void _s8001AA74_3();
extern "C" void _s8001AA74_4();
extern "C" void _s8001AA74_5();
extern "C" void _s8001AA74_6();
extern "C" void _s8001AA74_7();
extern "C" void _s8001AA74_8();
extern "C" void _s8001AA74_9();
extern "C" void _s8001AA74_10();
extern "C" void _s8001AA74_11();
extern "C" void _s8001AA74_12();
extern "C" void _s8001AA74_13();
extern "C" void _s8001AA74_14();

struct ESimsCam {
    void DrawCameraInfo();
};

void ESimsCam::DrawCameraInfo() {
}
