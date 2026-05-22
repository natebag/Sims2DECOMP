// 0x8020135C RELTarget::SetupPageShaders(int) (760 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 22,0x18(1); stw 0,0x44(1); mr 31,3; mr 29,4; addi 3,1,8; bl _s8020135C_0; lis 9,-32700; addi 30,9,-24484; addi 28,30,80; 0:; lwz 0,0x9c(31); cmpwi 0,0; bne 1f; lwz 0,0x0(31); lwz 4,0x0(30); cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lis 5,14705; lwz 6,0x7c(31); ori 5,5,38864; li 7,0; bl _s8020135C_1; b 2f; 1:; lwz 0,0x0(31); lwz 4,0x4(30); cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lis 5,14705; lwz 6,0x7c(31); ori 5,5,38864; li 7,0; bl _s8020135C_2; 2:; addi 30,30,16; cmpw 30,28; ble 0b; mr 4,29; mr 3,31; bl _s8020135C_3; li 26,0; lis 9,-32700; addi 24,1,16; addi 25,9,-24484; mr 30,3; mr 27,25; 3:; addi 9,25,4; addi 11,25,8; lwzx 28,9,26; cmpwi 30,0; lwzx 22,11,26; lwz 29,0x0(27); lwz 23,0xc(27); beq 15f; lwz 3,0x10(30); cmpwi 3,0; beq 4f; lhz 0,0xc(3); bl _s8020135C_4; li 0,0; stw 0,0x10(30); 4:; lis 3,-32697; lwz 4,0x8(30); addi 3,3,24012; bl _s8020135C_5; mr. 3,3; beq 6f; lwz 0,0x9c(31); lwz 5,0x4(3); cmpwi 0,0; bne 5f; lwz 0,0x0(31); cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); mr 4,29; b 10f; 5:; lwz 0,0x0(31); cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); mr 4,28; b 10f; 6:; lwz 9,0xc(30); addi 4,30,16; lwz 3,0xc(9); bl _s8020135C_6; lwz 5,0x10(30); cmpwi 5,0; beq 9f; lwz 0,0x9c(31); lhz 9,0xc(5); cmpwi 0,0; bne 7f; lwz 0,0x0(31); cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); mr 4,29; b 8f; 7:; lwz 0,0x0(31); cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lwz 6,0x7c(31); mr 4,28; 8:; li 7,0; bl _s8020135C_7; b 12f; 9:; lwz 0,0x9c(31); cmpwi 0,0; bne 11f; lwz 0,0x0(31); cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lis 5,14705; lwz 6,0x7c(31); mr 4,29; ori 5,5,38864; 10:; li 7,0; bl _s8020135C_8; b 12f; 11:; lwz 0,0x0(31); cmpwi 0,0; beq 12f; lwz 3,0x1c(31); cmpwi 3,0; beq 12f; lis 5,14705; lwz 6,0x7c(31); mr 4,28; ori 5,5,38864; li 7,0; bl _s8020135C_9; 12:; lwz 5,0x1c(30); lis 4,-32704; addi 4,4,-30836; mr 3,24; crxor 6,6,6; bl _s8020135C_10; addi 3,1,8; mr 4,24; bl _s8020135C_11; lwz 0,0x9c(31); cmpwi 0,0; bne 13f; addi 3,1,8; bl _s8020135C_12; mr 4,3; mr 3,22; bl _s8020135C_13; b 14f; 13:; addi 3,1,8; bl _s8020135C_14; mr 4,3; mr 3,23; bl _s8020135C_15; 14:; lwz 30,0x4(30); 15:; addi 27,27,16; addi 0,25,80; cmpw 27,0; addi 26,26,16; ble 3b; addi 3,1,8; li 4,2; bl _s8020135C_16; lwz 0,0x44(1); mtspr 8,0; lmw 22,0x18(1); addi 1,1,64"
extern "C" void _s8020135C_0();
extern "C" void _s8020135C_1();
extern "C" void _s8020135C_2();
extern "C" void _s8020135C_3();
extern "C" void _s8020135C_4();
extern "C" void _s8020135C_5();
extern "C" void _s8020135C_6();
extern "C" void _s8020135C_7();
extern "C" void _s8020135C_8();
extern "C" void _s8020135C_9();
extern "C" void _s8020135C_10();
extern "C" void _s8020135C_11();
extern "C" void _s8020135C_12();
extern "C" void _s8020135C_13();
extern "C" void _s8020135C_14();
extern "C" void _s8020135C_15();
extern "C" void _s8020135C_16();
extern "C" void f_8020135C() {}
