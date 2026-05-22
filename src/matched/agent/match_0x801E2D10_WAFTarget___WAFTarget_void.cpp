// 0x801E2D10 WAFTarget::~WAFTarget(void) (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,31224; lwz 11,0x94(30); stw 9,0x80(30); li 0,0; lis 9,-32697; mr 28,4; lwz 3,0x5f10(9); cmpwi 11,0; stw 0,-28736(13); bne 0f; li 4,58; bl _s801E2D10_0; b 1f; 0:; li 4,59; bl _s801E2D10_1; 1:; lwz 0,0x0(30); cmpwi 0,0; beq 11f; lwz 3,0x4(30); addi 4,30,40; bl _s801E2D10_2; lwz 3,0x8(30); addi 4,30,56; bl _s801E2D10_3; lwz 3,0xc(30); addi 4,30,72; bl _s801E2D10_4; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 2f; lwz 0,0x58(30); cmpwi 0,0; beq 3f; 2:; li 11,1; 3:; cmpwi 11,0; beq 4f; lwz 3,0x10(30); bl _s801E2D10_5; 4:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x68(30); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x14(30); bl _s801E2D10_6; 7:; lwz 3,0x18(30); cmpwi 3,0; beq 8f; lwz 4,0x7c(30); bl _s801E2D10_7; 8:; lwz 3,0x1c(30); cmpwi 3,0; beq 9f; lwz 4,0x7c(30); bl _s801E2D10_8; 9:; lwz 3,0x20(30); cmpwi 3,0; beq 10f; lwz 4,0x7c(30); bl _s801E2D10_9; 10:; lwz 3,0x24(30); cmpwi 3,0; beq 11f; lwz 4,0x7c(30); bl _s801E2D10_10; 11:; addi 3,30,592; li 4,2; bl _s801E2D10_11; addic. 0,30,164; mr 29,0; beq 13f; addi 31,30,584; cmpw 29,31; beq 13f; 12:; addi 31,31,-60; li 4,2; addi 3,31,52; bl _s801E2D10_12; cmpw 29,31; bne 12b; 13:; lis 9,-32698; andi. 0,28,1; addi 9,9,-12328; stw 9,0x80(30); beq 14f; mr 3,30; bl _s801E2D10_13; 14:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801E2D10_0();
extern "C" void _s801E2D10_1();
extern "C" void _s801E2D10_2();
extern "C" void _s801E2D10_3();
extern "C" void _s801E2D10_4();
extern "C" void _s801E2D10_5();
extern "C" void _s801E2D10_6();
extern "C" void _s801E2D10_7();
extern "C" void _s801E2D10_8();
extern "C" void _s801E2D10_9();
extern "C" void _s801E2D10_10();
extern "C" void _s801E2D10_11();
extern "C" void _s801E2D10_12();
extern "C" void _s801E2D10_13();
extern "C" void f_801E2D10() {}
