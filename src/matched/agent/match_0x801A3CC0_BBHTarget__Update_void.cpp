// 0x801A3CC0 BBHTarget::Update(void) (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 1f; lwz 0,0x8c(31); cmpwi 0,0; bne 1f; lwz 0,0x90(31); cmpwi 0,0; beq 0f; lwz 29,0x88(31); cmpwi 29,0; bne 1f; addi 3,1,8; lis 30,-32705; bl _s801A3CC0_0; addi 3,1,8; bl _s801A3CC0_1; addi 3,1,8; li 5,0; addi 4,30,-8524; bl _s801A3CC0_2; addi 3,1,8; li 4,1; bl _s801A3CC0_3; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-8612; bl _s801A3CC0_4; addi 3,1,8; li 4,12; bl _s801A3CC0_5; addi 3,1,8; bl _s801A3CC0_6; lis 7,-32705; addi 3,1,8; addi 7,7,-8708; li 5,250; li 6,0; li 8,0; addi 4,30,-8524; bl _s801A3CC0_7; li 4,255; addi 3,1,8; bl _s801A3CC0_8; addi 3,1,8; bl _s801A3CC0_9; lwz 3,0xa4(31); li 0,1; stw 29,0x9c(31); stw 0,0x8c(31); bl _s801A3CC0_10; addi 3,1,8; li 4,2; bl _s801A3CC0_11; b 1f; 0:; lwz 0,0x88(31); cmpwi 0,0; beq 1f; addi 3,1,8; bl _s801A3CC0_12; lis 4,-32705; lis 7,-32705; addi 3,1,8; addi 7,7,-8668; li 5,250; li 6,0; li 8,0; addi 4,4,-8524; bl _s801A3CC0_13; li 4,0; addi 3,1,8; bl _s801A3CC0_14; addi 3,1,8; bl _s801A3CC0_15; lwz 3,0xa4(31); li 0,1; stw 0,0x8c(31); bl _s801A3CC0_16; addi 3,1,8; li 4,2; bl _s801A3CC0_17; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s801A3CC0_0();
extern "C" void _s801A3CC0_1();
extern "C" void _s801A3CC0_2();
extern "C" void _s801A3CC0_3();
extern "C" void _s801A3CC0_4();
extern "C" void _s801A3CC0_5();
extern "C" void _s801A3CC0_6();
extern "C" void _s801A3CC0_7();
extern "C" void _s801A3CC0_8();
extern "C" void _s801A3CC0_9();
extern "C" void _s801A3CC0_10();
extern "C" void _s801A3CC0_11();
extern "C" void _s801A3CC0_12();
extern "C" void _s801A3CC0_13();
extern "C" void _s801A3CC0_14();
extern "C" void _s801A3CC0_15();
extern "C" void _s801A3CC0_16();
extern "C" void _s801A3CC0_17();
extern "C" void f_801A3CC0() {}
