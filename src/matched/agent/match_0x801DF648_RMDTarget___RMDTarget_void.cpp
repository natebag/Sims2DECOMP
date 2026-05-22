// 0x801DF648 RMDTarget::~RMDTarget(void) (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32698; mr 30,3; addi 9,9,29928; mr 27,4; stw 9,0x80(30); li 29,0; li 28,0; addi 31,30,140; 0:; lwz 4,0x0(31); cmpwi 4,0; beq 1f; mr 3,29; bl _s801DF648_0; stw 28,0x0(31); 1:; addi 29,29,1; addi 31,31,4; cmpwi 29,1; ble 0b; lwz 0,0x94(30); cmpwi 0,0; beq 2f; li 3,0; bl _s801DF648_1; li 0,0; stw 0,0x94(30); 2:; lwz 0,0x84(30); cmpwi 0,0; beq 4f; lwz 0,0x0(30); lwz 4,-29644(13); cmpwi 0,0; beq 3f; lwz 3,0x20(30); cmpwi 3,0; beq 3f; bl _s801DF648_2; 3:; lis 9,-32697; li 4,67; lwz 3,0x5f10(9); bl _s801DF648_3; li 0,0; stw 0,0x84(30); 4:; lwz 0,0x0(30); cmpwi 0,0; beq 14f; lwz 3,0x4(30); addi 4,30,40; bl _s801DF648_4; lwz 3,0x8(30); addi 4,30,56; bl _s801DF648_5; lwz 3,0xc(30); addi 4,30,72; bl _s801DF648_6; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x58(30); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x10(30); bl _s801DF648_7; 7:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 8f; lwz 0,0x68(30); cmpwi 0,0; beq 9f; 8:; li 11,1; 9:; cmpwi 11,0; beq 10f; lwz 3,0x14(30); bl _s801DF648_8; 10:; lwz 3,0x18(30); cmpwi 3,0; beq 11f; lwz 4,0x7c(30); bl _s801DF648_9; 11:; lwz 3,0x1c(30); cmpwi 3,0; beq 12f; lwz 4,0x7c(30); bl _s801DF648_10; 12:; lwz 3,0x20(30); cmpwi 3,0; beq 13f; lwz 4,0x7c(30); bl _s801DF648_11; 13:; lwz 3,0x24(30); cmpwi 3,0; beq 14f; lwz 4,0x7c(30); bl _s801DF648_12; 14:; addi 3,30,164; li 4,2; bl _s801DF648_13; addi 3,30,160; li 4,2; bl _s801DF648_14; lis 9,-32698; andi. 0,27,1; addi 9,9,-12328; stw 9,0x80(30); beq 15f; mr 3,30; bl _s801DF648_15; 15:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801DF648_0();
extern "C" void _s801DF648_1();
extern "C" void _s801DF648_2();
extern "C" void _s801DF648_3();
extern "C" void _s801DF648_4();
extern "C" void _s801DF648_5();
extern "C" void _s801DF648_6();
extern "C" void _s801DF648_7();
extern "C" void _s801DF648_8();
extern "C" void _s801DF648_9();
extern "C" void _s801DF648_10();
extern "C" void _s801DF648_11();
extern "C" void _s801DF648_12();
extern "C" void _s801DF648_13();
extern "C" void _s801DF648_14();
extern "C" void _s801DF648_15();
extern "C" void f_801DF648() {}
