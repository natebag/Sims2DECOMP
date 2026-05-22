// 0x801AFCD8 FAMTarget::SetVariable(char (480 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); mr 29,5; extsb 3,3; bl _s801AFCD8_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lwz 3,-30424(13); mr 4,31; bl _s801AFCD8_1; cmpwi 3,0; bne 1f; mr 3,30; bl _s801AFCD8_2; b 10f; 1:; lwz 3,-30428(13); mr 4,31; bl _s801AFCD8_3; cmpwi 3,0; bne 2f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_4; b 10f; 2:; lwz 3,-30412(13); mr 4,31; bl _s801AFCD8_5; cmpwi 3,0; bne 3f; mr 3,30; mr 4,29; bl _s801AFCD8_6; b 10f; 3:; lis 3,-32705; mr 4,31; addi 3,3,-416; bl _s801AFCD8_7; cmpwi 3,0; bne 4f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_8; b 10f; 4:; lis 3,-32705; mr 4,31; addi 3,3,-400; bl _s801AFCD8_9; cmpwi 3,0; bne 5f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_10; b 10f; 5:; lis 3,-32705; mr 4,31; addi 3,3,-356; bl _s801AFCD8_11; cmpwi 3,0; bne 6f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_12; b 10f; 6:; lis 3,-32705; mr 4,31; addi 3,3,-436; bl _s801AFCD8_13; cmpwi 3,0; bne 7f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_14; b 10f; 7:; lis 28,-32705; mr 4,31; addi 3,28,-384; bl _s801AFCD8_15; cmpwi 3,0; bne 8f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_16; b 10f; 8:; lis 3,-32705; mr 4,31; addi 3,3,-372; bl _s801AFCD8_17; cmpwi 3,0; bne 9f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_18; b 10f; 9:; addi 3,28,-384; mr 4,31; bl _s801AFCD8_19; cmpwi 3,0; bne 10f; mr 3,30; mr 4,31; mr 5,29; bl _s801AFCD8_20; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801AFCD8_0();
extern "C" void _s801AFCD8_1();
extern "C" void _s801AFCD8_2();
extern "C" void _s801AFCD8_3();
extern "C" void _s801AFCD8_4();
extern "C" void _s801AFCD8_5();
extern "C" void _s801AFCD8_6();
extern "C" void _s801AFCD8_7();
extern "C" void _s801AFCD8_8();
extern "C" void _s801AFCD8_9();
extern "C" void _s801AFCD8_10();
extern "C" void _s801AFCD8_11();
extern "C" void _s801AFCD8_12();
extern "C" void _s801AFCD8_13();
extern "C" void _s801AFCD8_14();
extern "C" void _s801AFCD8_15();
extern "C" void _s801AFCD8_16();
extern "C" void _s801AFCD8_17();
extern "C" void _s801AFCD8_18();
extern "C" void _s801AFCD8_19();
extern "C" void _s801AFCD8_20();
extern "C" void f_801AFCD8() {}
