// 0x801C5830 MMUTarget::~MMUTarget(void) (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lis 9,-32698; lwz 3,0xac(31); addi 9,9,30704; stw 9,0x80(31); li 30,0; mr 29,4; stw 30,-30180(13); cmpwi 3,0; beq 1f; bl _s801C5830_0; lwz 11,0xac(31); cmpwi 11,0; beq 0f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 0:; stw 30,0xac(31); 1:; lis 9,-32697; li 4,38; lwz 3,0x5f10(9); bl _s801C5830_1; lwz 0,0x0(31); cmpwi 0,0; beq 11f; lwz 3,0x4(31); addi 4,31,40; bl _s801C5830_2; lwz 3,0x8(31); addi 4,31,56; bl _s801C5830_3; lwz 3,0xc(31); addi 4,31,72; bl _s801C5830_4; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 2f; lwz 0,0x58(31); cmpwi 0,0; beq 3f; 2:; li 11,1; 3:; cmpwi 11,0; beq 4f; lwz 3,0x10(31); bl _s801C5830_5; 4:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x68(31); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x14(31); bl _s801C5830_6; 7:; lwz 3,0x18(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801C5830_7; 8:; lwz 3,0x1c(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801C5830_8; 9:; lwz 3,0x20(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801C5830_9; 10:; lwz 3,0x24(31); cmpwi 3,0; beq 11f; lwz 4,0x7c(31); bl _s801C5830_10; 11:; addi 3,31,260; li 4,2; bl _s801C5830_11; addi 3,31,200; li 4,2; bl _s801C5830_12; lis 9,-32698; andi. 0,29,1; addi 9,9,-12328; stw 9,0x80(31); beq 12f; mr 3,31; bl _s801C5830_13; 12:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C5830_0();
extern "C" void _s801C5830_1();
extern "C" void _s801C5830_2();
extern "C" void _s801C5830_3();
extern "C" void _s801C5830_4();
extern "C" void _s801C5830_5();
extern "C" void _s801C5830_6();
extern "C" void _s801C5830_7();
extern "C" void _s801C5830_8();
extern "C" void _s801C5830_9();
extern "C" void _s801C5830_10();
extern "C" void _s801C5830_11();
extern "C" void _s801C5830_12();
extern "C" void _s801C5830_13();
extern "C" void f_801C5830() {}
