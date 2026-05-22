// 0x80188BDC TArray<EVec3, (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="bl _s80188BDC_0; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32; blr; stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,3; mr 30,4; mr 29,5; mr 28,6; mr 27,7; mr 26,8; bl _s80188BDC_1; mulli 30,30,180; mr 4,29; mr 5,28; mr 6,27; mr 7,26; addi 30,30,1856; add 3,25,30; bl _s80188BDC_2; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40; blr; stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 23,3; mr 30,4; mr 29,5; mr 28,6; mr 27,7; mr 26,8; mr 25,9; lwz 24,0x38(1); bl _s80188BDC_3; mulli 30,30,180; mr 4,29; mr 5,28; mr 6,27; mr 7,26; mr 8,25; mr 9,24; addi 30,30,1856; add 3,23,30; bl _s80188BDC_4; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; addi 31,30,1856; mr 3,31; bl _s80188BDC_5; cmpwi 3,0; beq 0f; mr 3,31; bl _s80188BDC_6; 0:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 1f; addi 31,30,2036; mr 4,29; mr 3,31; bl _s80188BDC_7; cmpwi 3,0; beq 1f; mr 3,31; bl _s80188BDC_8; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s80188BDC_9; mulli 30,30,180; addi 30,30,1856; add 3,29,30; bl _s80188BDC_10; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; bl _s80188BDC_11; mulli 30,30,180; addi 30,30,1856; add 3,29,30; bl _s80188BDC_12; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80188BDC_0();
extern "C" void _s80188BDC_1();
extern "C" void _s80188BDC_2();
extern "C" void _s80188BDC_3();
extern "C" void _s80188BDC_4();
extern "C" void _s80188BDC_5();
extern "C" void _s80188BDC_6();
extern "C" void _s80188BDC_7();
extern "C" void _s80188BDC_8();
extern "C" void _s80188BDC_9();
extern "C" void _s80188BDC_10();
extern "C" void _s80188BDC_11();
extern "C" void _s80188BDC_12();
extern "C" void f_80188BDC() {}
