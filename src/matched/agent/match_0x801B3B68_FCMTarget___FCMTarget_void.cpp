// 0x801B3B68 FCMTarget::~FCMTarget(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,31008; lis 11,-32697; stw 9,0x80(31); mr 30,4; li 4,64; lwz 3,0x5f10(11); bl _s801B3B68_0; lwz 0,0x0(31); cmpwi 0,0; beq 9f; lwz 3,0x4(31); addi 4,31,40; bl _s801B3B68_1; lwz 3,0x8(31); addi 4,31,56; bl _s801B3B68_2; lwz 3,0xc(31); addi 4,31,72; bl _s801B3B68_3; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(31); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(31); bl _s801B3B68_4; 2:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(31); bl _s801B3B68_5; 5:; lwz 3,0x18(31); cmpwi 3,0; beq 6f; lwz 4,0x7c(31); bl _s801B3B68_6; 6:; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s801B3B68_7; 7:; lwz 3,0x20(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801B3B68_8; 8:; lwz 3,0x24(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801B3B68_9; 9:; addi 3,31,168; li 4,2; bl _s801B3B68_10; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 10f; mr 3,31; bl _s801B3B68_11; 10:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B3B68_0();
extern "C" void _s801B3B68_1();
extern "C" void _s801B3B68_2();
extern "C" void _s801B3B68_3();
extern "C" void _s801B3B68_4();
extern "C" void _s801B3B68_5();
extern "C" void _s801B3B68_6();
extern "C" void _s801B3B68_7();
extern "C" void _s801B3B68_8();
extern "C" void _s801B3B68_9();
extern "C" void _s801B3B68_10();
extern "C" void _s801B3B68_11();
extern "C" void f_801B3B68() {}
