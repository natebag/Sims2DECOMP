// 0x800D86E8 NghResFile::CopyHouse(int, (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-424(1); mfspr 0,8; stmw 20,0x178(1); stw 0,0x1ac(1); mr 27,3; mr 26,5; addi 3,1,8; mr 24,4; mr 31,6; addi 4,3,8; li 5,64; bl _s800D86E8_0; addi 30,1,88; addi 29,1,368; addi 3,1,80; bl _s800D86E8_1; addi 28,1,360; addi 4,1,96; li 5,260; addi 3,1,88; bl _s800D86E8_2; lwz 9,0xc(26); mr 4,30; lha 3,0x58(9); lwz 0,0x5c(9); add 3,26,3; mtspr 8,0; blrl; mr 3,30; bl _s800D86E8_3; mr 4,3; addi 3,1,360; bl _s800D86E8_4; mr 3,29; mr 4,28; bl _s800D86E8_5; lwz 4,0x170(1); addi 3,1,80; bl _s800D86E8_6; lwz 4,0x170(1); mr 3,29; bl _s800D86E8_7; lwz 4,0x168(1); mr 3,28; bl _s800D86E8_8; lwz 4,0x50(1); mr 3,26; bl _s800D86E8_9; cmpwi 3,0; beq 0f; lwz 4,0x50(1); addi 3,1,80; bl _s800D86E8_10; li 3,0; b 10f; 0:; mr 3,26; mr 4,31; li 5,0; li 6,0; bl _s800D86E8_11; mr 30,3; cmpwi 30,1; bne 9f; addi 0,24,-1; addi 25,31,-1; addi 22,26,316; rlwinm 31,0,2,0,29; addi 28,27,316; li 26,0; li 29,0; li 30,6; 1:; lwzx 9,28,31; lwzx 3,29,9; bl _s800D86E8_12; lwzx 9,28,31; addic. 30,30,-1; stwx 26,29,9; addi 29,29,4; bne 1b; lwz 9,0x24(27); mr 3,27; mr 4,24; rlwinm 23,25,2,0,29; addi 21,9,1; li 30,0; bl _s800D86E8_13; lis 20,-32702; 2:; lwzx 11,22,23; rlwinm 9,30,2,0,29; mr 31,9; addi 28,30,1; lwzx 29,9,11; cmpwi 29,0; beq 8f; addi 25,20,16696; li 26,0; 3:; lwz 9,0xc(27); addi 7,1,8; lwz 4,0x4(29); li 8,0; lha 3,0xf8(9); lwz 0,0xfc(9); lwzx 5,25,31; add 3,27,3; lha 6,0x8(29); mtspr 8,0; blrl; lwz 30,0x4(29); bl _s800D86E8_14; li 4,12; li 5,0; bl _s800D86E8_15; cmpwi 30,0; beq 4f; lwz 0,0x0(30); stw 0,0x0(3); b 5f; 4:; stw 30,0x0(3); 5:; cmpwi 30,0; beq 6f; lwz 0,0x4(30); stw 0,0x4(3); b 7f; 6:; stw 30,0x4(3); 7:; stw 26,0x8(3); stw 3,0x4(29); lwz 29,0x0(29); cmpwi 29,0; bne 3b; 8:; mr 30,28; cmpwi 30,5; ble 2b; mr 4,21; mr 3,27; bl _s800D86E8_16; mr 4,24; mr 3,27; li 5,0; bl _s800D86E8_17; mr 30,3; cmpwi 30,1; bne 9f; li 4,0; mr 3,27; bl _s800D86E8_18; mr 30,3; 9:; lwz 4,0x50(1); addi 3,1,80; bl _s800D86E8_19; mr 3,30; 10:; lwz 0,0x1ac(1); mtspr 8,0; lmw 20,0x178(1); addi 1,1,424"
extern "C" void _s800D86E8_0();
extern "C" void _s800D86E8_1();
extern "C" void _s800D86E8_2();
extern "C" void _s800D86E8_3();
extern "C" void _s800D86E8_4();
extern "C" void _s800D86E8_5();
extern "C" void _s800D86E8_6();
extern "C" void _s800D86E8_7();
extern "C" void _s800D86E8_8();
extern "C" void _s800D86E8_9();
extern "C" void _s800D86E8_10();
extern "C" void _s800D86E8_11();
extern "C" void _s800D86E8_12();
extern "C" void _s800D86E8_13();
extern "C" void _s800D86E8_14();
extern "C" void _s800D86E8_15();
extern "C" void _s800D86E8_16();
extern "C" void _s800D86E8_17();
extern "C" void _s800D86E8_18();
extern "C" void _s800D86E8_19();
extern "C" void f_800D86E8() {}
