// 0x801725DC CasSimRendererDynamic::HandleEventMorphSim(CasEventMorphSimS2C (976 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f30,0x30(1); stfd f31,0x38(1); stmw 29,0x24(1); stw 0,0x44(1); lwz 11,-26392(13); mr 29,3; mr 30,4; addi 31,29,112; lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; addi 3,1,8; mr 4,31; bl _s801725DC_0; lis 9,-32706; lwz 11,0x8(30); lfs f31,0x1e40(9); li 0,-1; lfs f30,0xc(30); cmpwi 11,3; stw 0,0x18(1); stw 0,0x10(1); stfs f31,0xc(1); stfs f31,0x14(1); beq 1f; ble 0f; cmpwi 11,5; beq 6f; blt 2f; cmpwi 11,6; beq 4f; cmpwi 11,7; beq 8f; b 11f; 0:; cmpwi 11,0; blt 11f; cmpwi 11,1; ble 1f; fmr f1,f30; addi 3,1,8; bl _s801725DC_1; b 12f; 1:; lfs f1,0xc(30); addi 3,1,8; lwz 4,0x8(30); bl _s801725DC_2; b 12f; 2:; lwz 3,0x4(31); cmpwi 3,0; beq 12f; lwz 3,0x120(3); cmpwi 3,0; beq 12f; li 4,0; fmr f1,f31; bl _s801725DC_3; lwz 9,0x4(31); li 4,1; fmr f1,f31; lwz 3,0x120(9); bl _s801725DC_4; lwz 9,0x4(31); fmr f1,f31; li 4,2; lwz 3,0x120(9); bl _s801725DC_5; addi 4,1,12; fmr f1,f30; addi 3,1,8; addi 5,1,16; addi 6,1,20; addi 7,1,24; bl _s801725DC_6; lwz 4,0x10(1); cmpwi 4,-1; beq 3f; lwz 9,0x4(31); lfs f1,0xc(1); lwz 3,0x120(9); bl _s801725DC_7; 3:; lwz 4,0x18(1); cmpwi 4,-1; beq 12f; lwz 9,0x4(31); b 10f; 4:; lwz 3,0x4(31); cmpwi 3,0; beq 12f; lwz 3,0x120(3); cmpwi 3,0; beq 12f; li 4,3; fmr f1,f31; bl _s801725DC_8; lwz 9,0x4(31); li 4,4; fmr f1,f31; lwz 3,0x120(9); bl _s801725DC_9; lwz 9,0x4(31); fmr f1,f31; li 4,5; lwz 3,0x120(9); bl _s801725DC_10; addi 4,1,12; fmr f1,f30; addi 3,1,8; addi 5,1,16; addi 6,1,20; addi 7,1,24; bl _s801725DC_11; lwz 4,0x10(1); cmpwi 4,-1; beq 5f; lwz 9,0x4(31); addi 4,4,3; lfs f1,0xc(1); lwz 3,0x120(9); bl _s801725DC_12; 5:; lwz 4,0x18(1); cmpwi 4,-1; beq 12f; lwz 9,0x4(31); addi 4,4,3; b 10f; 6:; lwz 3,0x4(31); cmpwi 3,0; beq 12f; lwz 3,0x120(3); cmpwi 3,0; beq 12f; li 4,6; fmr f1,f31; bl _s801725DC_13; lwz 9,0x4(31); li 4,7; fmr f1,f31; lwz 3,0x120(9); bl _s801725DC_14; lwz 9,0x4(31); fmr f1,f31; li 4,8; lwz 3,0x120(9); bl _s801725DC_15; addi 4,1,12; fmr f1,f30; addi 3,1,8; addi 5,1,16; addi 6,1,20; addi 7,1,24; bl _s801725DC_16; lwz 4,0x10(1); cmpwi 4,-1; beq 7f; lwz 9,0x4(31); addi 4,4,6; lfs f1,0xc(1); lwz 3,0x120(9); bl _s801725DC_17; 7:; lwz 4,0x18(1); cmpwi 4,-1; beq 12f; lwz 9,0x4(31); addi 4,4,6; b 10f; 8:; lwz 3,0x4(31); cmpwi 3,0; beq 12f; lwz 3,0x120(3); cmpwi 3,0; beq 12f; li 4,9; fmr f1,f31; bl _s801725DC_18; lwz 9,0x4(31); li 4,10; fmr f1,f31; lwz 3,0x120(9); bl _s801725DC_19; lwz 9,0x4(31); fmr f1,f31; li 4,11; lwz 3,0x120(9); bl _s801725DC_20; addi 4,1,12; fmr f1,f30; addi 3,1,8; addi 5,1,16; addi 6,1,20; addi 7,1,24; bl _s801725DC_21; lwz 4,0x10(1); cmpwi 4,-1; beq 9f; lwz 9,0x4(31); addi 4,4,9; lfs f1,0xc(1); lwz 3,0x120(9); bl _s801725DC_22; 9:; lwz 4,0x18(1); cmpwi 4,-1; beq 12f; lwz 9,0x4(31); addi 4,4,9; 10:; lfs f1,0x14(1); lwz 3,0x120(9); bl _s801725DC_23; b 12f; 11:; addi 3,1,8; li 4,2; bl _s801725DC_24; b 14f; 12:; lwz 9,0x0(29); lwz 9,0x1c(9); cmpwi 9,0; beq 13f; lwz 0,0x1354(9); cmpwi 0,0; beq 13f; li 4,32; mr 3,29; li 5,32; li 6,8; li 7,0; li 8,0; bl _s801725DC_25; mr 4,3; mr 3,29; bl _s801725DC_26; 13:; addi 3,1,8; li 4,2; bl _s801725DC_27; 14:; lwz 0,0x44(1); mtspr 8,0; lmw 29,0x24(1); lfd f30,0x30(1); lfd f31,0x38(1); addi 1,1,64"
extern "C" void _s801725DC_0();
extern "C" void _s801725DC_1();
extern "C" void _s801725DC_2();
extern "C" void _s801725DC_3();
extern "C" void _s801725DC_4();
extern "C" void _s801725DC_5();
extern "C" void _s801725DC_6();
extern "C" void _s801725DC_7();
extern "C" void _s801725DC_8();
extern "C" void _s801725DC_9();
extern "C" void _s801725DC_10();
extern "C" void _s801725DC_11();
extern "C" void _s801725DC_12();
extern "C" void _s801725DC_13();
extern "C" void _s801725DC_14();
extern "C" void _s801725DC_15();
extern "C" void _s801725DC_16();
extern "C" void _s801725DC_17();
extern "C" void _s801725DC_18();
extern "C" void _s801725DC_19();
extern "C" void _s801725DC_20();
extern "C" void _s801725DC_21();
extern "C" void _s801725DC_22();
extern "C" void _s801725DC_23();
extern "C" void _s801725DC_24();
extern "C" void _s801725DC_25();
extern "C" void _s801725DC_26();
extern "C" void _s801725DC_27();
extern "C" void f_801725DC() {}
