// 0x800CAB20 Neighbor::SpawnWantFearDialog(unsigned (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-184(1); mfspr 0,8; stmw 22,0x90(1); stw 0,0xbc(1); lis 9,-32697; mr 24,3; addi 10,9,24012; lwz 9,0x118(10); lwz 31,0x320(9); cmpwi 31,0; bne 2f; rlwinm 0,4,2,0,29; addi 9,24,408; lwzx 23,9,0; cmpwi 23,0; beq 2f; lis 9,-32697; addi 22,9,23428; lwz 0,0x48(22); cmpwi 0,0; beq 2f; lwz 11,0x18(24); cmpwi 11,0; beq 2f; lwz 0,0xbc(10); cmpw 11,0; beq 0f; lwz 0,0xc0(10); cmpw 11,0; bne 2f; 0:; lis 9,-32698; addi 25,1,8; addi 9,9,30832; addi 29,1,48; stw 9,0x84(25); li 0,1; stw 31,0x8(1); li 9,-1; addi 28,1,56; addi 27,1,60; addi 26,1,64; stw 9,0x18(25); stw 0,0x14(25); mr 3,29; stw 31,0x4(25); lis 30,-32706; stw 31,0x8(25); stw 31,0xc(25); stw 31,0x10(25); stw 31,0x1c(25); stw 31,0x20(25); stw 31,0x24(25); bl _s800CAB20_0; addi 3,1,52; bl _s800CAB20_1; mr 3,28; bl _s800CAB20_2; mr 3,27; bl _s800CAB20_3; mr 3,26; bl _s800CAB20_4; li 0,3; stw 31,0x3c(25); stw 0,0x4c(25); addi 4,30,-22896; stw 31,0x40(25); mr 3,29; stw 31,0x44(25); sth 31,0x48(25); sth 31,0x4a(25); stw 31,0x60(1); stw 31,0x58(1); stw 31,0x70(1); stw 31,0x68(1); stw 31,0x80(1); stw 31,0x78(1); bl _s800CAB20_5; addi 4,30,-22896; mr 3,28; bl _s800CAB20_6; addi 4,30,-22896; mr 3,27; bl _s800CAB20_7; addi 4,30,-22896; mr 3,26; bl _s800CAB20_8; mr 5,24; li 6,0; mr 4,29; mr 3,23; bl _s800CAB20_9; stw 31,0x44(1); mr 4,24; mr 3,23; bl _s800CAB20_10; stw 3,0x48(1); mr 4,24; mr 3,23; bl _s800CAB20_11; mr 4,3; li 5,0; lis 3,-32692; li 6,0; addi 3,3,-17444; bl _s800CAB20_12; li 0,32; stw 3,0x4c(1); sth 0,0x50(1); mr 3,29; sth 0,0x52(1); bl _s800CAB20_13; cmpwi 3,0; beq 1f; lwz 3,0x48(22); mr 4,25; bl _s800CAB20_14; 1:; mr 3,25; li 4,2; bl _s800CAB20_15; 2:; lwz 0,0xbc(1); mtspr 8,0; lmw 22,0x90(1); addi 1,1,184"
extern "C" void _s800CAB20_0();
extern "C" void _s800CAB20_1();
extern "C" void _s800CAB20_2();
extern "C" void _s800CAB20_3();
extern "C" void _s800CAB20_4();
extern "C" void _s800CAB20_5();
extern "C" void _s800CAB20_6();
extern "C" void _s800CAB20_7();
extern "C" void _s800CAB20_8();
extern "C" void _s800CAB20_9();
extern "C" void _s800CAB20_10();
extern "C" void _s800CAB20_11();
extern "C" void _s800CAB20_12();
extern "C" void _s800CAB20_13();
extern "C" void _s800CAB20_14();
extern "C" void _s800CAB20_15();
extern "C" void f_800CAB20() {}
