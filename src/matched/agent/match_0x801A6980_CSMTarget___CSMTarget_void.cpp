// 0x801A6980 CSMTarget::~CSMTarget(void) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32698; mr 30,3; addi 9,9,30640; mr 27,4; stw 9,0x80(30); li 28,0; addi 31,30,180; li 29,6; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 1f; li 4,3; bl _s801A6980_0; 1:; stw 28,0x0(31); addic. 29,29,-1; addi 31,31,4; bne 0b; lwz 3,0xb0(30); cmpwi 3,0; beq 2f; li 4,3; bl _s801A6980_1; 2:; stw 29,0xb0(30); lis 9,-32697; lwz 0,0x8c(30); lwz 3,0x5f10(9); cmpwi 0,0; bne 3f; li 4,50; bl _s801A6980_2; b 4f; 3:; li 4,51; bl _s801A6980_3; 4:; lwz 0,0x0(30); cmpwi 0,0; beq 14f; lwz 3,0x4(30); addi 4,30,40; bl _s801A6980_4; lwz 3,0x8(30); addi 4,30,56; bl _s801A6980_5; lwz 3,0xc(30); addi 4,30,72; bl _s801A6980_6; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x58(30); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x10(30); bl _s801A6980_7; 7:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 8f; lwz 0,0x68(30); cmpwi 0,0; beq 9f; 8:; li 11,1; 9:; cmpwi 11,0; beq 10f; lwz 3,0x14(30); bl _s801A6980_8; 10:; lwz 3,0x18(30); cmpwi 3,0; beq 11f; lwz 4,0x7c(30); bl _s801A6980_9; 11:; lwz 3,0x1c(30); cmpwi 3,0; beq 12f; lwz 4,0x7c(30); bl _s801A6980_10; 12:; lwz 3,0x20(30); cmpwi 3,0; beq 13f; lwz 4,0x7c(30); bl _s801A6980_11; 13:; lwz 3,0x24(30); cmpwi 3,0; beq 14f; lwz 4,0x7c(30); bl _s801A6980_12; 14:; lis 9,-32698; andi. 0,27,1; addi 9,9,-12328; stw 9,0x80(30); beq 15f; mr 3,30; bl _s801A6980_13; 15:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801A6980_0();
extern "C" void _s801A6980_1();
extern "C" void _s801A6980_2();
extern "C" void _s801A6980_3();
extern "C" void _s801A6980_4();
extern "C" void _s801A6980_5();
extern "C" void _s801A6980_6();
extern "C" void _s801A6980_7();
extern "C" void _s801A6980_8();
extern "C" void _s801A6980_9();
extern "C" void _s801A6980_10();
extern "C" void _s801A6980_11();
extern "C" void _s801A6980_12();
extern "C" void _s801A6980_13();
extern "C" void f_801A6980() {}
