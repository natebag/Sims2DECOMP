// 0x8029ACB4 AptDisplayList::placeObject(AptPseudoCIH_t (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 28,0x28(1); stw 0,0x3c(1); lis 11,-32700; mr 31,4; lhz 9,-6476(11); addi 0,11,-6476; stw 0,0x18(1); mr 29,3; addi 9,9,1; mr 28,5; sth 9,-6476(11); addi 30,1,24; li 7,0; lwz 9,0x0(31); lwz 0,0x4(9); andi. 11,0,32; beq 2f; lwz 4,0x34(9); addi 3,1,32; bl _s8029ACB4_0; lwz 11,0x20(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029ACB4_1; 0:; lwz 4,0x20(1); stw 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029ACB4_2; 1:; mr 7,30; 2:; lwz 30,0x4(31); li 4,0; lwz 5,0x10(31); li 9,1; lwz 0,0x8(30); mr 3,29; lwz 6,0x0(30); mr 8,28; lha 10,0x1a(30); lfs f1,0x10(30); stw 0,0x8(1); lwz 0,0x4(30); stw 0,0xc(1); lwz 11,0xc(30); stw 11,0x10(1); bl _s8029ACB4_3; lwz 11,0x4(31); mr 30,3; lwz 0,0x58(30); lha 9,0x18(11); rlwimi 0,9,1,17,30; stw 0,0x58(30); lwz 4,0x18(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8029ACB4_4; 3:; mr 3,30; lwz 0,0x3c(1); mtspr 8,0; lmw 28,0x28(1); addi 1,1,56"
extern "C" void _s8029ACB4_0();
extern "C" void _s8029ACB4_1();
extern "C" void _s8029ACB4_2();
extern "C" void _s8029ACB4_3();
extern "C" void _s8029ACB4_4();
extern "C" void f_8029ACB4() {}
