// 0x801A4848 CRDTarget::~CRDTarget(void) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 0,0x98(31); addi 9,9,30880; mr 30,4; stw 9,0x80(31); cmpwi 0,0; beq 0f; bl _s801A4848_0; li 0,0; stw 0,0x98(31); 0:; lwz 11,0xc8(31); cmpwi 11,0; beq 1f; lwz 9,0x9c(11); li 4,3; lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0xc8(31); 1:; lwz 0,0xa0(31); cmpwi 0,0; beq 2f; mr 3,31; bl _s801A4848_1; 2:; lwz 0,0x88(31); cmpwi 0,0; beq 3f; lis 9,-32697; li 4,42; lwz 3,0x5f10(9); bl _s801A4848_2; 3:; lwz 0,0x0(31); cmpwi 0,0; beq 13f; lwz 3,0x4(31); addi 4,31,40; bl _s801A4848_3; lwz 3,0x8(31); addi 4,31,56; bl _s801A4848_4; lwz 3,0xc(31); addi 4,31,72; bl _s801A4848_5; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 4f; lwz 0,0x58(31); cmpwi 0,0; beq 5f; 4:; li 11,1; 5:; cmpwi 11,0; beq 6f; lwz 3,0x10(31); bl _s801A4848_6; 6:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 7f; lwz 0,0x68(31); cmpwi 0,0; beq 8f; 7:; li 11,1; 8:; cmpwi 11,0; beq 9f; lwz 3,0x14(31); bl _s801A4848_7; 9:; lwz 3,0x18(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801A4848_8; 10:; lwz 3,0x1c(31); cmpwi 3,0; beq 11f; lwz 4,0x7c(31); bl _s801A4848_9; 11:; lwz 3,0x20(31); cmpwi 3,0; beq 12f; lwz 4,0x7c(31); bl _s801A4848_10; 12:; lwz 3,0x24(31); cmpwi 3,0; beq 13f; lwz 4,0x7c(31); bl _s801A4848_11; 13:; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 14f; mr 3,31; bl _s801A4848_12; 14:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801A4848_0();
extern "C" void _s801A4848_1();
extern "C" void _s801A4848_2();
extern "C" void _s801A4848_3();
extern "C" void _s801A4848_4();
extern "C" void _s801A4848_5();
extern "C" void _s801A4848_6();
extern "C" void _s801A4848_7();
extern "C" void _s801A4848_8();
extern "C" void _s801A4848_9();
extern "C" void _s801A4848_10();
extern "C" void _s801A4848_11();
extern "C" void _s801A4848_12();
extern "C" void f_801A4848() {}
