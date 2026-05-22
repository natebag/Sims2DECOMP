// 0x8018DE10 SaveGameTarget::PerformMemoryCardChecks(void) (664 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 31,3; li 0,0; lwz 3,0x128(31); addi 4,1,8; stw 0,0x8(1); bl _s8018DE10_0; cmpwi 3,-1; beq 9f; lwz 0,0x8(1); cmpwi 0,0; beq 1f; lwz 0,0x138(31); andi. 9,0,64; beq 0f; addi 3,31,132; bl _s8018DE10_1; li 9,23; li 0,1; stw 0,0x130(31); stw 9,0x12c(31); b 7f; 0:; li 0,2; mr 3,31; stw 0,0x12c(31); bl _s8018DE10_2; b 7f; 1:; lwz 3,0x128(31); li 30,1; stw 30,0xc(1); addi 4,1,12; bl _s8018DE10_3; cmpwi 3,-1; beq 9f; lwz 0,0xc(1); cmpwi 0,0; beq 3f; lwz 0,0x138(31); andi. 9,0,64; beq 2f; addi 3,31,132; bl _s8018DE10_4; li 0,23; stw 30,0x130(31); b 13f; 2:; li 0,3; mr 3,31; stw 0,0x12c(31); bl _s8018DE10_5; b 7f; 3:; lwz 3,0x128(31); li 29,1; stw 29,0x10(1); addi 4,1,16; bl _s8018DE10_6; cmpwi 3,-1; beq 9f; lwz 30,0x10(1); cmpwi 30,0; beq 4f; lwz 0,0x138(31); andi. 9,0,64; bne 12f; li 0,4; mr 3,31; stw 0,0x12c(31); bl _s8018DE10_7; b 7f; 4:; lwz 3,0x128(31); addi 4,1,20; stw 30,0x14(1); bl _s8018DE10_8; mr 0,3; cmpwi 0,-1; beq 9f; cmpwi 0,-6; bne 5f; lwz 0,0x138(31); andi. 9,0,64; bne 12f; li 0,4; mr 3,31; stw 0,0x12c(31); bl _s8018DE10_9; b 7f; 5:; lwz 0,0x14(1); cmpwi 0,0; bne 6f; lwz 0,0x138(31); andi. 9,0,64; bne 12f; li 0,9; mr 3,31; stw 0,0x12c(31); bl _s8018DE10_10; b 7f; 6:; lwz 3,0x128(31); lis 5,171; stw 30,0x18(1); addi 4,1,24; ori 5,5,52719; bl _s8018DE10_11; cmpwi 3,-1; beq 9f; lwz 0,0x18(1); cmpwi 0,0; beq 8f; lwz 0,0x138(31); andi. 9,0,2; bne 15f; li 0,7; mr 3,31; stw 0,0x12c(31); bl _s8018DE10_12; 7:; li 3,0; b 16f; 8:; lwz 3,0x128(31); addi 4,1,28; stw 0,0x1c(1); addi 5,1,32; bl _s8018DE10_13; cmpwi 3,-1; bne 10f; 9:; addi 3,31,132; bl _s8018DE10_14; li 0,21; li 3,0; stw 0,0x12c(31); b 16f; 10:; lwz 0,0x1c(1); cmpwi 0,0; bne 15f; lwz 0,0x138(31); andi. 9,0,32; beq 11f; addi 3,31,132; bl _s8018DE10_15; li 9,23; li 0,7; stw 0,0x110(31); li 3,0; stw 9,0x12c(31); b 16f; 11:; andi. 9,0,64; beq 14f; 12:; addi 3,31,132; bl _s8018DE10_16; li 0,23; stw 29,0x130(31); 13:; stw 0,0x12c(31); b 7b; 14:; li 0,8; mr 3,31; stw 0,0x12c(31); li 4,0; bl _s8018DE10_17; b 7b; 15:; li 3,1; 16:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s8018DE10_0();
extern "C" void _s8018DE10_1();
extern "C" void _s8018DE10_2();
extern "C" void _s8018DE10_3();
extern "C" void _s8018DE10_4();
extern "C" void _s8018DE10_5();
extern "C" void _s8018DE10_6();
extern "C" void _s8018DE10_7();
extern "C" void _s8018DE10_8();
extern "C" void _s8018DE10_9();
extern "C" void _s8018DE10_10();
extern "C" void _s8018DE10_11();
extern "C" void _s8018DE10_12();
extern "C" void _s8018DE10_13();
extern "C" void _s8018DE10_14();
extern "C" void _s8018DE10_15();
extern "C" void _s8018DE10_16();
extern "C" void _s8018DE10_17();
extern "C" void f_8018DE10() {}
