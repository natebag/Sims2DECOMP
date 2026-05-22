// 0x802BD710 EAStringC::TrimRight(char (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 26,3; mr 28,4; lwz 9,0x0(26); li 30,0; lhz 29,0x2(9); add 9,9,29; addi 31,9,7; addi 27,1,16; b 1f; 0:; addi 30,30,1; 1:; cmplw 30,29; bge 2f; lbz 4,0x0(31); mr 3,28; addi 31,31,-1; extsb 4,4; bl _s802BD710_0; cmpwi 3,0; bne 0b; 2:; lis 11,-32700; mr 4,26; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); subf 5,30,29; addi 9,9,1; mr 3,27; sth 9,-6476(11); bl _s802BD710_1; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD710_2; 3:; lwz 4,0x10(1); stw 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD710_3; 4:; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(26); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD710_4; 5:; lwz 4,0x8(1); stw 4,0x0(26); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BD710_5; 6:; mr 3,26; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s802BD710_0();
extern "C" void _s802BD710_1();
extern "C" void _s802BD710_2();
extern "C" void _s802BD710_3();
extern "C" void _s802BD710_4();
extern "C" void _s802BD710_5();
extern "C" void f_802BD710() {}
