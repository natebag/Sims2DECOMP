// 0x801993DC CASSelectionTarget::~CASSelectionTarget(void) (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 9,-32698; lis 11,-32698; mr 30,3; addi 9,9,27976; addi 11,11,28072; stw 9,0x88(30); stw 11,0x80(30); mr 25,4; li 27,0; li 26,0; addi 29,30,1428; li 28,0; 0:; lwz 3,0x0(29); cmpwi 3,0; beq 1f; bl _s801993DC_0; stw 26,0x0(29); 1:; addi 31,30,1364; lwzx 3,31,28; cmpwi 3,0; beq 2f; bl _s801993DC_1; stwx 26,31,28; 2:; addi 27,27,1; addi 29,29,4; addi 28,28,4; cmplwi 27,15; ble 0b; lwz 3,0x5d4(30); cmpwi 3,0; beq 3f; bl _s801993DC_2; li 0,0; stw 0,0x5d4(30); 3:; lwz 0,0x0(30); cmpwi 0,0; beq 13f; lwz 3,0x4(30); addi 4,30,40; bl _s801993DC_3; lwz 3,0x8(30); addi 4,30,56; bl _s801993DC_4; lwz 3,0xc(30); addi 4,30,72; bl _s801993DC_5; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 4f; lwz 0,0x58(30); cmpwi 0,0; beq 5f; 4:; li 11,1; 5:; cmpwi 11,0; beq 6f; lwz 3,0x10(30); bl _s801993DC_6; 6:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 7f; lwz 0,0x68(30); cmpwi 0,0; beq 8f; 7:; li 11,1; 8:; cmpwi 11,0; beq 9f; lwz 3,0x14(30); bl _s801993DC_7; 9:; lwz 3,0x18(30); cmpwi 3,0; beq 10f; lwz 4,0x7c(30); bl _s801993DC_8; 10:; lwz 3,0x1c(30); cmpwi 3,0; beq 11f; lwz 4,0x7c(30); bl _s801993DC_9; 11:; lwz 3,0x20(30); cmpwi 3,0; beq 12f; lwz 4,0x7c(30); bl _s801993DC_10; 12:; lwz 3,0x24(30); cmpwi 3,0; beq 13f; lwz 4,0x7c(30); bl _s801993DC_11; 13:; lis 9,-32698; lis 11,-32698; addi 9,9,24424; addi 11,11,-12328; stw 9,0x88(30); andi. 0,25,1; stw 11,0x80(30); beq 14f; mr 3,30; bl _s801993DC_12; 14:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s801993DC_0();
extern "C" void _s801993DC_1();
extern "C" void _s801993DC_2();
extern "C" void _s801993DC_3();
extern "C" void _s801993DC_4();
extern "C" void _s801993DC_5();
extern "C" void _s801993DC_6();
extern "C" void _s801993DC_7();
extern "C" void _s801993DC_8();
extern "C" void _s801993DC_9();
extern "C" void _s801993DC_10();
extern "C" void _s801993DC_11();
extern "C" void _s801993DC_12();
extern "C" void f_801993DC() {}
