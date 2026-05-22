// 0x80184A30 ActionQueueHUD::RunEditActionQueue(void) (568 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; bl _s80184A30_0; lwz 4,0x314(28); lwz 3,-26524(13); bl _s80184A30_1; lwz 30,0x310(28); mr 31,3; mr 4,30; bl _s80184A30_2; mr 29,3; mr 4,30; mr 3,31; bl _s80184A30_3; mr 6,3; mr 5,29; mr 3,31; li 4,25; li 7,0; bl _s80184A30_4; cmpwi 3,0; bne 0f; lwz 30,0x310(28); mr 3,31; mr 4,30; bl _s80184A30_5; mr 29,3; mr 4,30; mr 3,31; bl _s80184A30_6; mr 6,3; mr 5,29; mr 3,31; li 4,6; li 7,0; bl _s80184A30_7; cmpwi 3,0; beq 1f; 0:; mr 3,28; bl _s80184A30_8; b 5f; 1:; lwz 30,0x310(28); mr 3,31; mr 4,30; bl _s80184A30_9; mr 29,3; mr 4,30; mr 3,31; bl _s80184A30_10; mr 6,3; mr 5,29; mr 3,31; li 4,1; li 7,0; bl _s80184A30_11; cmpwi 3,0; beq 2f; mr 3,28; bl _s80184A30_12; b 5f; 2:; lwz 30,0x310(28); mr 3,31; mr 4,30; bl _s80184A30_13; mr 29,3; mr 4,30; mr 3,31; bl _s80184A30_14; mr 6,3; mr 5,29; mr 3,31; li 4,2; li 7,0; bl _s80184A30_15; cmpwi 3,0; beq 3f; mr 3,28; bl _s80184A30_16; b 5f; 3:; lwz 30,0x310(28); mr 3,31; mr 4,30; bl _s80184A30_17; mr 29,3; mr 4,30; mr 3,31; bl _s80184A30_18; mr 6,3; mr 5,29; mr 3,31; li 4,5; li 7,0; bl _s80184A30_19; cmpwi 3,0; beq 5f; mr 3,28; bl _s80184A30_20; mr. 30,3; beq 5f; lbz 0,0x319(28); extsb 9,0; cmpwi 9,0; blt 5f; lwz 0,0x150(28); cmpw 9,0; bge 5f; mulli 0,9,20; addi 9,28,168; lwzx 31,9,0; cmpwi 31,0; beq 5f; lwz 4,0x314(28); lwz 3,0x0(28); bl _s80184A30_21; mr 4,31; bl _s80184A30_22; lwz 9,0x4(30); mr 4,31; lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,30,3; blrl; lwz 0,-31536(13); cmpwi 0,0; bne 4f; li 3,120; bl _s80184A30_23; bl _s80184A30_24; stw 3,-31536(13); 4:; lis 4,10927; lwz 3,-31536(13); ori 4,4,62296; bl _s80184A30_25; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80184A30_0();
extern "C" void _s80184A30_1();
extern "C" void _s80184A30_2();
extern "C" void _s80184A30_3();
extern "C" void _s80184A30_4();
extern "C" void _s80184A30_5();
extern "C" void _s80184A30_6();
extern "C" void _s80184A30_7();
extern "C" void _s80184A30_8();
extern "C" void _s80184A30_9();
extern "C" void _s80184A30_10();
extern "C" void _s80184A30_11();
extern "C" void _s80184A30_12();
extern "C" void _s80184A30_13();
extern "C" void _s80184A30_14();
extern "C" void _s80184A30_15();
extern "C" void _s80184A30_16();
extern "C" void _s80184A30_17();
extern "C" void _s80184A30_18();
extern "C" void _s80184A30_19();
extern "C" void _s80184A30_20();
extern "C" void _s80184A30_21();
extern "C" void _s80184A30_22();
extern "C" void _s80184A30_23();
extern "C" void _s80184A30_24();
extern "C" void _s80184A30_25();
extern "C" void f_80184A30() {}
