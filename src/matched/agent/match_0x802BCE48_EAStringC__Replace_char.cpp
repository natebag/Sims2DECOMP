// 0x802BCE48 EAStringC::Replace(char (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 19,0x14(1); stw 0,0x4c(1); mr 23,4; mr 20,3; mr 21,5; mr 3,23; bl _s802BCE48_0; mr. 24,3; li 3,0; beq 9f; mr 3,21; li 22,0; bl _s802BCE48_1; lwz 9,0x0(20); mr 25,3; addi 31,9,8; b 1f; 0:; add 31,30,24; addi 22,22,1; 1:; mr 3,31; mr 4,23; bl _s802BCE48_2; mr. 30,3; bne 0b; cmpwi 22,0; bne 2f; li 3,0; b 9f; 2:; subf 0,24,25; lwz 9,0x0(20); mullw 0,0,22; addi 3,1,8; lhz 26,0x2(9); add 26,26,0; mr 4,26; bl _s802BCE48_3; lwz 9,0x8(1); cmpwi 22,0; lwz 11,0x0(20); addi 28,9,8; mr 19,28; addi 31,11,8; ble 5f; mr 27,22; 3:; mr 3,31; mr 4,23; bl _s802BCE48_4; mr 30,3; subf. 29,31,30; beq 4f; mr 3,28; mr 4,31; mr 5,29; add 28,28,29; crxor 6,6,6; bl _s802BCE48_5; 4:; mr 3,28; mr 4,21; mr 5,25; add 31,30,24; crxor 6,6,6; bl _s802BCE48_6; add 28,28,25; addic. 27,27,-1; bne 3b; 5:; subf 0,19,28; subf. 29,0,26; beq 6f; mr 3,28; mr 4,31; mr 5,29; add 28,28,29; crxor 6,6,6; bl _s802BCE48_7; 6:; li 0,0; li 8,0; stb 0,0x0(28); lwz 9,0x8(1); sth 26,0x2(9); lwz 11,0x8(1); sth 8,0x6(11); lwz 10,0x8(1); lhz 9,0x0(10); addi 9,9,1; sth 9,0x0(10); lwz 4,0x0(20); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BCE48_8; 7:; lwz 4,0x8(1); stw 4,0x0(20); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BCE48_9; 8:; mr 3,22; 9:; lwz 0,0x4c(1); mtspr 8,0; lmw 19,0x14(1); addi 1,1,72"
extern "C" void _s802BCE48_0();
extern "C" void _s802BCE48_1();
extern "C" void _s802BCE48_2();
extern "C" void _s802BCE48_3();
extern "C" void _s802BCE48_4();
extern "C" void _s802BCE48_5();
extern "C" void _s802BCE48_6();
extern "C" void _s802BCE48_7();
extern "C" void _s802BCE48_8();
extern "C" void _s802BCE48_9();
extern "C" void f_802BCE48() {}
