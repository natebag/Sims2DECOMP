// 0x80271EB0 _concatAsStrings(AptValue (544 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lwz 30,-26892(13); mr 27,3; mr 29,4; cmpwi 30,0; beq 3f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 1:; addi 31,30,12; mr 3,31; bl _s80271EB0_0; cmpwi 3,0; bne 2f; mr 3,31; li 4,0; bl _s80271EB0_1; 2:; mr 28,30; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s80271EB0_2; bl _s80271EB0_3; mr 28,3; 4:; lwz 0,0x0(29); li 11,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 5f; cmpwi 0,42; bne 6f; 5:; andis. 0,9,2048; beq 6f; li 11,1; 6:; cmpwi 11,0; beq 9f; rlwinm 0,9,0,25,31; mr 31,29; cmpwi 0,1; beq 7f; lwz 31,0x24(29); 7:; lwz 11,0xc(31); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80271EB0_4; 8:; lwz 0,0xc(31); addi 31,28,12; stw 0,0xc(28); b 10f; 9:; addi 30,28,12; mr 3,29; mr 4,30; bl _s80271EB0_5; mr 31,30; 10:; lwz 0,0x0(27); li 11,0; mr 9,0; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 11f; cmpwi 0,42; bne 12f; 11:; andis. 0,9,2048; beq 12f; li 11,1; 12:; cmpwi 11,0; beq 14f; rlwinm 0,9,0,25,31; mr 4,27; cmpwi 0,1; beq 13f; lwz 4,0x24(27); 13:; mr 3,31; addi 4,4,12; bl _s80271EB0_6; b 15f; 14:; lis 11,-32700; addi 30,1,8; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x8(1); mr 3,27; addi 9,9,1; mr 4,30; sth 9,-6476(11); bl _s80271EB0_7; mr 4,30; mr 3,31; bl _s80271EB0_8; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 15f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80271EB0_9; 15:; mr 3,28; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80271EB0_0();
extern "C" void _s80271EB0_1();
extern "C" void _s80271EB0_2();
extern "C" void _s80271EB0_3();
extern "C" void _s80271EB0_4();
extern "C" void _s80271EB0_5();
extern "C" void _s80271EB0_6();
extern "C" void _s80271EB0_7();
extern "C" void _s80271EB0_8();
extern "C" void _s80271EB0_9();
extern "C" void f_80271EB0() {}
