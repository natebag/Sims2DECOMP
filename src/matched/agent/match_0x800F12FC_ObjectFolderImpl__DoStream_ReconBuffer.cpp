// 0x800F12FC ObjectFolderImpl::DoStream(ReconBuffer (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 24,0x20(1); stw 0,0x44(1); li 0,1; mr 27,4; mr 26,3; stw 0,0x8(1); mr 3,27; addi 4,1,8; bl _s800F12FC_0; lwz 0,0x8(1); cmpwi 0,0; beq 0f; mr 3,27; bl _s800F12FC_1; 0:; lwz 0,0x664(26); mr 3,27; lwz 9,0x660(26); addi 4,1,12; li 5,1; li 25,0; subf 0,9,0; li 24,0; srawi 0,0,2; stw 0,0xc(1); bl _s800F12FC_2; lwz 0,0xc(1); cmpw 25,0; bge 8f; 1:; lwz 9,0xc(27); li 0,0; stw 0,0x10(1); cmpwi 9,0; beq 2f; lwz 10,0x660(26); rlwinm 9,24,2,0,29; lwzx 11,10,9; lwz 0,0x0(11); stw 0,0x10(1); 2:; mr 3,27; addi 4,1,16; li 5,1; bl _s800F12FC_3; lwz 0,0xc(27); cmpwi 0,0; bne 3f; lwz 9,0x0(26); lwz 4,0x10(1); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,26,3; mtspr 8,0; blrl; mr. 3,3; bne 3f; stw 3,0x14(1); addi 4,1,20; mr 3,27; li 5,1; bl _s800F12FC_4; addi 28,25,1; lwz 3,0x14(1); cmpwi 3,0; beq 7f; rlwinm 3,3,1,0,30; bl _s800F12FC_5; mr 31,3; lwz 5,0x14(1); mr 3,27; mr 4,31; bl _s800F12FC_6; cmpwi 31,0; beq 7f; mr 3,31; bl _s800F12FC_7; b 7f; 3:; lwz 9,0x0(26); addi 0,24,1; rlwinm 24,0,0,16,31; lwz 4,0x10(1); lha 3,0xb0(9); addi 28,25,1; lwz 0,0xb4(9); add 3,26,3; mtspr 8,0; blrl; mr. 30,3; beq 7f; lwz 29,0x4(30); mr 3,27; lwz 31,0x8(30); addi 4,1,24; stw 29,0x18(1); li 5,1; bl _s800F12FC_8; lwz 0,0x18(1); cmpw 0,29; ble 5f; cmpwi 31,0; beq 4f; mr 3,31; bl _s800F12FC_9; 4:; lwz 0,0x18(1); stw 0,0x4(30); lwz 3,0x18(1); rlwinm 3,3,1,0,30; bl _s800F12FC_10; mr 31,3; stw 31,0x8(30); 5:; lwz 5,0x18(1); mr 3,27; mr 4,31; addi 28,25,1; bl _s800F12FC_11; lwz 0,0x18(1); mtspr 9,0; cmpw 0,29; bge 7f; add 0,0,0; mfspr 11,9; subf 11,11,29; li 9,0; mtspr 9,11; add 3,0,31; 6:; sth 9,0x0(3); addi 3,3,2; bdnz 6b; 7:; lwz 0,0xc(1); mr 25,28; cmpw 25,0; blt 1b; 8:; lwz 0,0x44(1); mtspr 8,0; lmw 24,0x20(1); addi 1,1,64"
extern "C" void _s800F12FC_0();
extern "C" void _s800F12FC_1();
extern "C" void _s800F12FC_2();
extern "C" void _s800F12FC_3();
extern "C" void _s800F12FC_4();
extern "C" void _s800F12FC_5();
extern "C" void _s800F12FC_6();
extern "C" void _s800F12FC_7();
extern "C" void _s800F12FC_8();
extern "C" void _s800F12FC_9();
extern "C" void _s800F12FC_10();
extern "C" void _s800F12FC_11();
extern "C" void f_800F12FC() {}
