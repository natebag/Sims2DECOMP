// 0x80312BE8 EResPrefetch::BeginPreFetch(char (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,5; mr 29,4; bl _s80312BE8_0; li 3,20; bl _s80312BE8_1; lwz 11,-22652(13); mr 30,3; mr 4,29; lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; stw 3,0xc(30); li 0,1; li 9,0; stw 0,0x0(30); stw 27,0x4(30); addi 3,28,908; stw 9,0x10(30); mr 4,30; li 5,1; bl _s80312BE8_2; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80312BE8_0();
extern "C" void _s80312BE8_1();
extern "C" void _s80312BE8_2();
extern "C" void f_80312BE8() {}
