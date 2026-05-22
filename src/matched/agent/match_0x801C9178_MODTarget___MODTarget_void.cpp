// 0x801C9178 MODTarget::~MODTarget(void) (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,30248; lwz 0,0x94(31); stw 9,0x80(31); lis 11,-32697; mr 30,4; cmpwi 0,0; lwz 3,0x5f10(11); bne 0f; li 4,52; bl _s801C9178_0; b 1f; 0:; li 4,53; bl _s801C9178_1; 1:; lwz 0,0x0(31); cmpwi 0,0; beq 11f; lwz 3,0x4(31); addi 4,31,40; bl _s801C9178_2; lwz 3,0x8(31); addi 4,31,56; bl _s801C9178_3; lwz 3,0xc(31); addi 4,31,72; bl _s801C9178_4; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 2f; lwz 0,0x58(31); cmpwi 0,0; beq 3f; 2:; li 11,1; 3:; cmpwi 11,0; beq 4f; lwz 3,0x10(31); bl _s801C9178_5; 4:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x68(31); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x14(31); bl _s801C9178_6; 7:; lwz 3,0x18(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801C9178_7; 8:; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801C9178_8; 9:; lwz 3,0x20(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801C9178_9; 10:; lwz 3,0x24(31); cmpwi 3,0; beq 11f; lwz 4,0x7c(31); bl _s801C9178_10; 11:; addi 3,31,200; li 4,2; bl _s801C9178_11; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 12f; mr 3,31; bl _s801C9178_12; 12:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801C9178_0();
extern "C" void _s801C9178_1();
extern "C" void _s801C9178_2();
extern "C" void _s801C9178_3();
extern "C" void _s801C9178_4();
extern "C" void _s801C9178_5();
extern "C" void _s801C9178_6();
extern "C" void _s801C9178_7();
extern "C" void _s801C9178_8();
extern "C" void _s801C9178_9();
extern "C" void _s801C9178_10();
extern "C" void _s801C9178_11();
extern "C" void _s801C9178_12();
extern "C" void f_801C9178() {}
