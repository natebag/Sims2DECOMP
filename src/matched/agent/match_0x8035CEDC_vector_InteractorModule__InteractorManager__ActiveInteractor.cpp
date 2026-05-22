// 0x8035CEDC vector<InteractorModule::InteractorManager::ActiveInteractor, (824 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,28,64; addi 31,31,4; bl _s8035CEDC_0; mr 4,31; li 5,4; addi 3,28,68; addi 31,31,4; bl _s8035CEDC_1; lwz 4,0x44(28); addi 3,28,72; li 5,0; bl _s8035CEDC_2; lwz 0,0x44(28); cmpw 29,0; bge 1f; li 27,0; 0:; lwz 30,0x48(28); mr 4,31; li 5,4; addi 31,31,4; add 30,30,27; addi 29,29,1; mr 3,30; addi 27,27,96; bl _s8035CEDC_3; mr 4,31; li 5,12; addi 3,30,4; addi 31,31,12; bl _s8035CEDC_4; mr 4,31; li 5,64; addi 3,30,16; addi 31,31,64; bl _s8035CEDC_5; mr 4,31; li 5,4; addi 3,30,80; addi 31,31,4; bl _s8035CEDC_6; mr 4,31; li 5,4; addi 3,30,84; addi 31,31,4; bl _s8035CEDC_7; mr 4,31; li 5,4; addi 3,30,88; addi 31,31,4; bl _s8035CEDC_8; mr 4,31; addi 3,30,92; li 5,4; addi 31,31,4; bl _s8035CEDC_9; lwz 0,0x44(28); cmpw 29,0; blt 0b; 1:; addi 3,1,8; mr 4,28; bl _s8035CEDC_10; li 29,0; li 30,0; addi 27,1,8; b 4f; 2:; lbzx 0,27,30; cmpwi 0,32; beq 3f; stbx 0,28,29; addi 29,29,1; 3:; addi 30,30,1; 4:; addi 3,1,8; bl _s8035CEDC_11; cmpw 30,3; blt 2b; li 0,0; stbx 0,28,29; subf 3,26,31; lwz 0,0x6c(1); mtspr 8,0; lmw 26,0x50(1); addi 1,1,104; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 11,4; mr 30,3; lwz 9,0x54(11); mr 4,30; lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 11,4; mr 30,3; lwz 9,0x54(11); mr 4,30; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 31,4; addi 3,29,72; mr 30,5; lwz 0,0x4(3); cmpw 31,0; ble 5f; addi 4,31,1; li 5,0; bl _s8035CEDC_12; 5:; mulli 9,31,96; lwz 7,0x48(29); lwz 0,0x0(30); addi 10,30,4; addi 6,30,16; stwx 0,7,9; add 7,7,9; lwz 0,0x4(30); addi 5,7,4; lwz 11,0x4(10); addi 8,7,16; lwz 9,0x8(10); stw 0,0x4(7); stw 9,0x8(5); stw 11,0x4(5); lwz 9,0x10(30); lwz 10,0x14(30); stw 9,0x10(7); stw 10,0x14(7); lwz 11,0x8(6); lwz 12,0xc(6); stw 11,0x8(8); stw 12,0xc(8); lwz 9,0x10(6); lwz 10,0x14(6); stw 9,0x10(8); stw 10,0x14(8); lwz 11,0x18(6); lwz 12,0x1c(6); stw 11,0x18(8); stw 12,0x1c(8); lwz 9,0x20(6); lwz 10,0x24(6); stw 9,0x20(8); stw 10,0x24(8); lwz 11,0x28(6); lwz 12,0x2c(6); stw 11,0x28(8); stw 12,0x2c(8); lwz 9,0x30(6); lwz 10,0x34(6); stw 9,0x30(8); stw 10,0x34(8); lwz 11,0x38(6); lwz 12,0x3c(6); stw 11,0x38(8); stw 12,0x3c(8); lfs f0,0x50(30); stfs f0,0x50(7); lfs f13,0x54(30); stfs f13,0x54(7); lfs f0,0x58(30); stfs f0,0x58(7); lfs f13,0x5c(30); stfs f13,0x5c(7); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 5,64; bl _s8035CEDC_13; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stw 4,0x40(3)"
extern "C" void _s8035CEDC_0();
extern "C" void _s8035CEDC_1();
extern "C" void _s8035CEDC_2();
extern "C" void _s8035CEDC_3();
extern "C" void _s8035CEDC_4();
extern "C" void _s8035CEDC_5();
extern "C" void _s8035CEDC_6();
extern "C" void _s8035CEDC_7();
extern "C" void _s8035CEDC_8();
extern "C" void _s8035CEDC_9();
extern "C" void _s8035CEDC_10();
extern "C" void _s8035CEDC_11();
extern "C" void _s8035CEDC_12();
extern "C" void _s8035CEDC_13();
extern "C" void f_8035CEDC() {}
