// 0x800CAD10 Neighbor::Notify(WantFear::Notification (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 23,0x1c(1); stw 0,0x44(1); lis 9,-32697; mr 31,3; lwz 0,0x5c74(9); mr 26,4; mr 23,5; cmpwi 0,0; beq 0f; li 3,0; b 6f; 0:; li 25,0; addi 24,31,408; mr 27,25; li 28,0; 1:; lwz 9,0x194(31); li 11,1; add 3,28,9; lwz 0,0x4(3); cmpwi 0,0; bne 2f; li 11,0; 2:; cmpwi 11,0; beq 5f; mr 4,26; bl _s800CAD10_0; cmpwi 3,0; beq 5f; lwz 0,0x194(31); add 11,28,0; lhz 9,0x8(11); cmpwi 9,0; beq 3f; addi 0,9,-1; rlwinm 0,0,0,16,31; sth 0,0x8(11); cmpwi 0,0; bne 5f; 3:; lwz 9,0x194(31); addi 30,1,8; lha 0,0x2(26); mr 3,31; add 9,28,9; li 25,1; sth 0,0x2(9); lwz 4,0x194(31); add 4,4,28; bl _s800CAD10_1; lwz 9,0x194(31); mr 29,3; mr 3,31; mr 4,27; lwzx 11,28,9; add 9,28,9; lwz 0,0x4(9); lwz 10,0x8(9); stw 11,0x8(1); stw 0,0x4(30); stw 10,0x8(30); bl _s800CAD10_2; lha 0,-21222(13); cmpw 29,0; beq 5f; rlwinm 9,29,2,0,29; li 0,0; stwx 0,24,9; mr 3,30; mr 4,31; li 25,2; bl _s800CAD10_3; cmpwi 23,0; beq 4f; mr 3,30; bl _s800CAD10_4; cmpwi 3,0; beq 4f; lwz 3,-21476(13); mr 4,26; mr 5,31; lwz 9,0x0(3); lha 0,0x198(9); lwz 9,0x19c(9); add 3,3,0; mtspr 8,9; blrl; 4:; mr 4,29; mr 3,31; bl _s800CAD10_5; mr 4,29; mr 3,31; li 5,1; bl _s800CAD10_6; addi 3,1,8; bl _s800CAD10_7; cmpwi 3,0; bne 5f; li 3,3; bl _s800CAD10_8; addi 4,3,4; mr 3,31; bl _s800CAD10_9; 5:; addi 27,27,1; addi 28,28,12; cmplwi 27,19; ble 1b; mr 3,25; 6:; lwz 0,0x44(1); mtspr 8,0; lmw 23,0x1c(1); addi 1,1,64"
extern "C" void _s800CAD10_0();
extern "C" void _s800CAD10_1();
extern "C" void _s800CAD10_2();
extern "C" void _s800CAD10_3();
extern "C" void _s800CAD10_4();
extern "C" void _s800CAD10_5();
extern "C" void _s800CAD10_6();
extern "C" void _s800CAD10_7();
extern "C" void _s800CAD10_8();
extern "C" void _s800CAD10_9();
extern "C" void f_800CAD10() {}
