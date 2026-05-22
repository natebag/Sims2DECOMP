// 0x8008CE14 ChangeHouseUnloadHouse::Reset(void) (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 3,-24508(13); cmpwi 3,0; beq 0f; addi 3,3,48; li 4,32; bl _s8008CE14_0; lwz 3,-24508(13); li 4,32; addi 3,3,48; bl _s8008CE14_1; 0:; lwz 3,-21492(13); li 4,3; lis 30,-32697; bl _s8008CE14_2; lwz 11,-21424(13); lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; addi 3,30,24012; bl _s8008CE14_3; li 9,0; addi 30,30,24012; lis 11,-32697; li 0,1; stw 9,0xd0(30); stw 0,0x5c1c(11); bl _s8008CE14_4; lwz 3,-21472(13); bl _s8008CE14_5; lwz 11,-21508(13); lwz 9,0x0(11); lha 3,0xc8(9); lwz 0,0xcc(9); add 3,11,3; mtspr 8,0; blrl; bl _s8008CE14_6; lwz 3,-22708(13); bl _s8008CE14_7; lwz 3,-22704(13); bl _s8008CE14_8; lwz 3,-22700(13); bl _s8008CE14_9; lwz 3,-22708(13); bl _s8008CE14_10; lwz 3,-22704(13); bl _s8008CE14_11; lwz 3,-22700(13); bl _s8008CE14_12; bl _s8008CE14_13; bl _s8008CE14_14; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8008CE14_0();
extern "C" void _s8008CE14_1();
extern "C" void _s8008CE14_2();
extern "C" void _s8008CE14_3();
extern "C" void _s8008CE14_4();
extern "C" void _s8008CE14_5();
extern "C" void _s8008CE14_6();
extern "C" void _s8008CE14_7();
extern "C" void _s8008CE14_8();
extern "C" void _s8008CE14_9();
extern "C" void _s8008CE14_10();
extern "C" void _s8008CE14_11();
extern "C" void _s8008CE14_12();
extern "C" void _s8008CE14_13();
extern "C" void _s8008CE14_14();
extern "C" void f_8008CE14() {}
