// 0x80054A08 EIObjectMan::Init(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-26392(13); li 4,1; lwz 9,0x0(11); lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,11,3; blrl; mr 30,3; lis 4,-32707; addi 4,4,13640; bl _s80054A08_0; lis 9,-32707; mr 3,30; lfs f1,0x3568(9); fmr f2,f1; bl _s80054A08_1; lwz 11,-26392(13); mr 4,30; lwz 9,0x0(11); lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; stw 3,-32396(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80054A08_0();
extern "C" void _s80054A08_1();
extern "C" void f_80054A08() {}
