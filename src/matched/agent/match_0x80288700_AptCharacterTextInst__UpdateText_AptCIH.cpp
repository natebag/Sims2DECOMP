// 0x80288700 AptCharacterTextInst::UpdateText(AptCIH (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 28,3; lis 11,-32700; lwz 9,0x1c(28); addi 10,11,-6476; cmpw 9,10; beq 16f; lbz 0,0x8(9); cmpwi 0,36; beq 16f; lhz 9,-6476(11); mr. 30,4; stw 10,0x8(1); addi 27,28,28; addi 9,9,1; sth 9,-6476(11); beq 5f; 0:; mr 3,30; li 29,0; bl _s80288700_0; li 31,0; cmpwi 3,13; bne 1f; mr 3,30; bl _s80288700_1; subfic 0,3,0; adde 31,0,3; 1:; cmpwi 31,0; bne 3f; mr 3,30; li 31,0; bl _s80288700_2; cmpwi 3,18; bne 2f; mr 3,30; bl _s80288700_3; subfic 0,3,0; adde 31,0,3; 2:; cmpwi 31,0; beq 4f; 3:; li 29,1; 4:; cmpwi 29,0; bne 5f; lwz 0,0x48(30); cmpwi 0,0; beq 5f; mr 30,0; b 0b; 5:; lis 3,-32694; li 9,0; mr 4,30; addi 3,3,-16032; mr 6,27; li 5,0; li 7,1; li 8,1; bl _s80288700_4; lwz 0,0x0(3); andis. 9,0,2048; bne 9f; lwz 9,0x8(28); lwz 4,0x34(9); cmpwi 4,0; beq 6f; addi 3,1,16; b 7f; 6:; lis 4,-32704; addi 3,1,16; addi 4,4,18440; 7:; bl _s80288700_5; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80288700_6; 8:; lwz 4,0x10(1); stw 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 10f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80288700_7; b 10f; 9:; addi 4,1,8; bl _s80288700_8; 10:; lwz 3,0x18(28); lwz 4,0x8(1); lhz 5,0x2(3); lhz 0,0x2(4); cmpw 5,0; beq 11f; li 3,0; b 13f; 11:; cmpw 3,4; bne 12f; li 3,1; b 13f; 12:; addi 3,3,8; addi 4,4,8; bl _s80288700_9; subfic 0,3,0; adde 3,0,3; 13:; cmpwi 3,0; bne 15f; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 14f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80288700_10; 14:; lwz 0,0x6c(28); lwz 9,0x8(1); rlwinm 0,0,0,0,30; ori 0,0,2; stw 9,0x18(28); stw 0,0x6c(28); 15:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 16f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80288700_11; 16:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s80288700_0();
extern "C" void _s80288700_1();
extern "C" void _s80288700_2();
extern "C" void _s80288700_3();
extern "C" void _s80288700_4();
extern "C" void _s80288700_5();
extern "C" void _s80288700_6();
extern "C" void _s80288700_7();
extern "C" void _s80288700_8();
extern "C" void _s80288700_9();
extern "C" void _s80288700_10();
extern "C" void _s80288700_11();
extern "C" void f_80288700() {}
