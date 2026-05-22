// 0x801B4BE8 G2DTarget::~G2DTarget(void) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 11,0x88(31); addi 9,9,30768; stw 9,0x80(31); li 0,0; mr 30,4; stw 0,-30368(13); cmpwi 11,0; beq 0f; bl _s801B4BE8_0; lis 9,-32697; li 4,47; lwz 3,0x5f10(9); bl _s801B4BE8_1; 0:; lwz 0,0x0(31); cmpwi 0,0; beq 10f; lwz 3,0x4(31); addi 4,31,40; bl _s801B4BE8_2; lwz 3,0x8(31); addi 4,31,56; bl _s801B4BE8_3; lwz 3,0xc(31); addi 4,31,72; bl _s801B4BE8_4; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 1f; lwz 0,0x58(31); cmpwi 0,0; beq 2f; 1:; li 11,1; 2:; cmpwi 11,0; beq 3f; lwz 3,0x10(31); bl _s801B4BE8_5; 3:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 4f; lwz 0,0x68(31); cmpwi 0,0; beq 5f; 4:; li 11,1; 5:; cmpwi 11,0; beq 6f; lwz 3,0x14(31); bl _s801B4BE8_6; 6:; lwz 3,0x18(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s801B4BE8_7; 7:; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801B4BE8_8; 8:; lwz 3,0x20(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801B4BE8_9; 9:; lwz 3,0x24(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801B4BE8_10; 10:; addi 3,31,312; li 4,2; bl _s801B4BE8_11; addi 3,31,268; li 4,2; bl _s801B4BE8_12; addi 3,31,264; li 4,2; bl _s801B4BE8_13; addi 3,31,260; li 4,2; bl _s801B4BE8_14; addi 3,31,256; li 4,2; bl _s801B4BE8_15; addi 3,31,252; li 4,2; bl _s801B4BE8_16; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 11f; mr 3,31; bl _s801B4BE8_17; 11:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801B4BE8_0();
extern "C" void _s801B4BE8_1();
extern "C" void _s801B4BE8_2();
extern "C" void _s801B4BE8_3();
extern "C" void _s801B4BE8_4();
extern "C" void _s801B4BE8_5();
extern "C" void _s801B4BE8_6();
extern "C" void _s801B4BE8_7();
extern "C" void _s801B4BE8_8();
extern "C" void _s801B4BE8_9();
extern "C" void _s801B4BE8_10();
extern "C" void _s801B4BE8_11();
extern "C" void _s801B4BE8_12();
extern "C" void _s801B4BE8_13();
extern "C" void _s801B4BE8_14();
extern "C" void _s801B4BE8_15();
extern "C" void _s801B4BE8_16();
extern "C" void _s801B4BE8_17();
extern "C" void f_801B4BE8() {}
