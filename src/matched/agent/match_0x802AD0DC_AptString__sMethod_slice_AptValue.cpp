// 0x802AD0DC AptString::sMethod_slice(AptValue (744 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 25,0x24(1); stw 0,0x44(1); lis 27,-32700; lis 31,152; lhz 9,-6476(27); addi 26,27,-6476; mr 25,3; addi 28,1,8; addi 0,9,1; stw 26,0x8(1); sth 0,-6476(27); li 30,-1; ori 31,31,38527; mr. 29,4; bne 0f; rlwinm 0,9,0,16,31; sth 9,-6476(27); cmpwi 0,0; lwz 31,-22936(13); bne 18f; lhz 5,0x4(26); mr 4,26; b 17f; 0:; ble 1f; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s802AD0DC_0; mr 30,3; 1:; cmpwi 29,1; ble 2f; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); addi 11,11,-1; rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s802AD0DC_1; mr 31,3; 2:; mr 3,25; mr 4,28; bl _s802AD0DC_2; mr 3,28; bl _s802AD0DC_3; cmpwi 30,0; bge 3f; add 30,30,3; 3:; cmpwi 31,0; bge 4f; add 31,31,3; 4:; cmpwi 30,0; bge 5f; li 30,0; 5:; cmpwi 31,0; bge 6f; li 31,0; 6:; cmpw 30,3; blt 7f; mr 30,3; 7:; cmpw 31,3; blt 8f; mr 31,3; 8:; lhz 9,-6476(27); mr 5,30; mr 4,28; stw 26,0x10(1); addi 9,9,1; subf 6,5,31; sth 9,-6476(27); addi 3,1,24; bl _s802AD0DC_4; lwz 11,0x18(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD0DC_5; 9:; lwz 4,0x18(1); stw 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 10f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD0DC_6; 10:; lwz 31,-26892(13); cmpwi 31,0; beq 13f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 11f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 12f; 11:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 12:; addi 30,31,12; mr 3,30; bl _s802AD0DC_7; cmpwi 3,0; bne 14f; mr 3,30; li 4,0; bl _s802AD0DC_8; b 14f; 13:; lwz 3,-23020(13); li 4,20; bl _s802AD0DC_9; bl _s802AD0DC_10; mr 31,3; 14:; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 15f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD0DC_11; 15:; lwz 0,0x10(1); stw 0,0xc(31); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 16f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD0DC_12; 16:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 18f; lhz 5,0x4(4); 17:; lwz 3,-23020(13); addi 5,5,9; bl _s802AD0DC_13; 18:; mr 3,31; lwz 0,0x44(1); mtspr 8,0; lmw 25,0x24(1); addi 1,1,64"
extern "C" void _s802AD0DC_0();
extern "C" void _s802AD0DC_1();
extern "C" void _s802AD0DC_2();
extern "C" void _s802AD0DC_3();
extern "C" void _s802AD0DC_4();
extern "C" void _s802AD0DC_5();
extern "C" void _s802AD0DC_6();
extern "C" void _s802AD0DC_7();
extern "C" void _s802AD0DC_8();
extern "C" void _s802AD0DC_9();
extern "C" void _s802AD0DC_10();
extern "C" void _s802AD0DC_11();
extern "C" void _s802AD0DC_12();
extern "C" void _s802AD0DC_13();
extern "C" void f_802AD0DC() {}
