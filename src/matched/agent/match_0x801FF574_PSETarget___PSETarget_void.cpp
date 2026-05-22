// 0x801FF574 PSETarget::~PSETarget(void) (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 0,0x84(31); addi 9,9,31288; mr 30,4; stw 9,0x80(31); cmpwi 0,0; beq 0f; lwz 11,-21496(13); lwz 9,0x0(11); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x84(31); 0:; lwz 3,-24508(13); cmpwi 3,0; beq 1f; bl _s801FF574_0; 1:; mr 3,31; bl _s801FF574_1; lwz 0,0x0(31); cmpwi 0,0; beq 11f; lwz 3,0x4(31); addi 4,31,40; bl _s801FF574_2; lwz 3,0x8(31); addi 4,31,56; bl _s801FF574_3; lwz 3,0xc(31); addi 4,31,72; bl _s801FF574_4; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 2f; lwz 0,0x58(31); cmpwi 0,0; beq 3f; 2:; li 11,1; 3:; cmpwi 11,0; beq 4f; lwz 3,0x10(31); bl _s801FF574_5; 4:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x68(31); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x14(31); bl _s801FF574_6; 7:; lwz 3,0x18(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801FF574_7; 8:; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801FF574_8; 9:; lwz 3,0x20(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801FF574_9; 10:; lwz 3,0x24(31); cmpwi 3,0; beq 11f; lwz 4,0x7c(31); bl _s801FF574_10; 11:; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 12f; mr 3,31; bl _s801FF574_11; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801FF574_0();
extern "C" void _s801FF574_1();
extern "C" void _s801FF574_2();
extern "C" void _s801FF574_3();
extern "C" void _s801FF574_4();
extern "C" void _s801FF574_5();
extern "C" void _s801FF574_6();
extern "C" void _s801FF574_7();
extern "C" void _s801FF574_8();
extern "C" void _s801FF574_9();
extern "C" void _s801FF574_10();
extern "C" void _s801FF574_11();
extern "C" void f_801FF574() {}
