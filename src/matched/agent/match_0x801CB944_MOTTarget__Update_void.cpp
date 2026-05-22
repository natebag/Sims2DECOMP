// 0x801CB944 MOTTarget::Update(void) (532 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 6f; lwz 0,0x15c(31); cmpwi 0,0; bne 2f; lwz 0,0x160(31); cmpwi 0,0; beq 1f; lwz 0,0x88(31); cmpwi 0,0; bne 2f; addi 3,1,8; lis 30,-32705; bl _s801CB944_0; addi 3,1,8; bl _s801CB944_1; lwz 5,0x8c(31); addi 3,1,8; addi 4,30,14096; bl _s801CB944_2; addi 3,1,8; li 4,1; bl _s801CB944_3; lwz 0,0x8c(31); cmpwi 0,0; beq 0f; addi 3,1,8; li 4,320; bl _s801CB944_4; 0:; addi 3,1,8; bl _s801CB944_5; lwz 7,-29968(13); addi 3,1,8; lwz 8,0x8c(31); li 5,250; li 6,0; addi 4,30,14096; bl _s801CB944_6; li 4,255; addi 3,1,8; bl _s801CB944_7; addi 3,1,8; bl _s801CB944_8; li 0,1; addi 3,1,8; stw 0,0x88(31); li 4,2; stw 0,0x15c(31); bl _s801CB944_9; b 2f; 1:; lwz 0,0x88(31); cmpwi 0,0; beq 2f; addi 3,1,8; bl _s801CB944_10; lwz 7,-29956(13); lis 4,-32705; lwz 8,0x8c(31); addi 3,1,8; li 5,250; li 6,0; addi 4,4,14096; bl _s801CB944_11; li 4,0; addi 3,1,8; bl _s801CB944_12; addi 3,1,8; bl _s801CB944_13; li 0,1; addi 3,1,8; stw 0,0x15c(31); li 4,2; bl _s801CB944_14; 2:; lwz 9,0x94(31); lwz 0,0x98(31); cmpw 9,0; beq 6f; addi 3,1,8; bl _s801CB944_15; lwz 0,0x90(31); cmpwi 0,0; bne 5f; lwz 0,0x94(31); cmpwi 0,0; beq 3f; lis 30,-32705; lwz 6,0x8c(31); addi 3,1,8; addi 4,30,14068; li 5,1; bl _s801CB944_16; lwz 7,-29992(13); addi 3,1,8; lwz 8,0x8c(31); addi 4,30,14068; li 5,250; li 6,0; bl _s801CB944_17; addi 3,1,8; li 4,255; bl _s801CB944_18; addi 3,1,8; bl _s801CB944_19; b 4f; 3:; lwz 7,-29980(13); lis 4,-32705; lwz 8,0x8c(31); addi 3,1,8; addi 4,4,14068; li 5,250; li 6,0; bl _s801CB944_20; addi 3,1,8; li 4,0; bl _s801CB944_21; addi 3,1,8; bl _s801CB944_22; 4:; li 0,1; stw 0,0x90(31); 5:; addi 3,1,8; li 4,2; bl _s801CB944_23; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801CB944_0();
extern "C" void _s801CB944_1();
extern "C" void _s801CB944_2();
extern "C" void _s801CB944_3();
extern "C" void _s801CB944_4();
extern "C" void _s801CB944_5();
extern "C" void _s801CB944_6();
extern "C" void _s801CB944_7();
extern "C" void _s801CB944_8();
extern "C" void _s801CB944_9();
extern "C" void _s801CB944_10();
extern "C" void _s801CB944_11();
extern "C" void _s801CB944_12();
extern "C" void _s801CB944_13();
extern "C" void _s801CB944_14();
extern "C" void _s801CB944_15();
extern "C" void _s801CB944_16();
extern "C" void _s801CB944_17();
extern "C" void _s801CB944_18();
extern "C" void _s801CB944_19();
extern "C" void _s801CB944_20();
extern "C" void _s801CB944_21();
extern "C" void _s801CB944_22();
extern "C" void _s801CB944_23();
extern "C" void f_801CB944() {}
