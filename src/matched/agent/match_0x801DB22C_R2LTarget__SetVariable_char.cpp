// 0x801DB22C R2LTarget::SetVariable(char (776 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 30,4; mr 31,3; lbz 3,0x0(30); mr 29,5; extsb 3,3; bl _s801DB22C_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; lis 9,-32705; mr 4,30; addi 27,9,20088; mr 3,27; bl _s801DB22C_1; cmpwi 3,0; bne 1f; mr 3,29; bl _s801DB22C_2; mr 0,3; cmplwi 0,5; bgt 12f; lwz 4,0xa4(31); mr 3,31; mulli 4,4,6; add 4,4,0; bl _s801DB22C_3; b 12f; 1:; lis 3,-32705; mr 4,30; addi 3,3,20072; bl _s801DB22C_4; cmpwi 3,0; bne 2f; mr 3,31; bl _s801DB22C_5; b 12f; 2:; lis 9,-32705; mr 4,30; addi 28,9,20048; mr 3,28; bl _s801DB22C_6; cmpwi 3,0; bne 5f; mr 3,29; bl _s801DB22C_7; cmpwi 3,2; beq 12f; bgt 3f; cmpwi 3,1; beq 4f; b 12f; 3:; cmpwi 3,3; bne 12f; mr 3,31; bl _s801DB22C_8; cmpwi 3,0; beq 12f; lwz 9,0xa4(31); mr 3,31; addi 0,9,1; stw 9,0xa8(31); stw 0,0xa4(31); bl _s801DB22C_9; lwz 4,0xa0(31); mr 3,31; addi 4,4,6; bl _s801DB22C_10; b 12f; 4:; mr 3,31; bl _s801DB22C_11; cmpwi 3,0; beq 12f; lwz 9,0xa4(31); mr 3,31; addi 0,9,-1; stw 9,0xa8(31); stw 0,0xa4(31); bl _s801DB22C_12; lwz 4,0xa0(31); mr 3,31; addi 4,4,-6; bl _s801DB22C_13; b 12f; 5:; lis 3,-32705; mr 4,30; addi 3,3,20060; bl _s801DB22C_14; cmpwi 3,0; bne 6f; lwz 0,0x1cc(31); cmpwi 0,0; bne 12f; lwz 0,0xb8(31); cmpwi 0,0; bne 12f; lis 9,-32697; lwz 11,0x5ef8(9); cmpwi 11,0; beq 12f; lwz 9,0x80(11); lis 4,-32705; lis 5,-32705; addi 4,4,-5352; lha 3,0x10(9); addi 5,5,-5340; lwz 0,0x14(9); add 3,11,3; b 10f; 6:; lis 3,-32705; mr 4,30; addi 3,3,20228; bl _s801DB22C_15; cmpwi 3,0; bne 7f; lwz 4,0xa0(31); mr 3,31; bl _s801DB22C_16; mr. 3,3; ble 12f; addi 30,1,8; addi 5,3,-1; lis 4,-32705; mr 3,30; addi 4,4,-5236; crxor 6,6,6; bl _s801DB22C_17; lwz 9,0x80(31); mr 4,27; mr 5,30; b 9f; 7:; lis 3,-32705; mr 4,30; addi 3,3,20240; bl _s801DB22C_18; cmpwi 3,0; bne 8f; lwz 4,0xa0(31); mr 3,31; bl _s801DB22C_19; mr. 3,3; blt 12f; cmpwi 3,5; beq 12f; addi 30,1,12; addi 5,3,1; lis 4,-32705; mr 3,30; addi 4,4,-5236; crxor 6,6,6; bl _s801DB22C_20; lwz 9,0x80(31); mr 4,27; mr 5,30; b 9f; 8:; lis 3,-32705; mr 4,30; addi 3,3,20256; bl _s801DB22C_21; cmpwi 3,0; bne 11f; lwz 9,0x80(31); lis 5,-32705; mr 4,28; addi 5,5,-5288; 9:; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; 10:; mtspr 8,0; blrl; b 12f; 11:; lis 3,-32705; mr 4,30; addi 3,3,20272; bl _s801DB22C_22; cmpwi 3,0; bne 12f; lwz 9,0x80(31); lis 5,-32705; mr 4,28; addi 5,5,7784; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s801DB22C_0();
extern "C" void _s801DB22C_1();
extern "C" void _s801DB22C_2();
extern "C" void _s801DB22C_3();
extern "C" void _s801DB22C_4();
extern "C" void _s801DB22C_5();
extern "C" void _s801DB22C_6();
extern "C" void _s801DB22C_7();
extern "C" void _s801DB22C_8();
extern "C" void _s801DB22C_9();
extern "C" void _s801DB22C_10();
extern "C" void _s801DB22C_11();
extern "C" void _s801DB22C_12();
extern "C" void _s801DB22C_13();
extern "C" void _s801DB22C_14();
extern "C" void _s801DB22C_15();
extern "C" void _s801DB22C_16();
extern "C" void _s801DB22C_17();
extern "C" void _s801DB22C_18();
extern "C" void _s801DB22C_19();
extern "C" void _s801DB22C_20();
extern "C" void _s801DB22C_21();
extern "C" void _s801DB22C_22();
extern "C" void f_801DB22C() {}
