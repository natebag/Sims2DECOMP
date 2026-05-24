// 0x8008F470 ELiveMode::DrawSplitScreenDivider(ERC (828 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-448(1); mfspr 0,8; stfd f30,0x1b0(1); stfd f31,0x1b8(1); stmw 19,0x17c(1); stw 0,0x1c4(1); lis 30,-32697; mr 31,4; addi 30,30,24012; mr 19,3; lwz 4,0x118(30); mr 3,30; lis 28,-32707; lis 27,-32707; bl _s8008F470_0; lis 9,-32697; mr 3,30; lwz 4,0x5c84(9); addi 29,1,8; addi 20,1,56; addi 21,1,296; addi 30,4,16; addi 22,1,216; bl _s8008F470_1; lis 9,-32707; lfs f1,0x7e6c(28); lfs f2,0x7e70(9); lis 11,-32707; lis 9,-32707; lfs f3,0x7e74(11); lfs f6,0x7e7c(9); addi 23,1,88; lfs f5,0x7e78(27); fmr f4,f1; addi 26,1,168; addi 25,1,248; mr 3,30; bl _s8008F470_2; lfs f31,0x7e6c(28); lis 9,-32707; lfs f0,0x7e80(9); addi 11,1,24; stfs f31,0x8(1); addi 9,1,40; stfs f0,0x8(29); mr 6,9; stfs f31,0x4(29); addi 24,1,328; stfs f31,0x18(1); mr 5,11; stfs f31,0x4(11); mr 3,30; stfs f31,0x8(11); mr 4,29; lfs f30,0x7e78(27); stfs f31,0x28(1); stfs f30,0x4(9); stfs f31,0x8(9); bl _s8008F470_3; stfs f31,0x8(1); mr 3,30; mr 4,29; stfs f31,0x4(29); stfs f30,0xc(29); stfs f30,0x8(29); bl _s8008F470_4; lwz 9,0x9c(30); mr 4,31; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; li 0,4; addi 3,1,136; mtspr 9,0; 0:; bdnz 0b; li 0,0; li 9,127; stw 9,0x74(1); mr 4,20; stw 9,0x50(1); stw 9,0x68(1); stw 9,0x6c(1); stw 9,0x70(1); stw 0,0x84(1); stw 0,0x48(1); stw 0,0x4c(1); stw 0,0x54(1); stw 0,0x78(1); stw 0,0x7c(1); stw 0,0x80(1); bl _s8008F470_5; mr 4,3; mr 3,22; bl _s8008F470_6; mr 4,3; mr 3,21; bl _s8008F470_7; lis 9,-32707; lis 7,-32707; lfs f0,0x7e6c(9); lis 11,-32707; lis 10,-32707; lis 8,-32707; lfs f12,0x7e88(11); lis 9,-32707; lfs f11,0x7e84(7); lfs f10,0x7e8c(10); lfs f9,0x7e74(8); lfs f13,0x7e78(9); stfs f11,0xd8(1); stfs f10,0x128(1); stfs f9,0x12c(1); stfs f12,0x130(1); stfs f11,0x38(1); stfs f0,0x3c(1); stfs f12,0x40(1); stfs f0,0x44(1); stfs f10,0x88(1); stfs f0,0x8c(1); stfs f12,0x90(1); stfs f0,0x94(1); stfs f9,0xdc(1); stfs f12,0xe0(1); stfs f0,0xe4(1); stfs f0,0x134(1); stfs f0,0x58(1); stfs f13,0xc(23); stfs f0,0x4(23); stfs f0,0x8(23); stfs f0,0xa8(1); stfs f13,0xc(26); stfs f13,0x4(26); stfs f0,0x8(26); stfs f13,0xf8(1); stfs f0,0x4(25); stfs f0,0x8(25); stfs f13,0xc(25); lwz 9,0x44(19); stfs f13,0x148(1); stfs f13,0xc(24); stfs f0,0x8(24); stfs f13,0x4(24); lwz 3,0x14(9); cmpwi 3,0; beq 1f; mr 11,3; b 2f; 1:; lwz 9,0x18(9); li 11,0; cmpwi 9,0; beq 2f; lwz 11,0x14(9); 2:; lwz 9,0xf0(11); mr 4,31; li 5,0; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x70(31); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 7,0; li 4,0; li 5,2; lwz 0,0x1cc(9); li 6,0; lha 3,0x1c8(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); li 6,0; li 4,0; li 5,0; lwz 0,0x1dc(9); lha 3,0x1d8(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x70(31); mr 4,20; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; mr 3,19; mr 4,31; mr 5,30; li 6,0; bl _s8008F470_8; lwz 0,0x1c4(1); mtspr 8,0; lmw 19,0x17c(1); lfd f30,0x1b0(1); lfd f31,0x1b8(1); addi 1,1,448"

extern "C" void _s8008F470_0();
extern "C" void _s8008F470_1();
extern "C" void _s8008F470_2();
extern "C" void _s8008F470_3();
extern "C" void _s8008F470_4();
extern "C" void _s8008F470_5();
extern "C" void _s8008F470_6();
extern "C" void _s8008F470_7();
extern "C" void _s8008F470_8();

struct ELiveMode {
    void DrawSplitScreenDivider();
};

void ELiveMode::DrawSplitScreenDivider() {
}
