// 0x800863CC DialogPaneBase::Startup(void) (940 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 24,0x20(1); stw 0,0x44(1); mr 26,3; li 29,0; li 28,1; bl _s800863CC_0; addi 31,26,8; addi 24,1,8; li 3,112; bl _s800863CC_1; lis 9,-32707; mr 30,3; lfs f0,0x7300(9); addi 11,30,32; lis 9,-32698; stw 29,0x0(30); addi 9,9,-11112; stfs f0,0x18(30); stfs f0,0xc(30); mr 3,11; stfs f0,0x10(30); stfs f0,0x14(30); stw 9,0x1c(30); stw 28,0x4(30); stw 29,0x8(30); stw 29,0x24(11); bl _s800863CC_2; mr 3,30; stw 29,0x6c(30); bl _s800863CC_3; mr 3,30; bl _s800863CC_4; lis 9,-32698; mr 3,30; addi 9,9,-11352; stw 9,0x1c(30); bl _s800863CC_5; stw 30,0x60(26); mr 3,30; stw 28,0x4(30); li 4,5; bl _s800863CC_6; lwz 30,0x4(31); lwz 0,0xc(31); lwz 9,0x60(26); cmpw 30,0; stw 9,0x8(1); beq 0f; stw 9,0x0(30); mr 28,31; addi 25,1,20; lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 11f; 0:; lwz 0,0x8(26); addi 10,1,16; stw 28,0x10(1); addi 11,1,12; subf 0,0,30; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 1f; mr 11,10; 1:; lwz 0,0x0(11); add. 0,9,0; beq 3f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 2f; mr 3,27; bl _s800863CC_7; mr 29,3; b 4f; 2:; mr 3,27; bl _s800863CC_8; mr 29,3; b 4f; 3:; li 29,0; li 27,0; 4:; lwz 4,0x0(31); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,29; mr 5,30; bl _s800863CC_9; add 0,3,30; b 6f; 5:; mr 0,29; 6:; lwz 9,0x10(1); mr 30,0; addi 28,26,8; addi 25,1,20; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(24); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s800863CC_10; b 10f; 9:; bl _s800863CC_11; 10:; add 0,27,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 11:; li 3,112; li 29,0; bl _s800863CC_12; li 27,1; lis 9,-32707; mr 30,3; lfs f0,0x7300(9); addi 11,30,32; lis 9,-32698; stw 29,0x0(30); addi 9,9,-11112; stfs f0,0x18(30); stfs f0,0xc(30); mr 3,11; stfs f0,0x10(30); stfs f0,0x14(30); stw 9,0x1c(30); stw 27,0x4(30); stw 29,0x8(30); stw 29,0x24(11); bl _s800863CC_13; mr 3,30; stw 29,0x6c(30); bl _s800863CC_14; mr 3,30; bl _s800863CC_15; lis 9,-32698; mr 3,30; addi 9,9,-11352; stw 9,0x1c(30); bl _s800863CC_16; stw 30,0x64(26); mr 3,30; stw 27,0x4(30); li 4,5; bl _s800863CC_17; lwz 30,0x4(28); lwz 0,0xc(28); lwz 9,0x64(26); cmpw 30,0; stw 9,0x14(1); beq 12f; stw 9,0x0(30); lwz 9,0x4(28); addi 9,9,4; stw 9,0x4(28); b 23f; 12:; lwz 0,0x8(26); addi 11,1,28; stw 27,0x1c(1); addi 9,1,24; subf 0,0,30; srawi 3,0,2; stw 3,0x18(1); cmplwi 3,1; bge 13f; mr 9,11; 13:; lwz 0,0x0(9); add. 0,3,0; beq 15f; rlwinm 0,0,2,0,29; mr 31,0; cmplwi 0,128; ble 14f; mr 3,31; bl _s800863CC_18; mr 29,3; b 16f; 14:; mr 3,31; bl _s800863CC_19; mr 29,3; b 16f; 15:; li 29,0; li 31,0; 16:; lwz 4,0x0(28); cmpw 30,4; beq 17f; subf 30,4,30; mr 3,29; mr 5,30; bl _s800863CC_20; add 0,3,30; b 18f; 17:; mr 0,29; 18:; lwz 9,0x1c(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 20f; 19:; lwz 0,0x0(25); stw 0,0x0(30); addi 30,30,4; bdnz 19b; 20:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 22f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 21f; bl _s800863CC_21; b 22f; 21:; bl _s800863CC_22; 22:; add 0,31,29; stw 29,0x0(28); stw 0,0xc(28); stw 30,0x4(28); 23:; lwz 0,0x44(1); mtspr 8,0; lmw 24,0x20(1); addi 1,1,64"
extern "C" void _s800863CC_0();
extern "C" void _s800863CC_1();
extern "C" void _s800863CC_2();
extern "C" void _s800863CC_3();
extern "C" void _s800863CC_4();
extern "C" void _s800863CC_5();
extern "C" void _s800863CC_6();
extern "C" void _s800863CC_7();
extern "C" void _s800863CC_8();
extern "C" void _s800863CC_9();
extern "C" void _s800863CC_10();
extern "C" void _s800863CC_11();
extern "C" void _s800863CC_12();
extern "C" void _s800863CC_13();
extern "C" void _s800863CC_14();
extern "C" void _s800863CC_15();
extern "C" void _s800863CC_16();
extern "C" void _s800863CC_17();
extern "C" void _s800863CC_18();
extern "C" void _s800863CC_19();
extern "C" void _s800863CC_20();
extern "C" void _s800863CC_21();
extern "C" void _s800863CC_22();
extern "C" void f_800863CC() {}
