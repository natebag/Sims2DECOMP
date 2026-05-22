// 0x8034F86C ENgcTexture::Create(ETextureDef (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; bl _s8034F86C_0; lbz 0,0x18(30); cmpwi 0,131; beq 9f; bgt 1f; cmpwi 0,1; beq 10f; bgt 0f; cmpwi 0,0; beq 2f; b 12f; 0:; cmpwi 0,129; beq 6f; cmpwi 0,130; beq 7f; b 12f; 1:; cmpwi 0,133; beq 10f; blt 8f; cmpwi 0,137; beq 5f; cmpwi 0,138; beq 4f; b 12f; 2:; lhz 0,0x1a(30); cmpwi 0,2080; bne 3f; lis 3,-32692; li 4,216; li 5,8; addi 3,3,-7364; bl _s8034F86C_1; bl _s8034F86C_2; b 11f; 3:; cmpwi 0,1056; bne 12f; lis 3,-32692; li 4,212; li 5,8; addi 3,3,-7364; bl _s8034F86C_3; bl _s8034F86C_4; b 11f; 4:; lis 3,-32692; li 4,216; li 5,8; addi 3,3,-7364; bl _s8034F86C_5; bl _s8034F86C_6; b 11f; 5:; lis 3,-32692; li 4,212; li 5,8; addi 3,3,-7364; bl _s8034F86C_7; bl _s8034F86C_8; b 11f; 6:; lis 3,-32692; li 4,156; li 5,8; addi 3,3,-7364; bl _s8034F86C_9; bl _s8034F86C_10; b 11f; 7:; lis 3,-32692; li 4,156; li 5,8; addi 3,3,-7364; bl _s8034F86C_11; bl _s8034F86C_12; b 11f; 8:; lis 3,-32692; li 4,156; li 5,8; addi 3,3,-7364; bl _s8034F86C_13; bl _s8034F86C_14; b 11f; 9:; lis 3,-32692; li 4,156; li 5,8; addi 3,3,-7364; bl _s8034F86C_15; bl _s8034F86C_16; b 11f; 10:; lis 3,-32692; li 4,156; li 5,8; addi 3,3,-7364; bl _s8034F86C_17; bl _s8034F86C_18; 11:; stw 3,0x28(31); 12:; lwz 11,0x28(31); cmpwi 11,0; bne 13f; li 3,0; b 14f; 13:; lwz 9,0x24(11); mr 4,30; lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; 14:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034F86C_0();
extern "C" void _s8034F86C_1();
extern "C" void _s8034F86C_2();
extern "C" void _s8034F86C_3();
extern "C" void _s8034F86C_4();
extern "C" void _s8034F86C_5();
extern "C" void _s8034F86C_6();
extern "C" void _s8034F86C_7();
extern "C" void _s8034F86C_8();
extern "C" void _s8034F86C_9();
extern "C" void _s8034F86C_10();
extern "C" void _s8034F86C_11();
extern "C" void _s8034F86C_12();
extern "C" void _s8034F86C_13();
extern "C" void _s8034F86C_14();
extern "C" void _s8034F86C_15();
extern "C" void _s8034F86C_16();
extern "C" void _s8034F86C_17();
extern "C" void _s8034F86C_18();
extern "C" void f_8034F86C() {}
