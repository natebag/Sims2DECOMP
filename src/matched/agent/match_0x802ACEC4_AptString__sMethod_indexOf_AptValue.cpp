// 0x802ACEC4 AptString::sMethod_indexOf(AptValue (528 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); lis 9,-32700; mr 28,4; lhz 11,-6476(9); addi 0,9,-6476; stw 0,0x10(1); addi 4,1,8; addi 11,11,2; stw 0,0x8(1); sth 11,-6476(9); li 31,0; bl _s802ACEC4_0; cmpwi 28,0; bne 2f; lwz 4,0x10(1); lwz 31,-22936(13); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACEC4_1; 0:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACEC4_2; 1:; mr 3,31; b 10f; 2:; lis 30,-32694; addi 4,1,16; lwz 9,-16032(30); addi 29,30,-16032; lwz 0,0x8(29); rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s802ACEC4_3; cmpwi 28,2; bne 3f; lwz 9,-16032(30); lwz 0,0x8(29); addi 9,9,-1; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s802ACEC4_4; mr. 31,3; bge 3f; li 31,0; 3:; lwz 4,0x10(1); mr 5,31; addi 3,1,8; addi 4,4,8; bl _s802ACEC4_5; mr 31,3; lwz 3,-26908(13); cmpwi 3,0; beq 6f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 4f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 5f; 4:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 5:; stw 31,0xc(3); mr 29,3; b 7f; 6:; lwz 3,-23020(13); li 4,16; bl _s802ACEC4_6; mr 30,3; li 4,7; mr 29,30; bl _s802ACEC4_7; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; stw 9,0x8(30); 7:; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACEC4_8; 8:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACEC4_9; 9:; mr 3,29; 10:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s802ACEC4_0();
extern "C" void _s802ACEC4_1();
extern "C" void _s802ACEC4_2();
extern "C" void _s802ACEC4_3();
extern "C" void _s802ACEC4_4();
extern "C" void _s802ACEC4_5();
extern "C" void _s802ACEC4_6();
extern "C" void _s802ACEC4_7();
extern "C" void _s802ACEC4_8();
extern "C" void _s802ACEC4_9();
extern "C" void f_802ACEC4() {}
