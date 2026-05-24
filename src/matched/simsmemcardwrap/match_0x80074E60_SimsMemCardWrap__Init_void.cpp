// 0x80074E60 SimsMemCardWrap::Init(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-26384(13); lis 4,-32707; addi 4,4,22840; lwz 9,0x0(11); lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26384(13); li 4,1; li 5,8192; lwz 9,0x0(11); lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,11,3; blrl; lwz 29,-26384(13); lwz 30,0x0(29); lha 0,0xb8(30); addi 30,30,184; add 29,29,0; bl _s80074E60_0; lwz 0,0x4(30); mr 5,3; li 4,2; mr 3,29; mtspr 8,0; blrl; bl _s80074E60_1; mr 30,3; lis 3,-32707; mr 4,30; addi 3,3,22856; crxor 6,6,6; bl _s80074E60_2; lis 3,-32707; rlwinm 4,30,19,13,31; addi 3,3,22892; crxor 6,6,6; bl _s80074E60_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80074E60_0();
extern "C" void _s80074E60_1();
extern "C" void _s80074E60_2();
extern "C" void _s80074E60_3();

struct SimsMemCardWrap {
    void Init();
};

void SimsMemCardWrap::Init() {
}
