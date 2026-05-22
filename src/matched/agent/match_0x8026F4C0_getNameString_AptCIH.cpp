// 0x8026F4C0 _getNameString(AptCIH (540 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 27,0x24(1); stw 0,0x3c(1); mr 31,3; mr 28,4; mr. 5,5; bne 0f; lis 9,-32704; addi 30,9,6544; b 1f; 0:; lis 9,-32704; addi 30,9,6548; 1:; lwz 27,0x48(31); cmpwi 27,0; bne 5f; cmpwi 5,0; bne 2f; lwz 0,0x58(31); rlwinm. 9,0,0,0,16; bne 3f; 2:; cmpwi 5,1; bne 9f; 3:; lwz 5,0x58(31); lis 4,-32704; addi 4,4,6552; addi 3,1,8; srawi 5,5,15; crxor 6,6,6; bl _s8026F4C0_0; addi 4,1,8; addi 3,1,24; bl _s8026F4C0_1; lwz 11,0x18(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(28); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F4C0_2; 4:; lwz 4,0x18(1); stw 4,0x0(28); b 6f; 5:; mr 3,27; mr 4,28; bl _s8026F4C0_3; lwz 10,0xc(31); lis 11,-32700; addi 0,11,-6476; addi 5,31,12; cmpw 10,0; beq 7f; addi 3,1,8; mr 4,30; bl _s8026F4C0_4; addi 4,1,8; mr 3,28; bl _s8026F4C0_5; lwz 4,0x8(1); 6:; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F4C0_6; b 9f; 7:; lhz 9,-6476(11); mr 4,30; lwz 30,0x58(31); mr 3,28; addi 9,9,1; stw 10,0x8(1); sth 9,-6476(11); srawi 30,30,15; bl _s8026F4C0_7; addi 29,1,8; lis 4,-32704; mr 5,30; addi 4,4,6564; mr 3,29; crxor 6,6,6; bl _s8026F4C0_8; mr 4,29; mr 3,28; bl _s8026F4C0_9; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F4C0_10; 8:; lwz 0,0x8(1); mr 4,29; mr 5,31; stw 0,0xc(31); lwz 9,0x4c(27); lwz 3,0xc(9); bl _s8026F4C0_11; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026F4C0_12; 9:; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"
extern "C" void _s8026F4C0_0();
extern "C" void _s8026F4C0_1();
extern "C" void _s8026F4C0_2();
extern "C" void _s8026F4C0_3();
extern "C" void _s8026F4C0_4();
extern "C" void _s8026F4C0_5();
extern "C" void _s8026F4C0_6();
extern "C" void _s8026F4C0_7();
extern "C" void _s8026F4C0_8();
extern "C" void _s8026F4C0_9();
extern "C" void _s8026F4C0_10();
extern "C" void _s8026F4C0_11();
extern "C" void _s8026F4C0_12();
extern "C" void f_8026F4C0() {}
