// 0x802AC7EC AptString::sMethod_charAt(AptValue (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lis 9,-32694; mr 30,3; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s802AC7EC_0; lwz 0,0x0(30); mr 4,3; rlwinm 0,0,0,25,31; cmpwi 0,1; beq 0f; lwz 30,0x24(30); 0:; addi 3,30,12; cmpwi 4,0; blt 1f; bl _s802AC7EC_1; mr. 4,3; bne 2f; 1:; lwz 3,-22936(13); b 9f; 2:; lis 11,-32700; addi 3,1,8; lhz 9,-6476(11); addi 0,11,-6476; mr 29,3; stw 0,0x8(1); addi 9,9,1; li 5,1; sth 9,-6476(11); bl _s802AC7EC_2; lwz 30,-26892(13); cmpwi 30,0; beq 6f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 4:; addi 31,30,12; mr 3,31; bl _s802AC7EC_3; cmpwi 3,0; bne 5f; mr 3,31; li 4,0; bl _s802AC7EC_4; 5:; mr 31,30; b 7f; 6:; lwz 3,-23020(13); li 4,20; bl _s802AC7EC_5; bl _s802AC7EC_6; mr 31,3; 7:; mr 4,29; addi 3,31,12; bl _s802AC7EC_7; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802AC7EC_8; 8:; mr 3,31; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802AC7EC_0();
extern "C" void _s802AC7EC_1();
extern "C" void _s802AC7EC_2();
extern "C" void _s802AC7EC_3();
extern "C" void _s802AC7EC_4();
extern "C" void _s802AC7EC_5();
extern "C" void _s802AC7EC_6();
extern "C" void _s802AC7EC_7();
extern "C" void _s802AC7EC_8();
extern "C" void f_802AC7EC() {}
