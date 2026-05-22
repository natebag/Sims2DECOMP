// 0x802ACB50 AptString::sMethod_concat(AptValue (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); lis 11,-32700; mr 29,4; lhz 9,-6476(11); addi 31,11,-6476; stw 31,0x8(1); addi 4,1,8; addi 9,9,1; li 30,0; sth 9,-6476(11); bl _s802ACB50_0; cmpw 30,29; bge 2f; lis 27,-32694; mr 25,31; addi 26,27,-16032; lis 28,-32700; addi 31,1,16; 0:; lhz 11,-6476(28); mr 4,31; lwz 9,-16032(27); lwz 0,0x8(26); addi 11,11,1; subf 9,30,9; sth 11,-6476(28); stw 25,0x10(1); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s802ACB50_1; mr 4,31; addi 3,1,8; bl _s802ACB50_2; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACB50_3; 1:; addi 30,30,1; cmpw 30,29; blt 0b; 2:; lwz 31,-26892(13); cmpwi 31,0; beq 5f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 4:; addi 30,31,12; mr 3,30; bl _s802ACB50_4; cmpwi 3,0; bne 6f; mr 3,30; li 4,0; bl _s802ACB50_5; b 6f; 5:; lwz 3,-23020(13); li 4,20; bl _s802ACB50_6; bl _s802ACB50_7; mr 31,3; 6:; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACB50_8; 7:; lwz 0,0x8(1); stw 0,0xc(31); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACB50_9; 8:; mr 3,31; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s802ACB50_0();
extern "C" void _s802ACB50_1();
extern "C" void _s802ACB50_2();
extern "C" void _s802ACB50_3();
extern "C" void _s802ACB50_4();
extern "C" void _s802ACB50_5();
extern "C" void _s802ACB50_6();
extern "C" void _s802ACB50_7();
extern "C" void _s802ACB50_8();
extern "C" void _s802ACB50_9();
extern "C" void f_802ACB50() {}
