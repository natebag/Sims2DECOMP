// 0x801E140C SKLTarget::Update(void) (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x84(31); cmpwi 0,0; beq 5f; lwz 0,0x8c(31); cmpwi 0,0; bne 2f; lwz 0,0x90(31); cmpwi 0,0; beq 1f; lwz 0,0x88(31); cmpwi 0,0; bne 2f; addi 3,1,8; lis 30,-32705; bl _s801E140C_0; addi 3,1,8; bl _s801E140C_1; lwz 5,0x94(31); addi 3,1,8; addi 4,30,23028; bl _s801E140C_2; addi 3,1,8; li 4,1; bl _s801E140C_3; lwz 0,0x94(31); cmpwi 0,0; beq 0f; addi 3,1,8; li 4,320; bl _s801E140C_4; 0:; addi 3,1,8; bl _s801E140C_5; lwz 8,0x94(31); lis 7,-32705; addi 3,1,8; addi 7,7,21916; li 5,250; li 6,0; addi 4,30,23028; bl _s801E140C_6; li 4,255; addi 3,1,8; bl _s801E140C_7; addi 3,1,8; bl _s801E140C_8; li 0,1; addi 3,1,8; stw 0,0x88(31); li 4,2; stw 0,0x8c(31); bl _s801E140C_9; b 2f; 1:; lwz 0,0x88(31); cmpwi 0,0; beq 2f; addi 3,1,8; bl _s801E140C_10; lwz 8,0x94(31); lis 4,-32705; lis 7,-32705; addi 3,1,8; addi 7,7,21976; li 5,250; li 6,0; addi 4,4,23028; bl _s801E140C_11; li 4,0; addi 3,1,8; bl _s801E140C_12; addi 3,1,8; bl _s801E140C_13; li 0,1; addi 3,1,8; stw 0,0x8c(31); li 4,2; bl _s801E140C_14; 2:; lwz 9,0x9c(31); lwz 0,0xa0(31); cmpw 9,0; beq 5f; lwz 0,0x98(31); cmpwi 0,0; bne 5f; addi 3,1,8; bl _s801E140C_15; lwz 0,0x9c(31); cmpwi 0,0; beq 3f; lis 30,-32705; lwz 6,0x94(31); addi 3,1,8; addi 4,30,23000; li 5,1; bl _s801E140C_16; lwz 7,-29584(13); addi 3,1,8; lwz 8,0x94(31); addi 4,30,23000; li 5,250; li 6,0; bl _s801E140C_17; addi 3,1,8; li 4,255; bl _s801E140C_18; addi 3,1,8; bl _s801E140C_19; b 4f; 3:; lwz 7,-29572(13); lis 4,-32705; lwz 8,0x94(31); addi 3,1,8; addi 4,4,23000; li 5,250; li 6,0; bl _s801E140C_20; addi 3,1,8; li 4,0; bl _s801E140C_21; addi 3,1,8; bl _s801E140C_22; 4:; li 0,1; addi 3,1,8; stw 0,0x98(31); li 4,2; bl _s801E140C_23; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s801E140C_0();
extern "C" void _s801E140C_1();
extern "C" void _s801E140C_2();
extern "C" void _s801E140C_3();
extern "C" void _s801E140C_4();
extern "C" void _s801E140C_5();
extern "C" void _s801E140C_6();
extern "C" void _s801E140C_7();
extern "C" void _s801E140C_8();
extern "C" void _s801E140C_9();
extern "C" void _s801E140C_10();
extern "C" void _s801E140C_11();
extern "C" void _s801E140C_12();
extern "C" void _s801E140C_13();
extern "C" void _s801E140C_14();
extern "C" void _s801E140C_15();
extern "C" void _s801E140C_16();
extern "C" void _s801E140C_17();
extern "C" void _s801E140C_18();
extern "C" void _s801E140C_19();
extern "C" void _s801E140C_20();
extern "C" void _s801E140C_21();
extern "C" void _s801E140C_22();
extern "C" void _s801E140C_23();
extern "C" void f_801E140C() {}
