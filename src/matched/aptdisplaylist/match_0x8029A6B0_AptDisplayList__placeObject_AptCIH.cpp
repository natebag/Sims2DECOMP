// 0x8029A6B0 AptDisplayList::placeObject(AptCIH (816 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stfd f31,0x38(1); stmw 27,0x24(1); stw 0,0x44(1); li 0,0; mr 29,3; fmr f31,f1; stw 0,0x14(1); cmpwi 4,0; stw 4,0x10(1); lwz 30,0x48(1); lwz 31,0x4c(1); lwz 27,0x50(1); lwz 28,0x54(1); bne 0f; mr 4,5; addi 0,1,20; mr 5,6; stw 0,0x8(1); mr 6,7; mr 7,8; mr 8,9; mr 9,10; addi 10,1,16; bl _s8029A6B0_0; lwz 0,0x10(1); cmpwi 0,0; beq 21f; 0:; cmpwi 30,0; cmpwi 7,31,0; cmpwi 6,27,0; beq 2f; lwz 9,0x10(1); mr 11,30; li 10,24; addi 9,9,40; 1:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 1b; lwz 0,0x0(11); stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); 2:; beq cr7,3f; lwz 11,0x10(1); lwz 8,0x0(31); lwz 0,0x8(31); addi 9,11,16; lwz 7,0x4(31); lwz 10,0xc(31); stw 8,0x10(11); stw 7,0x4(9); stw 0,0x8(9); stw 10,0xc(9); lwz 0,0x14(31); lwz 11,0x10(31); stw 0,0x14(9); stw 11,0x10(9); 3:; beq cr6,4f; lwz 9,0x10(1); lwz 11,0x4c(9); stw 27,0x20(11); 4:; lwz 31,0x10(1); li 30,0; mr 3,31; bl _s8029A6B0_1; cmpwi 3,17; bne 5f; mr 3,31; bl _s8029A6B0_2; subfic 0,3,0; adde 30,0,3; 5:; cmpwi 30,0; beq 6f; lwz 9,0x10(1); lwz 11,0x4c(9); stfs f31,0x18(11); 6:; lwz 0,0x14(1); cmpwi 0,0; beq 7f; lwz 4,0x10(1); mr 3,29; li 5,1; bl _s8029A6B0_3; 7:; lwz 31,0x10(1); li 29,0; li 30,0; mr 3,31; bl _s8029A6B0_4; cmpwi 3,13; bne 8f; mr 3,31; bl _s8029A6B0_5; subfic 0,3,0; adde 30,0,3; 8:; cmpwi 30,0; bne 10f; mr 3,31; li 30,0; bl _s8029A6B0_6; cmpwi 3,18; bne 9f; mr 3,31; bl _s8029A6B0_7; subfic 0,3,0; adde 30,0,3; 9:; cmpwi 30,0; beq 11f; 10:; li 29,1; 11:; cmpwi 29,0; beq 21f; cmpwi 28,0; beq 20f; lwz 0,0x0(28); andis. 9,0,2048; beq 20f; lwz 9,0x8(28); lha 3,0x20(9); lwz 0,0x24(9); add 3,28,3; mtspr 8,0; blrl; mr 30,3; bl _s8029A6B0_8; mr. 31,3; beq 20f; lis 29,-32694; addi 28,29,-11332; 12:; lwz 3,0x0(31); lwz 4,-11332(29); lhz 5,0x2(3); lhz 0,0x2(4); cmpw 5,0; beq 13f; li 3,0; b 15f; 13:; cmpw 3,4; bne 14f; li 3,1; b 15f; 14:; addi 3,3,8; addi 4,4,8; bl _s8029A6B0_9; subfic 0,3,0; adde 3,0,3; 15:; cmpwi 3,0; bne 19f; lwz 3,0x0(31); lwz 4,0x1e0(28); lhz 5,0x2(3); lhz 0,0x2(4); cmpw 5,0; beq 16f; li 3,0; b 18f; 16:; cmpw 3,4; bne 17f; li 3,1; b 18f; 17:; addi 3,3,8; addi 4,4,8; bl _s8029A6B0_10; subfic 0,3,0; adde 3,0,3; 18:; cmpwi 3,0; bne 19f; lis 3,-32694; lwz 4,0x10(1); lwz 7,0x4(31); addi 3,3,-16032; li 5,0; mr 6,31; li 8,1; li 9,1; li 10,0; bl _s8029A6B0_11; 19:; mr 4,31; mr 3,30; bl _s8029A6B0_12; mr. 31,3; bne 12b; 20:; lwz 3,0x10(1); bl _s8029A6B0_13; 21:; lwz 3,0x10(1); lwz 0,0x44(1); mtspr 8,0; lmw 27,0x24(1); lfd f31,0x38(1); addi 1,1,64"

extern "C" void _s8029A6B0_0();
extern "C" void _s8029A6B0_1();
extern "C" void _s8029A6B0_2();
extern "C" void _s8029A6B0_3();
extern "C" void _s8029A6B0_4();
extern "C" void _s8029A6B0_5();
extern "C" void _s8029A6B0_6();
extern "C" void _s8029A6B0_7();
extern "C" void _s8029A6B0_8();
extern "C" void _s8029A6B0_9();
extern "C" void _s8029A6B0_10();
extern "C" void _s8029A6B0_11();
extern "C" void _s8029A6B0_12();
extern "C" void _s8029A6B0_13();

struct AptDisplayList {
    void placeObject_AptCIH();
};

void AptDisplayList::placeObject_AptCIH() {
}
