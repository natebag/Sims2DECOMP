// 0x801C6FC4 SetupCAS(void) (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); lis 3,-32705; li 4,0; addi 3,3,3292; lis 30,-32697; bl _s801C6FC4_0; lis 31,-32697; lis 3,-32705; li 4,0; addi 3,3,11448; bl _s801C6FC4_1; lis 5,-32705; addi 4,30,24012; addi 3,1,8; addi 5,5,11460; crxor 6,6,6; bl _s801C6FC4_2; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; lis 3,-32705; addi 3,3,5044; bl _s801C6FC4_3; lis 5,-32705; addi 4,31,24012; addi 3,1,12; addi 5,5,11488; crxor 6,6,6; bl _s801C6FC4_4; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; lis 3,-32705; addi 3,3,5064; bl _s801C6FC4_5; lis 5,-32705; addi 4,31,24012; addi 5,5,11516; addi 3,1,16; crxor 6,6,6; bl _s801C6FC4_6; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; lis 3,-32705; addi 3,3,5080; bl _s801C6FC4_7; lis 5,-32705; addi 4,30,24012; addi 5,5,11544; addi 3,1,20; crxor 6,6,6; bl _s801C6FC4_8; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; lis 3,-32705; addi 3,3,5100; bl _s801C6FC4_9; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s801C6FC4_0();
extern "C" void _s801C6FC4_1();
extern "C" void _s801C6FC4_2();
extern "C" void _s801C6FC4_3();
extern "C" void _s801C6FC4_4();
extern "C" void _s801C6FC4_5();
extern "C" void _s801C6FC4_6();
extern "C" void _s801C6FC4_7();
extern "C" void _s801C6FC4_8();
extern "C" void _s801C6FC4_9();
extern "C" void f_801C6FC4() {}
