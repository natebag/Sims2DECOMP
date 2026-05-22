// 0x801BA500 INGTarget::~INGTarget(void) (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lis 11,-32698; lis 10,-32698; lwz 0,0x0(31); addi 9,9,29776; addi 11,11,29752; addi 10,10,29800; mr 30,4; stw 9,0x84(31); stw 11,0x88(31); cmpwi 0,0; stw 10,0x80(31); beq 9f; lwz 3,0x4(31); addi 4,31,40; bl _s801BA500_0; lwz 3,0x8(31); addi 4,31,56; bl _s801BA500_1; lwz 3,0xc(31); addi 4,31,72; bl _s801BA500_2; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(31); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(31); bl _s801BA500_3; 2:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(31); bl _s801BA500_4; 5:; lwz 3,0x18(31); cmpwi 3,0; beq 6f; lwz 4,0x7c(31); bl _s801BA500_5; 6:; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s801BA500_6; 7:; lwz 3,0x20(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801BA500_7; 8:; lwz 3,0x24(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801BA500_8; 9:; lis 9,-32697; li 4,25; lwz 3,0x5f10(9); bl _s801BA500_9; lwz 4,0x9c(31); li 3,0; bl _s801BA500_10; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 10f; lwz 4,0xa0(31); li 3,1; bl _s801BA500_11; 10:; li 3,0; bl _s801BA500_12; addi 3,31,164; li 4,2; bl _s801BA500_13; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 11f; mr 3,31; bl _s801BA500_14; 11:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801BA500_0();
extern "C" void _s801BA500_1();
extern "C" void _s801BA500_2();
extern "C" void _s801BA500_3();
extern "C" void _s801BA500_4();
extern "C" void _s801BA500_5();
extern "C" void _s801BA500_6();
extern "C" void _s801BA500_7();
extern "C" void _s801BA500_8();
extern "C" void _s801BA500_9();
extern "C" void _s801BA500_10();
extern "C" void _s801BA500_11();
extern "C" void _s801BA500_12();
extern "C" void _s801BA500_13();
extern "C" void _s801BA500_14();
extern "C" void f_801BA500() {}
