// 0x801BFCDC M2MTarget::~M2MTarget(void) (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 9,-32698; lis 11,-32698; mr 30,3; addi 9,9,30376; addi 11,11,30424; stw 9,0x108(30); stw 11,0x80(30); lis 9,-32697; mr 25,4; lwz 3,0x5bc0(9); cmpwi 3,0; beq 0f; li 4,1; bl _s801BFCDC_0; 0:; lwz 0,0x168(30); cmpwi 0,5; beq 1f; mr 3,30; bl _s801BFCDC_1; 1:; lwz 0,0x0(30); cmpwi 0,0; beq 11f; lwz 3,0x4(30); addi 4,30,40; bl _s801BFCDC_2; lwz 3,0x8(30); addi 4,30,56; bl _s801BFCDC_3; lwz 3,0xc(30); addi 4,30,72; bl _s801BFCDC_4; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 2f; lwz 0,0x58(30); cmpwi 0,0; beq 3f; 2:; li 11,1; 3:; cmpwi 11,0; beq 4f; lwz 3,0x10(30); bl _s801BFCDC_5; 4:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x68(30); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x14(30); bl _s801BFCDC_6; 7:; lwz 3,0x18(30); cmpwi 3,0; beq 8f; lwz 4,0x7c(30); bl _s801BFCDC_7; 8:; lwz 3,0x1c(30); cmpwi 3,0; beq 9f; lwz 4,0x7c(30); bl _s801BFCDC_8; 9:; lwz 3,0x20(30); cmpwi 3,0; beq 10f; lwz 4,0x7c(30); bl _s801BFCDC_9; 10:; lwz 3,0x24(30); cmpwi 3,0; beq 11f; lwz 4,0x7c(30); bl _s801BFCDC_10; 11:; lwz 11,0x118(30); cmpwi 11,0; beq 12f; lwz 9,0x8(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 12:; li 9,0; addic. 0,30,312; mr 29,0; stw 9,0x118(30); addi 28,30,308; addi 27,30,288; addi 26,30,132; beq 14f; addi 31,30,344; cmpw 29,31; beq 14f; 13:; addi 31,31,-4; li 4,0; mr 3,31; bl _s801BFCDC_11; cmpw 29,31; bne 13b; 14:; mr 3,28; li 4,2; bl _s801BFCDC_12; mr 3,27; li 4,2; bl _s801BFCDC_13; mr 3,26; li 4,0; bl _s801BFCDC_14; lis 9,-32698; andi. 0,25,1; addi 9,9,-12328; stw 9,0x80(30); beq 15f; mr 3,30; bl _s801BFCDC_15; 15:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s801BFCDC_0();
extern "C" void _s801BFCDC_1();
extern "C" void _s801BFCDC_2();
extern "C" void _s801BFCDC_3();
extern "C" void _s801BFCDC_4();
extern "C" void _s801BFCDC_5();
extern "C" void _s801BFCDC_6();
extern "C" void _s801BFCDC_7();
extern "C" void _s801BFCDC_8();
extern "C" void _s801BFCDC_9();
extern "C" void _s801BFCDC_10();
extern "C" void _s801BFCDC_11();
extern "C" void _s801BFCDC_12();
extern "C" void _s801BFCDC_13();
extern "C" void _s801BFCDC_14();
extern "C" void _s801BFCDC_15();
extern "C" void f_801BFCDC() {}
