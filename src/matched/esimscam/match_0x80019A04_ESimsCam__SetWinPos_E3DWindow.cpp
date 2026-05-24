// 0x80019A04 ESimsCam::SetWinPos(E3DWindow (1016 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 26,0x78(1); stw 0,0x94(1); mr 31,3; lis 9,-32697; lwz 0,0x4(31); addi 9,9,24012; addi 9,9,280; mr 26,4; rlwinm 0,0,2,0,29; lwzx 9,9,0; cmpwi 9,0; beq 1f; lwz 0,0x160(9); li 9,0; cmpwi 0,0; beq 0f; cmpwi 0,8; beq 0f; li 9,1; 0:; cmpwi 9,0; beq 1f; mr 3,31; addi 29,31,1108; bl _s80019A04_0; addi 30,31,1060; lfs f0,0x418(31); addi 9,31,1048; lfs f12,0x454(31); mr 4,31; stfs f0,0x18(1); addi 3,1,8; addi 5,1,24; addi 6,1,40; lfs f0,0x4(9); addi 7,1,56; lfs f11,0x424(31); stfs f0,0x1c(1); lfs f13,0x8(9); stfs f12,0x28(1); stfs f13,0x20(1); lfs f0,0x4(29); stfs f0,0x2c(1); lfs f13,0x8(29); stfs f11,0x38(1); stfs f13,0x30(1); lfs f0,0x4(30); stfs f0,0x3c(1); lfs f13,0x8(30); stfs f13,0x40(1); bl _s80019A04_1; mr 3,26; mr 5,29; mr 6,30; addi 4,1,8; bl _s80019A04_2; b 14f; 1:; lwz 0,0x554(31); cmpwi 0,2; beq 6f; bgt 2f; cmpwi 0,0; beq 3f; cmpwi 0,1; beq 5f; b 3f; 2:; cmpwi 0,3; beq 7f; cmpwi 0,4; beq 10f; 3:; lis 9,-32697; lwz 0,0x4(31); addi 9,9,24012; rlwinm 0,0,2,0,29; addi 9,9,280; lwzx 11,9,0; lwz 10,0x160(11); cmpwi 10,8; beq 4f; lwz 9,0x0(31); lfs f0,0x8c(9); stfs f0,0x444(31); 4:; lfs f1,-26800(13); mr 3,31; addi 30,31,1108; addi 28,31,1048; bl _s80019A04_3; mr 3,31; addi 4,1,8; mr 5,30; addi 27,1,40; bl _s80019A04_4; lwz 3,0x550(31); mr 5,30; addi 4,1,8; b 9f; 5:; lwz 5,0x558(31); addi 4,31,1084; mr 3,31; addi 30,31,1108; bl _s80019A04_5; addi 28,31,1048; mr 3,31; addi 27,1,40; bl _s80019A04_6; mr 3,31; addi 4,1,8; mr 5,30; bl _s80019A04_7; lwz 3,0x550(31); mr 5,30; addi 4,1,8; b 9f; 6:; addi 4,1,8; lwz 5,0x558(31); mr 29,4; mr 3,31; bl _s80019A04_8; addi 28,31,1048; lwz 5,0x558(31); addi 30,1,40; addi 4,1,24; mr 3,31; bl _s80019A04_9; mr 27,30; lfs f11,0x18(1); addi 10,31,1084; lfs f12,0x8(1); mr 3,31; lfs f13,0x4(29); fadds f12,f12,f11; lfs f0,0x8(29); lfs f10,0x1c(1); lfs f11,0x20(1); stfs f12,0x28(1); fadds f13,f13,f10; fadds f0,f0,f11; stfs f13,0x2c(1); stfs f0,0x30(1); lwz 9,0x28(1); lwz 11,0x4(30); lwz 0,0x8(30); stw 9,0x43c(31); stw 0,0x8(10); stw 11,0x4(10); bl _s80019A04_10; lwz 3,0x550(31); mr 4,29; b 8f; 7:; lwz 5,0x558(31); addi 4,1,8; mr 3,31; addi 28,31,1048; bl _s80019A04_11; lwz 5,0x55c(31); addi 4,31,1084; addi 27,1,40; mr 3,31; bl _s80019A04_12; mr 3,31; bl _s80019A04_13; lwz 3,0x550(31); addi 4,1,8; 8:; addi 5,31,1108; 9:; addi 6,31,1060; bl _s80019A04_14; b 11f; 10:; mr 3,31; addi 30,31,1048; bl _s80019A04_15; mr 28,30; lwz 3,0x550(31); mr 4,30; addi 5,31,1108; addi 6,31,1060; bl _s80019A04_16; li 0,1; addi 27,1,40; stw 0,0x478(31); 11:; lwz 0,0x478(31); cmpwi 0,0; beq 12f; li 0,0; lwz 3,0x550(31); stw 0,0x478(31); bl _s80019A04_17; b 13f; 12:; lwz 3,0x550(31); lfs f1,-26800(13); bl _s80019A04_18; 13:; lwz 9,0x550(31); addi 30,1,72; addi 6,1,88; mr 3,27; lwz 11,0x2c(9); mr 4,31; addi 9,9,44; mr 5,30; lwz 10,0x8(9); addi 7,1,104; lwz 0,0x4(9); stw 11,0x418(31); stw 10,0x8(28); stw 0,0x4(28); lfs f10,0x418(31); lwz 9,0x550(31); stfs f10,0x48(1); addi 11,9,80; addi 10,9,68; lfs f13,0x4(28); stfs f13,0x4c(1); lfs f0,0x8(28); stfs f0,0x50(1); lfs f11,0x50(9); lfs f12,0x8(11); lfs f9,0x4(11); fadds f10,f10,f11; fadds f0,f0,f12; stfs f10,0x58(1); fadds f13,f13,f9; stfs f0,0x60(1); stfs f13,0x5c(1); lfs f0,0x44(9); stfs f0,0x68(1); lfs f13,0x4(10); stfs f13,0x6c(1); lfs f0,0x8(10); stfs f0,0x70(1); bl _s80019A04_19; lwz 6,0x550(31); mr 3,26; lfs f12,0x28(1); mr 4,27; lfs f0,0x50(6); addi 9,6,80; lfs f10,0x8(9); mr 5,30; fadds f12,f12,f0; lfs f11,0x4(9); lfs f13,0x2c(1); addi 6,6,68; lfs f0,0x30(1); fadds f13,f13,f11; stfs f12,0x48(1); fadds f0,f0,f10; stfs f13,0x4c(1); stfs f0,0x50(1); bl _s80019A04_20; 14:; lwz 0,0x94(1); mtspr 8,0; lmw 26,0x78(1); addi 1,1,144"

extern "C" void _s80019A04_0();
extern "C" void _s80019A04_1();
extern "C" void _s80019A04_2();
extern "C" void _s80019A04_3();
extern "C" void _s80019A04_4();
extern "C" void _s80019A04_5();
extern "C" void _s80019A04_6();
extern "C" void _s80019A04_7();
extern "C" void _s80019A04_8();
extern "C" void _s80019A04_9();
extern "C" void _s80019A04_10();
extern "C" void _s80019A04_11();
extern "C" void _s80019A04_12();
extern "C" void _s80019A04_13();
extern "C" void _s80019A04_14();
extern "C" void _s80019A04_15();
extern "C" void _s80019A04_16();
extern "C" void _s80019A04_17();
extern "C" void _s80019A04_18();
extern "C" void _s80019A04_19();
extern "C" void _s80019A04_20();

struct ESimsCam {
    void SetWinPos_E3DWindow();
};

void ESimsCam::SetWinPos_E3DWindow() {
}
