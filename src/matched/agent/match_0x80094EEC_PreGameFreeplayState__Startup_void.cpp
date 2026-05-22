// 0x80094EEC PreGameFreeplayState::Startup(void) (304 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,3; lis 30,-32697; lis 5,-32706; addi 4,30,24012; addi 3,1,8; addi 5,5,-31340; crxor 6,6,6; bl _s80094EEC_0; lis 31,-32697; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; lis 3,-32706; addi 3,3,-31360; bl _s80094EEC_1; lis 5,-32706; addi 4,31,24012; addi 3,1,12; addi 5,5,-31296; crxor 6,6,6; bl _s80094EEC_2; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; lis 3,-32706; addi 3,3,-31312; bl _s80094EEC_3; lis 5,-32706; addi 4,31,24012; addi 5,5,-31248; addi 3,1,16; crxor 6,6,6; bl _s80094EEC_4; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; lis 3,-32706; addi 3,3,-31268; bl _s80094EEC_5; lis 5,-32706; addi 4,30,24012; addi 5,5,-31204; addi 3,1,20; crxor 6,6,6; bl _s80094EEC_6; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; lis 3,-32706; addi 3,3,-31220; bl _s80094EEC_7; lis 3,-32706; li 4,3; addi 3,3,-31176; bl _s80094EEC_8; li 3,368; bl _s80094EEC_9; bl _s80094EEC_10; stw 3,0x1c(29); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80094EEC_0();
extern "C" void _s80094EEC_1();
extern "C" void _s80094EEC_2();
extern "C" void _s80094EEC_3();
extern "C" void _s80094EEC_4();
extern "C" void _s80094EEC_5();
extern "C" void _s80094EEC_6();
extern "C" void _s80094EEC_7();
extern "C" void _s80094EEC_8();
extern "C" void _s80094EEC_9();
extern "C" void _s80094EEC_10();
extern "C" void f_80094EEC() {}
