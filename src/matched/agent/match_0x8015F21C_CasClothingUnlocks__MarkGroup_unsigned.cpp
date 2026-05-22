// 0x8015F21C CasClothingUnlocks::MarkGroup(unsigned (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 23,0x1c(1); stw 0,0x44(1); stw 12,0x18(1); mr 29,3; mr 25,4; mr 24,5; mr 26,6; addi 3,1,8; li 31,0; bl _s8015F21C_0; 0:; li 28,1; cmpwi 31,0; bne 1f; li 28,0; 1:; addi 3,1,8; mr 4,28; bl _s8015F21C_1; addi 23,31,1; cmpwi 24,0; li 30,0; mfcr 27; 2:; li 31,0; 3:; addi 3,1,8; mr 4,30; mr 5,31; bl _s8015F21C_2; cmpw 3,25; bne 5f; mtcrf 128,27; beq 4f; mr 3,29; mr 4,28; mr 5,30; mr 6,31; bl _s8015F21C_3; b 5f; 4:; mr 3,29; mr 4,28; mr 5,30; mr 6,31; mr 7,26; bl _s8015F21C_4; 5:; addi 31,31,1; cmpwi 31,39; ble 3b; addi 30,30,1; cmpwi 30,25; ble 2b; li 30,0; cmpwi 4,24,0; 6:; li 31,0; addi 27,30,1; 7:; addi 3,1,8; mr 4,30; mr 5,31; bl _s8015F21C_5; cmpw 3,25; bne 9f; beq cr4,8f; mr 3,29; mr 4,28; mr 5,30; mr 6,31; bl _s8015F21C_6; b 9f; 8:; mr 3,29; mr 4,28; mr 5,30; mr 6,31; mr 7,26; bl _s8015F21C_7; 9:; addi 31,31,1; cmpwi 31,29; ble 7b; mr 30,27; cmpwi 30,2; ble 6b; mr 31,23; cmpwi 31,1; ble 0b; addi 3,1,8; li 4,2; bl _s8015F21C_8; lwz 0,0x44(1); lwz 12,0x18(1); mtspr 8,0; lmw 23,0x1c(1); mtcrf 8,12; addi 1,1,64"
extern "C" void _s8015F21C_0();
extern "C" void _s8015F21C_1();
extern "C" void _s8015F21C_2();
extern "C" void _s8015F21C_3();
extern "C" void _s8015F21C_4();
extern "C" void _s8015F21C_5();
extern "C" void _s8015F21C_6();
extern "C" void _s8015F21C_7();
extern "C" void _s8015F21C_8();
extern "C" void f_8015F21C() {}
