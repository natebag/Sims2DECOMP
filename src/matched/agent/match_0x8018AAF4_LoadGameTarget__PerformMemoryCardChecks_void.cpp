// 0x8018AAF4 LoadGameTarget::PerformMemoryCardChecks(void) (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 31,3; li 0,0; lwz 3,0x128(31); addi 4,1,8; stw 0,0x8(1); bl _s8018AAF4_0; cmpwi 3,-1; beq 10f; lwz 0,0x8(1); cmpwi 0,0; beq 1f; li 0,8; mr 3,31; stw 0,0x12c(31); bl _s8018AAF4_1; 0:; li 3,0; b 13f; 1:; li 0,1; lwz 3,0x128(31); stw 0,0xc(1); addi 4,1,12; bl _s8018AAF4_2; cmpwi 3,-1; beq 10f; lwz 0,0xc(1); cmpwi 0,0; beq 2f; li 0,9; mr 3,31; stw 0,0x12c(31); bl _s8018AAF4_3; b 0b; 2:; lwz 3,0x128(31); li 29,1; stw 29,0x10(1); addi 4,1,16; bl _s8018AAF4_4; cmpwi 3,-1; beq 10f; lwz 30,0x10(1); cmpwi 30,0; bne 3f; lwz 3,0x128(31); addi 4,1,20; stw 30,0x14(1); bl _s8018AAF4_5; mr 0,3; cmpwi 0,-1; beq 10f; cmpwi 0,-6; bne 4f; 3:; li 0,10; mr 3,31; stw 0,0x12c(31); bl _s8018AAF4_6; b 0b; 4:; lwz 0,0x14(1); cmpwi 0,0; bne 6f; lwz 0,0x138(31); andi. 9,0,1; beq 5f; li 0,25; mr 3,31; stw 0,0x12c(31); bl _s8018AAF4_7; b 0b; 5:; addi 3,31,132; bl _s8018AAF4_8; li 0,3; stw 0,0x10c(31); b 0b; 6:; lwz 3,0x128(31); lis 5,171; stw 30,0x18(1); addi 4,1,24; ori 5,5,52719; bl _s8018AAF4_9; cmpwi 3,-1; beq 10f; lwz 0,0x18(1); cmpwi 0,0; bne 8f; lwz 0,0x138(31); andi. 9,0,1; beq 7f; li 0,25; mr 3,31; stw 0,0x12c(31); bl _s8018AAF4_10; b 0b; 7:; addi 3,31,132; bl _s8018AAF4_11; li 0,3; stw 0,0x10c(31); b 0b; 8:; lwz 3,0x128(31); lis 5,171; stw 29,0x1c(1); addi 4,1,28; ori 5,5,52719; bl _s8018AAF4_12; cmpwi 3,-1; beq 10f; lwz 0,0x1c(1); cmpwi 0,0; beq 9f; li 0,13; mr 3,31; stw 0,0x12c(31); bl _s8018AAF4_13; b 0b; 9:; lwz 0,0x138(31); andi. 9,0,8; beq 12f; lwz 3,0x128(31); addi 4,1,32; stw 29,0x20(1); bl _s8018AAF4_14; cmpwi 3,-1; bne 11f; 10:; addi 3,31,132; bl _s8018AAF4_15; li 0,6; li 3,0; stw 0,0x12c(31); b 13f; 11:; lwz 0,0x20(1); cmpwi 0,0; bne 12f; li 0,12; mr 3,31; stw 0,0x12c(31); bl _s8018AAF4_16; b 0b; 12:; li 3,1; 13:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s8018AAF4_0();
extern "C" void _s8018AAF4_1();
extern "C" void _s8018AAF4_2();
extern "C" void _s8018AAF4_3();
extern "C" void _s8018AAF4_4();
extern "C" void _s8018AAF4_5();
extern "C" void _s8018AAF4_6();
extern "C" void _s8018AAF4_7();
extern "C" void _s8018AAF4_8();
extern "C" void _s8018AAF4_9();
extern "C" void _s8018AAF4_10();
extern "C" void _s8018AAF4_11();
extern "C" void _s8018AAF4_12();
extern "C" void _s8018AAF4_13();
extern "C" void _s8018AAF4_14();
extern "C" void _s8018AAF4_15();
extern "C" void _s8018AAF4_16();
extern "C" void f_8018AAF4() {}
