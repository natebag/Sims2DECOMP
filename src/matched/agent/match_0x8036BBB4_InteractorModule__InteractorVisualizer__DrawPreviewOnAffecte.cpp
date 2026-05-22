// 0x8036BBB4 InteractorModule::InteractorVisualizer::DrawPreviewOnAffectedWalls(InteractorModule::WallManipulator (1612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stfs f13,0x1e8(1); 0:; lwz 0,0x0(10); addic. 7,7,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(10); mr 8,31; mr 9,20; li 7,1416; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lfs f0,0x114(31); stfs f0,0x1ec(1); lfs f13,0x118(31); stfs f13,0x1f0(1); lfs f0,0x11c(31); stfs f0,0x1f4(1); lfs f13,0x120(31); stfs f13,0x108(1); lfs f0,0x4(25); stfs f0,0x10c(1); lfs f13,0x8(25); stfs f13,0x110(1); lfs f0,0xc(25); stfs f0,0x114(1); lfs f13,0x130(31); stfs f13,0x1f8(1); lfs f0,0x134(31); stfs f0,0x1fc(1); lfs f13,0x138(31); stfs f13,0x200(1); lfs f0,0x13c(31); stfs f0,0x204(1); lfs f13,0x140(31); stfs f13,0x208(1); lfs f0,0x144(31); stfs f0,0x20c(1); 1:; lwz 0,0x0(9); addic. 7,7,-24; stw 0,0x0(8); lwz 0,0x4(9); stw 0,0x4(8); lwz 0,0x8(9); stw 0,0x8(8); lwz 0,0xc(9); stw 0,0xc(8); lwz 0,0x10(9); stw 0,0x10(8); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(8); addi 8,8,24; bne 1b; lwz 0,0x0(9); stw 0,0x0(8); lwz 0,0x6ac(1); mtspr 8,0; lmw 20,0x658(1); lfd f28,0x688(1); lfd f29,0x690(1); lfd f30,0x698(1); lfd f31,0x6a0(1); addi 1,1,1704; blr; stwu 1,-88(1); mfspr 0,8; stmw 25,0x3c(1); stw 0,0x5c(1); mr 29,3; mr 31,4; bl _s8036BBB4_0; lis 3,-32692; li 4,1420; li 5,16; addi 3,3,6092; bl _s8036BBB4_1; mr 0,3; li 4,0; li 5,1420; stw 0,0x14(29); bl _s8036BBB4_2; addi 3,1,8; bl _s8036BBB4_3; lis 5,20545; addi 3,1,8; mr 4,31; ori 5,5,21076; li 6,14; li 7,14; bl _s8036BBB4_4; cmpwi 3,0; beq 2f; addi 3,1,8; bl _s8036BBB4_5; lwz 9,0x18(1); lwz 0,0x10(29); mr 5,9; lwz 4,0x14(29); rlwimi 0,9,8,0,23; stw 0,0x10(29); lwz 9,0x28(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; b 3f; 2:; lwz 9,0x28(31); addi 4,1,32; li 5,20; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; bl _s8036BBB4_6; lwz 4,0x30(1); li 5,0; bl _s8036BBB4_7; lwz 9,0x28(31); mr 30,3; lwz 5,0x30(1); mr 4,30; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; bl _s8036BBB4_8; lwz 5,0x30(1); addi 3,3,1; lwz 0,0x10(29); add 4,30,3; subf 5,3,5; rlwimi 0,5,8,0,23; lwz 3,0x14(29); stw 0,0x10(29); bl _s8036BBB4_9; bl _s8036BBB4_10; mr 4,30; bl _s8036BBB4_11; 3:; lwz 28,0x14(29); lwz 0,0x108(28); andis. 9,0,32; beq 4f; li 0,1; addi 31,28,220; stw 0,0x18(29); mr 3,31; bl _s8036BBB4_12; mr. 4,3; beq 9f; lis 3,-32692; li 5,0; addi 3,3,-27556; b 8f; 4:; andis. 9,0,512; beq 7f; lwz 9,0x168(28); li 27,0; stw 9,0x18(29); lwz 0,0x168(28); cmpw 27,0; bge 11f; lis 25,-32692; li 26,0; addi 31,29,28; addi 30,28,364; 5:; mr 3,30; bl _s8036BBB4_13; mr. 3,3; beq 6f; mr 4,3; li 5,0; addi 3,25,-27556; li 6,0; bl _s8036BBB4_14; 6:; stw 3,0x0(31); addi 9,29,28; lwzx 0,9,26; addi 27,27,1; addi 26,26,4; addi 31,31,4; stw 0,0x0(30); addi 30,30,132; lwz 0,0x168(28); cmpw 27,0; blt 5b; b 11f; 7:; li 0,1; addi 31,28,220; stw 0,0x18(29); mr 3,31; bl _s8036BBB4_15; mr. 4,3; beq 9f; lis 3,-32692; li 5,0; addi 3,3,-17444; 8:; li 6,0; bl _s8036BBB4_16; stw 3,0x1c(29); b 10f; 9:; stw 4,0x1c(29); 10:; lwz 0,0x1c(29); stw 0,0x0(31); lwz 9,0x1c(29); stw 9,0x16c(28); 11:; addi 3,1,8; li 4,2; bl _s8036BBB4_17; lwz 0,0x5c(1); mtspr 8,0; lmw 25,0x3c(1); addi 1,1,88; blr; stwu 1,-72(1); mfspr 0,8; stmw 28,0x38(1); stw 0,0x4c(1); mr 29,3; mr. 31,4; beq 16f; addi 3,1,8; lwz 28,0x14(29); bl _s8036BBB4_18; lis 5,20545; addi 3,1,8; mr 4,31; ori 5,5,21076; li 6,14; li 7,14; bl _s8036BBB4_19; cmpwi 3,0; beq 12f; lwz 9,0x18(1); lwz 0,0x10(29); mr 5,9; lwz 4,0x14(29); rlwimi 0,9,8,0,23; stw 0,0x10(29); lwz 9,0x28(31); lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; b 13f; 12:; lwz 9,0x28(31); addi 4,1,32; li 5,20; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; bl _s8036BBB4_20; lwz 4,0x30(1); li 5,0; bl _s8036BBB4_21; lwz 9,0x28(31); mr 30,3; lwz 5,0x30(1); mr 4,30; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; bl _s8036BBB4_22; lwz 5,0x30(1); addi 3,3,1; lwz 0,0x10(29); add 4,30,3; subf 5,3,5; rlwimi 0,5,8,0,23; lwz 3,0x14(29); stw 0,0x10(29); bl _s8036BBB4_23; bl _s8036BBB4_24; mr 4,30; bl _s8036BBB4_25; 13:; lwz 0,0x18(29); li 10,0; cmpw 10,0; bge 15f; addi 11,28,364; addi 9,29,28; 14:; lwz 0,0x0(9); addi 10,10,1; addi 9,9,4; stw 0,0x0(11); addi 11,11,132; lwz 0,0x18(29); cmpw 10,0; blt 14b; 15:; addi 3,1,8; li 4,2; bl _s8036BBB4_26; 16:; lwz 0,0x4c(1); mtspr 8,0; lmw 28,0x38(1); addi 1,1,72; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 17f; cmpwi 3,0; beq 17f; lis 3,-32688; lis 4,-32713; lis 5,-32713; lis 6,-32713; lis 8,-32702; lis 9,-32688; addi 3,3,-10004; addi 4,4,-16080; addi 5,5,-16040; addi 6,6,-15996; addi 8,8,13432; addi 9,9,-13000; li 7,0; bl _s8036BBB4_27; stw 3,-22400(13); 17:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 3,60; bl _s8036BBB4_28; bl _s8036BBB4_29; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 4,3; li 3,60; bl _s8036BBB4_30; bl _s8036BBB4_31; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,2; bl _s8036BBB4_32; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr. 11,3; beq 18f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 18:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lis 3,-32688; addi 3,3,-10004; blr; lis 9,-32688; lwz 3,-9992(9)"
extern "C" void _s8036BBB4_0();
extern "C" void _s8036BBB4_1();
extern "C" void _s8036BBB4_2();
extern "C" void _s8036BBB4_3();
extern "C" void _s8036BBB4_4();
extern "C" void _s8036BBB4_5();
extern "C" void _s8036BBB4_6();
extern "C" void _s8036BBB4_7();
extern "C" void _s8036BBB4_8();
extern "C" void _s8036BBB4_9();
extern "C" void _s8036BBB4_10();
extern "C" void _s8036BBB4_11();
extern "C" void _s8036BBB4_12();
extern "C" void _s8036BBB4_13();
extern "C" void _s8036BBB4_14();
extern "C" void _s8036BBB4_15();
extern "C" void _s8036BBB4_16();
extern "C" void _s8036BBB4_17();
extern "C" void _s8036BBB4_18();
extern "C" void _s8036BBB4_19();
extern "C" void _s8036BBB4_20();
extern "C" void _s8036BBB4_21();
extern "C" void _s8036BBB4_22();
extern "C" void _s8036BBB4_23();
extern "C" void _s8036BBB4_24();
extern "C" void _s8036BBB4_25();
extern "C" void _s8036BBB4_26();
extern "C" void _s8036BBB4_27();
extern "C" void _s8036BBB4_28();
extern "C" void _s8036BBB4_29();
extern "C" void _s8036BBB4_30();
extern "C" void _s8036BBB4_31();
extern "C" void _s8036BBB4_32();
extern "C" void f_8036BBB4() {}
