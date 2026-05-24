// 0x800CA604 Neighbor::LoadFromCharacter(ENeighborhoodCustomChar (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; lhz 9,0x0(30); addi 3,31,112; sth 9,0x74(31); lhz 0,0x2(30); sth 0,0x76(31); lhz 9,0x4(30); sth 9,0x78(31); lhz 0,0x6(30); sth 0,0x7a(31); lhz 9,0x8(30); sth 9,0x7c(31); lhz 0,0xa(30); sth 0,0x7e(31); bl _s800CA604_0; sth 3,0xfc(31); lbz 0,0xc(30); sth 0,0x98(31); lhz 9,0x142(30); sth 9,0x82(31); lhz 0,0x146(30); sth 0,0x84(31); lhz 9,0x14a(30); sth 9,0x86(31); lhz 0,0x14e(30); sth 0,0x88(31); lhz 9,0x152(30); sth 9,0x8a(31); lhz 0,0x156(30); sth 0,0x8c(31); lhz 9,0x15a(30); sth 9,0x8e(31); lhz 0,0x15e(30); sth 0,0x90(31); lhz 9,0x162(30); sth 9,0x92(31); lhz 0,0x166(30); sth 0,0x94(31); lhz 9,0x16a(30); sth 9,0xa0(31); lhz 0,0x16e(30); sth 0,0xe0(31); lhz 9,0x172(30); sth 9,0xe2(31); lhz 0,0x176(30); sth 0,0xee(31); lhz 9,0x12(30); sth 9,0xe4(31); bl _s800CA604_1; stw 3,0x0(31); addi 11,30,20; lwz 9,0xc(31); li 10,288; lwz 9,0x8c(9); 0:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 0b; lwz 0,0x0(11); stw 0,0x0(9); lwz 3,0xc(31); lwz 4,0x138(30); bl _s800CA604_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800CA604_0();
extern "C" void _s800CA604_1();
extern "C" void _s800CA604_2();

struct Neighbor {
    void LoadFromCharacter_ENeighborhoodCustomChar();
};

void Neighbor::LoadFromCharacter_ENeighborhoodCustomChar() {
}
