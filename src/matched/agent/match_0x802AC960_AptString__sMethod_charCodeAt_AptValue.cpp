// 0x802AC960 AptString::sMethod_charCodeAt(AptValue (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); lis 9,-32694; mr 30,3; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s802AC960_0; lwz 0,0x0(30); mr 4,3; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 0f; lwz 30,0x24(30); 0:; addi 3,30,12; cmpwi 4,0; blt 1f; bl _s802AC960_1; mr. 3,3; bne 2f; 1:; lwz 3,-22936(13); b 12f; 2:; lbz 5,0x0(3); andi. 0,5,128; beq 6f; rlwinm 0,5,0,24,26; cmpwi 0,192; bne 3f; lbz 0,0x1(3); rlwinm 5,5,6,21,25; rlwinm 0,0,0,26,31; or 5,5,0; b 6f; 3:; rlwinm 0,5,0,24,27; cmpwi 0,224; bne 4f; lbz 0,0x1(3); rlwinm 5,5,12,16,19; lbz 10,0x2(3); rlwinm 0,0,6,20,25; or 5,5,0; rlwinm 9,10,0,26,31; b 5f; 4:; lbz 0,0x1(3); rlwinm 5,5,18,11,13; lbz 10,0x2(3); rlwinm 11,0,12,14,19; lbz 9,0x3(3); or 5,5,11; rlwinm 0,10,6,20,25; or 5,5,0; rlwinm 9,9,0,26,31; 5:; or 5,5,9; 6:; addi 30,1,16; lis 4,-32703; addi 29,1,8; addi 4,4,1812; mr 3,30; mr 31,29; crxor 6,6,6; bl _s802AC960_2; mr 4,30; mr 3,29; bl _s802AC960_3; lwz 30,-26892(13); cmpwi 30,0; beq 9f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 7f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 8f; 7:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 8:; addi 29,30,12; mr 3,29; bl _s802AC960_4; cmpwi 3,0; bne 10f; mr 3,29; li 4,0; bl _s802AC960_5; b 10f; 9:; lwz 3,-23020(13); li 4,20; bl _s802AC960_6; bl _s802AC960_7; mr 30,3; 10:; mr 4,31; addi 3,30,12; bl _s802AC960_8; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AC960_9; 11:; mr 3,30; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s802AC960_0();
extern "C" void _s802AC960_1();
extern "C" void _s802AC960_2();
extern "C" void _s802AC960_3();
extern "C" void _s802AC960_4();
extern "C" void _s802AC960_5();
extern "C" void _s802AC960_6();
extern "C" void _s802AC960_7();
extern "C" void _s802AC960_8();
extern "C" void _s802AC960_9();
extern "C" void f_802AC960() {}
