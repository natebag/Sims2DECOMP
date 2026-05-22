// 0x8004D6CC ISimsObjectModel::SetupCharacter(void) (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stfd f31,0x48(1); stmw 23,0x24(1); stw 0,0x54(1); mr 28,3; lwz 3,0x328(28); lwz 9,0x4(3); lha 0,0x310(9); lwz 9,0x314(9); add 3,3,0; mtspr 8,9; blrl; lwz 4,0xc0(3); cmpwi 4,0; beq 0f; lwz 4,0x20(4); cmpwi 4,0; beq 0f; addi 3,28,820; li 5,1; li 6,0; bl _s8004D6CC_0; 0:; lwz 9,0x120(28); cmpwi 9,0; beq 6f; lwz 0,0x94(9); cmpwi 0,0; ble 6f; lis 9,-32707; lis 11,-32763; lfs f31,0x31bc(9); addi 23,11,-6384; mr 26,0; li 24,0; li 25,1; addi 29,1,8; li 27,0; 1:; lwz 11,0x120(28); stw 24,0x18(1); lwz 9,0x90(11); lhax 0,9,27; add 31,9,27; cmpwi 0,0; beq 2f; cmpwi 0,1; beq 3f; b 4f; 2:; li 3,208; bl _s8004D6CC_1; bl _s8004D6CC_2; lfs f13,0x18(31); mr 30,3; mr 4,29; stfs f13,0xc4(30); lfs f0,0x18(31); stw 25,0xcc(30); fadds f0,f0,f0; stfs f0,0xc8(30); stfs f31,0x8(1); stfs f31,0x4(29); stfs f31,0x8(29); bl _s8004D6CC_3; stw 30,0x18(1); b 4f; 3:; li 3,184; bl _s8004D6CC_4; bl _s8004D6CC_5; stfs f31,0x8(1); addi 11,3,172; stfs f31,0x4(29); stfs f31,0x8(29); lwz 10,0x4(29); lwz 0,0x8(1); lwz 9,0x8(29); stw 0,0xac(3); stw 9,0x8(11); stw 10,0x4(11); stw 3,0x18(1); 4:; lwz 7,0x18(1); cmpwi 7,0; beq 5f; lwz 8,0x8(31); addi 9,31,8; lwz 10,0x8(9); addi 11,7,144; lwz 0,0x4(9); mr 3,28; stw 8,0x90(7); stw 10,0x8(11); stw 0,0x4(11); lfs f0,0x14(31); stw 24,0xa8(7); stfs f0,0x8c(7); stw 25,0x7c(7); stw 25,0x88(7); stw 24,0x84(7); bl _s8004D6CC_6; lwz 9,0x18(1); stw 3,0x28(9); mr 4,9; stw 23,0x1c(9); lwz 11,0x3c8(28); lwz 3,0x1c(11); bl _s8004D6CC_7; addi 3,28,1124; addi 4,1,24; bl _s8004D6CC_8; 5:; addi 27,27,28; addic. 26,26,-1; bne 1b; 6:; lwz 0,0x54(1); mtspr 8,0; lmw 23,0x24(1); lfd f31,0x48(1); addi 1,1,80"
extern "C" void _s8004D6CC_0();
extern "C" void _s8004D6CC_1();
extern "C" void _s8004D6CC_2();
extern "C" void _s8004D6CC_3();
extern "C" void _s8004D6CC_4();
extern "C" void _s8004D6CC_5();
extern "C" void _s8004D6CC_6();
extern "C" void _s8004D6CC_7();
extern "C" void _s8004D6CC_8();
extern "C" void f_8004D6CC() {}
