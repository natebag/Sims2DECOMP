// 0x802202C0 InteractorModule::WallManipulator::FinalizePlacement(void) (688 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 24,0x50(1); stw 0,0x74(1); mr 31,3; addi 28,1,8; lfs f0,0x60(31); addi 9,31,96; lfs f12,0x20(31); addi 11,31,32; stfs f0,0x8(1); addi 27,1,40; lwz 10,-21488(13); addi 26,1,24; lfs f13,0x4(9); mr 25,27; mr 24,26; stfs f13,0x4(28); lfs f0,0x8(9); stfs f0,0x8(28); stfs f12,0x18(1); lfs f0,0x4(11); stfs f0,0x1c(1); lfs f13,0x8(11); stfs f13,0x20(1); lwz 9,0x0(10); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,-21488(13); mr 29,3; lwz 9,0x0(11); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; lis 4,-32704; addi 3,1,64; addi 4,4,-7976; bl _s802202C0_0; addi 7,1,64; mr 5,29; mr 6,30; addi 3,1,40; li 4,8; bl _s802202C0_1; addi 3,1,64; li 4,2; bl _s802202C0_2; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; mr 4,3; mr 3,27; bl _s802202C0_3; li 0,0; mr 4,28; stw 0,0x48(1); mr 3,31; mr 5,26; addi 6,1,72; li 7,1; li 8,0; bl _s802202C0_4; lwz 0,0x48(1); mr 28,3; cmpwi 0,0; beq 6f; lis 9,-32697; li 30,0; addi 3,9,24012; lwz 0,0x3bc(3); cmpwi 0,0; bne 0f; bl _s802202C0_5; cmpwi 3,0; bne 0f; lwz 0,0xc8(31); cmpwi 0,-1; bne 1f; 0:; li 30,1; 1:; cmpwi 30,0; mfcr 30; bne 2f; lwz 0,0xc8(31); cmpw 28,0; ble 2f; addi 3,1,40; b 7f; 2:; li 0,0; mr 5,24; stw 0,0x4c(1); mr 3,31; addi 4,1,8; addi 6,1,76; li 7,1; li 8,0; bl _s802202C0_6; cmpwi 3,0; bne 3f; addi 3,1,40; b 7f; 3:; lis 9,-32697; lwz 4,0xc4(31); addi 29,9,24012; lwz 11,0xc8(29); rlwinm 4,4,24,31,31; lwz 3,0x8(11); bl _s802202C0_7; cmpwi 3,0; beq 5f; mtcrf 128,30; bne 4f; lwz 0,0xc8(31); subf 0,28,0; stw 0,0xc8(31); 4:; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,11,3; blrl; mr 3,29; bl _s802202C0_8; lwz 11,-21424(13); lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; addi 3,1,40; li 4,2; bl _s802202C0_9; li 3,1; b 8f; 5:; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; mr 4,25; bl _s802202C0_10; lwz 11,-21488(13); li 4,0; lwz 9,0x0(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; 6:; mr 3,25; 7:; li 4,2; bl _s802202C0_11; li 3,0; 8:; lwz 0,0x74(1); mtspr 8,0; lmw 24,0x50(1); addi 1,1,112"
extern "C" void _s802202C0_0();
extern "C" void _s802202C0_1();
extern "C" void _s802202C0_2();
extern "C" void _s802202C0_3();
extern "C" void _s802202C0_4();
extern "C" void _s802202C0_5();
extern "C" void _s802202C0_6();
extern "C" void _s802202C0_7();
extern "C" void _s802202C0_8();
extern "C" void _s802202C0_9();
extern "C" void _s802202C0_10();
extern "C" void _s802202C0_11();
extern "C" void f_802202C0() {}
