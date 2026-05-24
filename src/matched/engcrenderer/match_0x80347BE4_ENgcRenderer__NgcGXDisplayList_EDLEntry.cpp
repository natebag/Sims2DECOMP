// 0x80347BE4 ENgcRenderer::NgcGXDisplayList(EDLEntry (1012 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; mfcr 12; stfd f31,0x88(1); stmw 19,0x54(1); stw 0,0x94(1); stw 12,0x50(1); lwz 0,-26252(13); li 30,0; mr 27,3; mr 31,4; cmpwi 0,0; stw 30,-26196(13); beq 11f; lwz 0,0x510(27); cmpwi 0,0; beq 0f; li 4,0; bl _s80347BE4_0; 0:; lbz 0,0x1(31); li 19,1; cmpwi 0,0; bne 1f; li 19,0; 1:; lwz 9,0x4d8(27); li 3,9; lwz 20,0x8(31); li 5,16; lwz 0,0x6cc(9); li 28,3; lwz 22,0x14(31); mr 4,20; oris 0,0,32768; lwz 24,0x1c(31); lwz 29,0xc(31); ori 0,0,1; lwz 25,0x10(31); lwz 26,0x18(31); stw 0,0x6cc(9); stw 30,0x4c(9); stw 30,0x4(9); stw 30,0x28(9); stw 30,0x2c(9); stw 30,0x30(9); stw 30,0x38(9); stw 30,0x3c(9); stw 30,0x40(9); stw 30,0x44(9); stw 30,0x48(9); bl _s80347BE4_1; lwz 9,0x4d8(27); cmpwi 22,0; lwz 0,0x6cc(9); stw 28,0x28(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); beq 2f; lwz 9,0x4d8(27); li 3,10; mr 4,22; li 5,4; lwz 0,0x6cc(9); stw 28,0x2c(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); bl _s80347BE4_2; 2:; cmpwi 3,25,0; beq cr3,3f; lwz 9,0x4d8(27); mr 4,25; li 3,11; li 5,4; lwz 0,0x6cc(9); stw 28,0x30(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); bl _s80347BE4_3; 3:; cmpwi 4,29,0; beq cr4,5f; lwz 9,0x4d8(27); cmpwi 19,0; li 5,8; lwz 0,0x6cc(9); stw 28,0x38(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); beq 4f; li 5,16; 4:; li 3,13; mr 4,29; bl _s80347BE4_4; 5:; lwz 0,0x5c8(27); cmpwi 0,0; beq 9f; cmpwi 22,0; beq 9f; beq cr4,9f; lwz 9,0x4d8(27); li 11,1; li 4,0; addi 31,26,3; lwz 0,0x6cc(9); stw 11,0x3c(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); lwz 3,0x4d8(27); bl _s80347BE4_5; lhz 30,0x1(26); li 3,152; li 4,2; mr 5,30; bl _s80347BE4_6; cmpwi 30,0; beq 11f; lis 9,-32702; mr 23,30; lfd f31,0x1e98(9); lis 26,-13311; addi 28,1,40; addi 24,1,24; addi 25,1,56; lis 21,17200; 6:; lhz 30,0x0(31); rlwinm 0,30,0,16,31; sth 0,-32768(26); lhzu 29,0x2(31); rlwinm 0,29,0,16,31; addi 31,31,2; sth 0,-32768(26); beq cr3,7f; lhz 0,0x0(31); addi 31,31,2; rlwinm 0,0,0,16,31; sth 0,-32768(26); 7:; beq cr4,8f; lhz 0,0x0(31); cmpwi 19,0; addi 31,31,2; rlwinm 0,0,0,16,31; sth 0,-32768(26); beq 8f; addi 31,31,2; 8:; li 4,0; li 5,12; mr 3,28; rlwinm 30,30,2,0,29; crxor 6,6,6; bl _s80347BE4_7; rlwinm 29,29,2,0,29; rlwinm 9,30,2,0,29; li 5,12; lfsx f0,9,20; li 4,0; add 9,9,20; mr 3,25; stfs f0,0x28(1); lfs f13,0x4(9); lwz 11,0x28(1); stfs f13,0x2c(1); lfs f0,0x8(9); stfs f0,0x30(1); lwz 0,0x4(28); lwz 9,0x8(28); stw 11,0x18(1); stw 0,0x4(24); stw 9,0x8(24); crxor 6,6,6; bl _s80347BE4_8; lbzx 0,22,29; lwz 5,0x4d8(27); add 8,29,22; extsb 0,0; mr 11,9; xoris 0,0,32768; mr 10,9; stw 0,0x4c(1); addi 6,5,2240; mr 3,24; mr 4,28; stw 21,0x48(1); addi 5,5,2192; addi 7,1,8; lfd f0,0x48(1); fsub f0,f0,f31; frsp f0,f0; stfs f0,0x38(1); lbz 0,0x1(8); lwz 30,0x38(1); extsb 0,0; xoris 0,0,32768; stw 0,0x4c(1); stw 21,0x48(1); lfd f0,0x48(1); fsub f0,f0,f31; frsp f0,f0; stfs f0,0x3c(1); lbz 0,0x2(8); extsb 0,0; xoris 0,0,32768; stw 0,0x4c(1); stw 21,0x48(1); lfd f0,0x48(1); fsub f0,f0,f31; frsp f0,f0; stfs f0,0x40(1); lwz 0,0x4(25); lwz 9,0x8(25); stw 30,0x28(1); stw 0,0x4(28); stw 9,0x8(28); bl _s80347BE4_9; lfs f0,0x8(1); addic. 23,23,-1; lfs f13,0xc(1); stfs f0,-32768(26); stfs f13,-32768(26); bne 6b; b 11f; 9:; cmpwi 19,0; beq 10f; addi 4,29,8; li 3,14; li 5,16; bl _s80347BE4_10; lwz 9,0x4d8(27); li 11,3; lwz 0,0x6cc(9); stw 11,0x3c(9); oris 0,0,32768; ori 0,0,1; stw 0,0x6cc(9); 10:; lwz 3,0x4d8(27); li 4,0; bl _s80347BE4_11; mr 3,26; mr 4,24; bl _s80347BE4_12; 11:; lwz 9,0x4dc(27); addi 9,9,24; stw 9,0x4dc(27); lwz 0,0x94(1); lwz 12,0x50(1); mtspr 8,0; lmw 19,0x54(1); lfd f31,0x88(1); mtcrf 24,12; addi 1,1,144"

extern "C" void _s80347BE4_0();
extern "C" void _s80347BE4_1();
extern "C" void _s80347BE4_2();
extern "C" void _s80347BE4_3();
extern "C" void _s80347BE4_4();
extern "C" void _s80347BE4_5();
extern "C" void _s80347BE4_6();
extern "C" void _s80347BE4_7();
extern "C" void _s80347BE4_8();
extern "C" void _s80347BE4_9();
extern "C" void _s80347BE4_10();
extern "C" void _s80347BE4_11();
extern "C" void _s80347BE4_12();

struct ENgcRenderer {
    void NgcGXDisplayList_EDLEntry();
};

void ENgcRenderer::NgcGXDisplayList_EDLEntry() {
}
