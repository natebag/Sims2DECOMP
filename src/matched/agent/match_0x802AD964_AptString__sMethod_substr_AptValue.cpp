// 0x802AD964 AptString::sMethod_substr(AptValue (560 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); lis 11,-32700; lis 29,152; lhz 9,-6476(11); addi 10,11,-6476; mr 27,3; addi 31,1,8; addi 0,9,1; stw 10,0x8(1); sth 0,-6476(11); li 28,-1; ori 29,29,38527; mr. 30,4; bne 0f; rlwinm 0,9,0,16,31; sth 9,-6476(11); cmpwi 0,0; lwz 31,-22936(13); bne 11f; lhz 5,0x4(10); mr 4,10; b 10f; 0:; ble 1f; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s802AD964_0; mr 28,3; 1:; cmpwi 30,1; ble 2f; lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); addi 11,11,-1; rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s802AD964_1; mr 29,3; 2:; mr 3,27; mr 4,31; bl _s802AD964_2; mr 3,31; bl _s802AD964_3; cmpwi 28,0; bge 3f; add 28,28,3; 3:; lwz 31,-26892(13); cmpwi 31,0; beq 6f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 4f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 5f; 4:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 5:; addi 30,31,12; mr 3,30; bl _s802AD964_4; cmpwi 3,0; bne 7f; mr 3,30; li 4,0; bl _s802AD964_5; b 7f; 6:; lwz 3,-23020(13); li 4,20; bl _s802AD964_6; bl _s802AD964_7; mr 31,3; 7:; addi 4,1,8; mr 5,28; mr 6,29; addi 3,1,16; bl _s802AD964_8; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD964_9; 8:; lwz 0,0x10(1); stw 0,0xc(31); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AD964_10; 9:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 11f; lhz 5,0x4(4); 10:; lwz 3,-23020(13); addi 5,5,9; bl _s802AD964_11; 11:; mr 3,31; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s802AD964_0();
extern "C" void _s802AD964_1();
extern "C" void _s802AD964_2();
extern "C" void _s802AD964_3();
extern "C" void _s802AD964_4();
extern "C" void _s802AD964_5();
extern "C" void _s802AD964_6();
extern "C" void _s802AD964_7();
extern "C" void _s802AD964_8();
extern "C" void _s802AD964_9();
extern "C" void _s802AD964_10();
extern "C" void _s802AD964_11();
extern "C" void f_802AD964() {}
