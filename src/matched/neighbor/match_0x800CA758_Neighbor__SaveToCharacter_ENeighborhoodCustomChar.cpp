// 0x800CA758 Neighbor::SaveToCharacter(ENeighborhoodCustomChar (460 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,4; lhz 9,0x74(31); addi 30,28,24; addi 29,28,88; sth 9,0x0(28); lhz 0,0x76(31); sth 0,0x2(28); lhz 9,0x78(31); sth 9,0x4(28); lhz 0,0x7a(31); sth 0,0x6(28); lhz 9,0x7c(31); sth 9,0x8(28); lhz 0,0x7e(31); sth 0,0xa(28); lbz 9,0x99(31); stb 9,0xc(28); lha 0,0x82(31); stw 0,0x140(28); lha 9,0x84(31); stw 9,0x144(28); lha 0,0x86(31); stw 0,0x148(28); lha 9,0x88(31); stw 9,0x14c(28); lha 0,0x8a(31); stw 0,0x150(28); lha 9,0x8c(31); stw 9,0x154(28); lha 0,0x8e(31); stw 0,0x158(28); lha 9,0x90(31); stw 9,0x15c(28); lha 0,0x92(31); stw 0,0x160(28); lha 9,0x94(31); stw 9,0x164(28); lha 0,0xa0(31); stw 0,0x168(28); lha 9,0xe0(31); stw 9,0x16c(28); lha 0,0xe2(31); stw 0,0x170(28); lha 9,0xee(31); stw 9,0x174(28); lha 0,0xe4(31); stw 0,0x10(28); lwz 3,0xc(31); bl _s800CA758_0; bl _s800CA758_1; mr 4,3; mr 3,30; bl _s800CA758_2; lwz 3,0xc(31); bl _s800CA758_3; bl _s800CA758_4; mr 4,3; mr 3,29; bl _s800CA758_5; lwz 9,0xc(31); addi 4,1,8; addi 11,28,20; li 10,288; lwz 9,0x8c(9); 0:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(9); stw 10,0x8(1); stw 0,0x0(11); lwz 3,0xc(31); bl _s800CA758_6; lwz 9,0x8(1); cmpwi 9,0; beq 2f; lwz 3,0x14(9); cmpwi 3,0; bne 1f; lwz 9,0x18(9); li 3,0; cmpwi 9,0; beq 1f; lwz 3,0x14(9); 1:; li 4,0; bl _s800CA758_7; stw 3,0x138(28); lwz 3,0x8(1); cmpwi 3,0; beq 2f; bl _s800CA758_8; li 0,0; stw 0,0x8(1); 2:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s800CA758_0();
extern "C" void _s800CA758_1();
extern "C" void _s800CA758_2();
extern "C" void _s800CA758_3();
extern "C" void _s800CA758_4();
extern "C" void _s800CA758_5();
extern "C" void _s800CA758_6();
extern "C" void _s800CA758_7();
extern "C" void _s800CA758_8();

struct Neighbor {
    void SaveToCharacter_ENeighborhoodCustomChar();
};

void Neighbor::SaveToCharacter_ENeighborhoodCustomChar() {
}
