// 0x801DAF90 R2LTarget::~R2LTarget(void) (668 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 30,3; lis 11,-32698; lwz 3,0x1e8(30); lis 9,-32698; addi 11,11,28872; addi 9,9,28896; mr 23,4; stw 11,0x84(30); stw 9,0x80(30); cmpwi 3,0; beq 0f; bl _s801DAF90_0; li 0,0; stw 0,0x1e8(30); 0:; lwz 0,0x9c(30); li 29,0; addi 27,30,468; addi 26,30,324; cmpw 29,0; addi 25,30,188; addi 24,30,172; bge 3f; li 28,0; li 31,0; 1:; lwz 9,0x98(30); add 9,31,9; lwz 3,0x8(9); cmpwi 3,0; beq 2f; bl _s801DAF90_1; lwz 9,0x98(30); add 9,31,9; stw 28,0x8(9); 2:; lwz 0,0x9c(30); addi 29,29,1; addi 31,31,28; cmpw 29,0; blt 1b; 3:; lwz 9,0x98(30); cmpwi 9,0; beq 6f; lwz 0,-8(9); mulli 0,0,28; add 31,9,0; cmpw 9,31; beq 5f; 4:; addi 31,31,-28; li 4,2; addi 3,31,16; bl _s801DAF90_2; addi 3,31,12; li 4,2; bl _s801DAF90_3; lwz 0,0x98(30); cmpw 0,31; bne 4b; 5:; lwz 3,0x98(30); addi 3,3,-8; bl _s801DAF90_4; li 0,0; stw 0,0x98(30); 6:; lwz 4,0x8c(30); li 31,0; stw 31,0x9c(30); cmpwi 4,0; beq 7f; li 3,0; bl _s801DAF90_5; stw 31,0x8c(30); 7:; lwz 4,0x90(30); cmpwi 4,0; beq 8f; li 3,1; bl _s801DAF90_6; stw 31,0x90(30); 8:; lis 9,-32697; li 4,34; lwz 3,0x5f10(9); bl _s801DAF90_7; lwz 0,0x0(30); cmpwi 0,0; beq 18f; lwz 3,0x4(30); addi 4,30,40; bl _s801DAF90_8; lwz 3,0x8(30); addi 4,30,56; bl _s801DAF90_9; lwz 3,0xc(30); addi 4,30,72; bl _s801DAF90_10; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 9f; lwz 0,0x58(30); cmpwi 0,0; beq 10f; 9:; li 11,1; 10:; cmpwi 11,0; beq 11f; lwz 3,0x10(30); bl _s801DAF90_11; 11:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 12f; lwz 0,0x68(30); cmpwi 0,0; beq 13f; 12:; li 11,1; 13:; cmpwi 11,0; beq 14f; lwz 3,0x14(30); bl _s801DAF90_12; 14:; lwz 3,0x18(30); cmpwi 3,0; beq 15f; lwz 4,0x7c(30); bl _s801DAF90_13; 15:; lwz 3,0x1c(30); cmpwi 3,0; beq 16f; lwz 4,0x7c(30); bl _s801DAF90_14; 16:; lwz 3,0x20(30); cmpwi 3,0; beq 17f; lwz 4,0x7c(30); bl _s801DAF90_15; 17:; lwz 3,0x24(30); cmpwi 3,0; beq 18f; lwz 4,0x7c(30); bl _s801DAF90_16; 18:; mr 3,27; li 4,2; bl _s801DAF90_17; mr 3,26; li 4,2; bl _s801DAF90_18; mr 3,25; li 4,2; bl _s801DAF90_19; mr 3,24; li 4,2; bl _s801DAF90_20; lis 9,-32698; andi. 0,23,1; addi 9,9,-12328; stw 9,0x80(30); beq 19f; mr 3,30; bl _s801DAF90_21; 19:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s801DAF90_0();
extern "C" void _s801DAF90_1();
extern "C" void _s801DAF90_2();
extern "C" void _s801DAF90_3();
extern "C" void _s801DAF90_4();
extern "C" void _s801DAF90_5();
extern "C" void _s801DAF90_6();
extern "C" void _s801DAF90_7();
extern "C" void _s801DAF90_8();
extern "C" void _s801DAF90_9();
extern "C" void _s801DAF90_10();
extern "C" void _s801DAF90_11();
extern "C" void _s801DAF90_12();
extern "C" void _s801DAF90_13();
extern "C" void _s801DAF90_14();
extern "C" void _s801DAF90_15();
extern "C" void _s801DAF90_16();
extern "C" void _s801DAF90_17();
extern "C" void _s801DAF90_18();
extern "C" void _s801DAF90_19();
extern "C" void _s801DAF90_20();
extern "C" void _s801DAF90_21();
extern "C" void f_801DAF90() {}
