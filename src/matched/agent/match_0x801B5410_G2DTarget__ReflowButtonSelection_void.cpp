// 0x801B5410 G2DTarget::ReflowButtonSelection(void) (788 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; addi 3,31,312; bl _s801B5410_0; li 0,3; lwz 10,0xb0(31); mtspr 9,0; li 11,0; addi 9,1,8; 0:; xor 0,10,11; subfic 8,0,0; adde 0,8,0; stw 0,0x0(9); addi 11,11,1; addi 9,9,4; bdnz 0b; lwz 0,0xc8(31); cmpwi 0,0; bne 6f; lwz 0,0x150(31); addi 30,31,312; lwz 9,0x8(1); cmpw 0,9; beq 2f; lis 4,-32705; stw 9,0x150(31); addi 4,4,3172; mr 3,30; li 5,0; bl _s801B5410_1; lwz 0,0x8(1); li 4,1; cmpwi 0,0; bne 1f; li 4,0; 1:; mr 3,30; bl _s801B5410_2; 2:; lwz 0,0x154(31); lwz 9,0xc(1); cmpw 0,9; beq 4f; lis 4,-32705; stw 9,0x154(31); addi 4,4,3184; mr 3,30; li 5,0; bl _s801B5410_3; lwz 0,0xc(1); li 4,1; cmpwi 0,0; bne 3f; li 4,0; 3:; mr 3,30; bl _s801B5410_4; 4:; lwz 0,0x158(31); lwz 9,0x10(1); cmpw 0,9; beq 12f; lis 4,-32705; stw 9,0x158(31); addi 4,4,3196; mr 3,30; li 5,0; bl _s801B5410_5; lwz 0,0x10(1); li 4,1; cmpwi 0,0; bne 5f; li 4,0; 5:; mr 3,30; bl _s801B5410_6; b 12f; 6:; lwz 0,0x168(31); addi 30,31,312; lwz 9,0x8(1); cmpw 0,9; beq 8f; lis 4,-32705; stw 9,0x168(31); addi 4,4,3208; mr 3,30; li 5,0; bl _s801B5410_7; lwz 0,0x8(1); li 4,1; cmpwi 0,0; bne 7f; li 4,0; 7:; mr 3,30; bl _s801B5410_8; 8:; lwz 0,0x16c(31); lwz 9,0xc(1); cmpw 0,9; beq 10f; lis 4,-32705; stw 9,0x16c(31); addi 4,4,3224; mr 3,30; li 5,0; bl _s801B5410_9; lwz 0,0xc(1); li 4,1; cmpwi 0,0; bne 9f; li 4,0; 9:; mr 3,30; bl _s801B5410_10; 10:; lwz 0,0x170(31); lwz 9,0x10(1); cmpw 0,9; beq 12f; lis 4,-32705; stw 9,0x170(31); addi 4,4,3240; mr 3,30; li 5,0; bl _s801B5410_11; lwz 0,0x10(1); li 4,1; cmpwi 0,0; bne 11f; li 4,0; 11:; mr 3,30; bl _s801B5410_12; 12:; lwz 0,0x15c(31); lwz 9,0x8(1); cmpw 0,9; beq 14f; lis 4,-32705; stw 9,0x15c(31); addi 4,4,3256; mr 3,30; li 5,0; bl _s801B5410_13; lwz 0,0xb0(31); cmpwi 0,0; bne 13f; mr 3,30; li 4,-1; bl _s801B5410_14; b 14f; 13:; lis 4,1286; mr 3,30; ori 4,4,29183; bl _s801B5410_15; 14:; lwz 0,0x160(31); lwz 9,0xc(1); cmpw 0,9; beq 16f; lis 4,-32705; stw 9,0x160(31); addi 4,4,3268; mr 3,30; li 5,0; bl _s801B5410_16; lwz 0,0xb0(31); cmpwi 0,1; bne 15f; mr 3,30; li 4,-1; bl _s801B5410_17; b 16f; 15:; lis 4,1286; mr 3,30; ori 4,4,29183; bl _s801B5410_18; 16:; lwz 0,0x164(31); lwz 9,0x10(1); cmpw 0,9; beq 18f; lis 4,-32705; stw 9,0x164(31); addi 4,4,3280; mr 3,30; li 5,0; bl _s801B5410_19; lwz 0,0xb0(31); cmpwi 0,2; bne 17f; mr 3,30; li 4,-1; bl _s801B5410_20; b 18f; 17:; lis 4,1286; mr 3,30; ori 4,4,29183; bl _s801B5410_21; 18:; mr 3,30; bl _s801B5410_22; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s801B5410_0();
extern "C" void _s801B5410_1();
extern "C" void _s801B5410_2();
extern "C" void _s801B5410_3();
extern "C" void _s801B5410_4();
extern "C" void _s801B5410_5();
extern "C" void _s801B5410_6();
extern "C" void _s801B5410_7();
extern "C" void _s801B5410_8();
extern "C" void _s801B5410_9();
extern "C" void _s801B5410_10();
extern "C" void _s801B5410_11();
extern "C" void _s801B5410_12();
extern "C" void _s801B5410_13();
extern "C" void _s801B5410_14();
extern "C" void _s801B5410_15();
extern "C" void _s801B5410_16();
extern "C" void _s801B5410_17();
extern "C" void _s801B5410_18();
extern "C" void _s801B5410_19();
extern "C" void _s801B5410_20();
extern "C" void _s801B5410_21();
extern "C" void _s801B5410_22();
extern "C" void f_801B5410() {}
