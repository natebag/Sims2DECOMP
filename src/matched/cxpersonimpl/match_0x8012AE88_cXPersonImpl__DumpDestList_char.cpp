// 0x8012AE88 cXPersonImpl::DumpDestList(char (816 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-392(1); mfspr 0,8; stfd f27,0x160(1); stfd f28,0x168(1); stfd f29,0x170(1); stfd f30,0x178(1); stfd f31,0x180(1); stmw 20,0x130(1); stw 0,0x18c(1); mr 29,3; lis 9,-32706; mr 3,4; addi 4,9,-12888; bl _s8012AE88_0; mr. 28,3; beq 5f; lwz 11,0x0(29); li 31,0; lwz 10,0x4(11); lwz 9,0x4(10); lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,-21496(13); mr 30,3; lwz 9,0x0(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; mr 6,3; lis 4,-32706; addi 4,4,-12884; mr 5,30; mr 3,28; crxor 6,6,6; bl _s8012AE88_1; lwz 9,0x0(29); lis 4,-32706; addi 4,4,-12864; mr 3,28; lwz 6,0x68(9); lwz 5,0x6c(9); crxor 6,6,6; bl _s8012AE88_2; addi 9,29,1016; lwz 11,0x3f8(29); lwz 0,0x4(9); mr 22,9; subf 0,11,0; rlwinm. 9,0,29,3,31; beq 4f; addi 23,1,264; 0:; lwz 11,0x3f8(29); rlwinm 0,31,3,0,28; lis 4,-32706; mr 3,28; add 11,11,0; addi 4,4,-12844; lwz 9,0x0(11); lwz 10,0x4(11); mr 5,31; addi 24,31,1; stw 9,0x108(1); stw 10,0x10c(1); lwz 6,0x4(23); lwz 7,0x108(1); crxor 6,6,6; bl _s8012AE88_3; lwz 0,0x3f8(29); lwz 9,0x4(22); subf 9,0,9; srawi 9,9,3; addi 9,9,-1; cmplw 31,9; bge 3f; rlwinm 11,24,3,0,28; lis 9,-32706; add 11,0,11; lwz 5,0x108(1); lwz 6,0x10c(1); lwz 7,0x0(11); lwz 8,0x4(11); lis 10,-32706; lis 11,-32706; lfd f30,-12776(9); lfs f29,-12768(11); lis 9,-32706; lis 11,-32706; addi 31,1,272; lfs f27,-12764(9); mr 27,31; lfd f28,-12784(11); addi 25,1,280; stw 7,0x118(1); stw 8,0x11c(1); addi 26,1,288; stw 5,0x120(1); stw 6,0x124(1); lis 30,17200; lfs f31,-12792(10); lis 20,-32706; lis 21,-32706; 1:; lwz 11,0x4(23); lwz 9,0x4(25); mr 8,10; xoris 0,11,32768; mr 7,10; stw 0,0x12c(1); subf 9,11,9; xoris 9,9,32768; lwz 11,0x108(1); stw 30,0x128(1); mr 6,10; mr 5,10; lwz 0,0x118(1); lfd f13,0x128(1); mr 3,27; stw 9,0x12c(1); xoris 10,11,32768; fsub f13,f13,f30; subf 0,11,0; stw 30,0x128(1); frsp f13,f13; xoris 0,0,32768; lfd f0,0x128(1); mr 4,26; fsub f0,f0,f30; frsp f0,f0; fmadds f0,f31,f0,f13; fadds f0,f0,f29; fmr f13,f0; fctiwz f12,f13; stfd f12,0x128(1); lwz 7,0x12c(1); stw 10,0x12c(1); stw 7,0x4(27); stw 30,0x128(1); lfd f13,0x128(1); stw 0,0x12c(1); fsub f13,f13,f30; stw 30,0x128(1); frsp f13,f13; lfd f0,0x128(1); fsub f0,f0,f30; frsp f0,f0; fmadds f0,f31,f0,f13; fadds f0,f0,f29; fmr f13,f0; fctiwz f11,f13; stfd f11,0x128(1); lwz 9,0x12c(1); stw 9,0x110(1); bl _s8012AE88_4; cmpwi 3,1; beq 2f; lwz 6,0x4(31); li 4,256; lwz 7,0x110(1); addi 5,20,-12820; fmr f1,f31; addi 3,1,8; creqv 6,6,6; bl _s8012AE88_5; mr 3,28; addi 4,21,-12800; addi 5,1,8; crxor 6,6,6; bl _s8012AE88_6; lwz 9,0x110(1); lwz 10,0x114(1); stw 9,0x120(1); stw 10,0x124(1); 2:; fadds f31,f31,f27; fmr f0,f31; fcmpu 0,f0,f28; blt 1b; 3:; lwz 9,0x4(22); mr 31,24; lwz 0,0x3f8(29); subf 9,0,9; srawi 9,9,3; cmplw 31,9; blt 0b; 4:; lis 4,-32706; mr 3,28; addi 4,4,-12796; crxor 6,6,6; bl _s8012AE88_7; mr 3,28; bl _s8012AE88_8; 5:; lwz 0,0x18c(1); mtspr 8,0; lmw 20,0x130(1); lfd f27,0x160(1); lfd f28,0x168(1); lfd f29,0x170(1); lfd f30,0x178(1); lfd f31,0x180(1); addi 1,1,392"

extern "C" void _s8012AE88_0();
extern "C" void _s8012AE88_1();
extern "C" void _s8012AE88_2();
extern "C" void _s8012AE88_3();
extern "C" void _s8012AE88_4();
extern "C" void _s8012AE88_5();
extern "C" void _s8012AE88_6();
extern "C" void _s8012AE88_7();
extern "C" void _s8012AE88_8();

struct cXPersonImpl {
    void DumpDestList();
};

void cXPersonImpl::DumpDestList() {
}
