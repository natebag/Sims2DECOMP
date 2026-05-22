// 0x8003C798 GameData::SystemPreUpdate(void) (700 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 9,-32697; mr 29,3; addi 31,9,24012; lwz 3,0x110(31); cmpwi 3,0; beq 0f; li 4,0; bl _s8003C798_0; lwz 3,0x110(31); li 4,1; bl _s8003C798_1; 0:; li 0,0; lwz 3,-26524(13); stw 0,0x2c(29); li 4,0; bl _s8003C798_2; mr. 3,3; beq 6f; lwz 30,-26524(13); li 4,0; mr 3,30; bl _s8003C798_3; mr 4,3; mr 3,30; bl _s8003C798_4; lwz 9,0x208(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; andi. 3,3,5; cmpwi 3,5; beq 1f; li 0,1; stw 0,0x30(29); 1:; lwz 0,0x30(29); cmpwi 0,0; beq 7f; lwz 3,-26524(13); li 4,1; li 31,1; bl _s8003C798_5; cmpwi 3,0; beq 2f; lwz 0,0x34(29); cmpwi 0,0; bne 2f; lwz 3,-26524(13); li 4,1; bl _s8003C798_6; extsb 28,3; b 3f; 2:; li 28,-1; 3:; li 30,0; cmpwi 31,0; beq 7f; 4:; cmpw 30,28; beq 5f; lwz 3,-26524(13); mr 4,30; bl _s8003C798_7; bl _s8003C798_8; cmpwi 3,0; beq 5f; lwz 3,-26524(13); li 31,0; stw 31,0x30(29); li 4,0; bl _s8003C798_9; mr 4,3; mr 5,30; lwz 3,-26524(13); bl _s8003C798_10; 5:; addi 0,30,1; extsb 30,0; cmpwi 30,4; bge 7f; cmpwi 31,0; bne 4b; b 7f; 6:; stw 3,0x30(29); 7:; lwz 3,-26524(13); li 4,1; bl _s8003C798_11; mr. 3,3; beq 13f; lwz 30,-26524(13); li 4,1; mr 3,30; bl _s8003C798_12; mr 4,3; mr 3,30; bl _s8003C798_13; lwz 9,0x208(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; andi. 3,3,5; cmpwi 3,5; beq 8f; li 0,1; stw 0,0x34(29); 8:; lwz 0,0x34(29); cmpwi 0,0; beq 14f; lwz 3,-26524(13); li 4,0; li 31,1; bl _s8003C798_14; cmpwi 3,0; beq 9f; lwz 0,0x30(29); cmpwi 0,0; bne 9f; lwz 3,-26524(13); li 4,0; bl _s8003C798_15; extsb 28,3; b 10f; 9:; li 28,-1; 10:; li 30,0; cmpwi 31,0; beq 14f; 11:; cmpw 30,28; beq 12f; lwz 3,-26524(13); mr 4,30; bl _s8003C798_16; bl _s8003C798_17; cmpwi 3,0; beq 12f; lwz 3,-26524(13); li 31,0; stw 31,0x34(29); li 4,1; bl _s8003C798_18; mr 4,3; mr 5,30; lwz 3,-26524(13); bl _s8003C798_19; 12:; addi 0,30,1; extsb 30,0; cmpwi 30,4; bge 14f; cmpwi 31,0; bne 11b; b 14f; 13:; stw 3,0x34(29); 14:; bl _s8003C798_20; cmpwi 3,4; blt 16f; cmpwi 3,6; ble 15f; cmpwi 3,11; bne 16f; 15:; li 3,0; b 18f; 16:; lis 9,-32697; lwz 3,0x5ee0(9); cmpwi 3,0; beq 17f; bl _s8003C798_21; 17:; li 3,1; 18:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8003C798_0();
extern "C" void _s8003C798_1();
extern "C" void _s8003C798_2();
extern "C" void _s8003C798_3();
extern "C" void _s8003C798_4();
extern "C" void _s8003C798_5();
extern "C" void _s8003C798_6();
extern "C" void _s8003C798_7();
extern "C" void _s8003C798_8();
extern "C" void _s8003C798_9();
extern "C" void _s8003C798_10();
extern "C" void _s8003C798_11();
extern "C" void _s8003C798_12();
extern "C" void _s8003C798_13();
extern "C" void _s8003C798_14();
extern "C" void _s8003C798_15();
extern "C" void _s8003C798_16();
extern "C" void _s8003C798_17();
extern "C" void _s8003C798_18();
extern "C" void _s8003C798_19();
extern "C" void _s8003C798_20();
extern "C" void _s8003C798_21();
extern "C" void f_8003C798() {}
