// 0x80075DEC SkinCompositor::CreateSkin(ERTexture (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,7; stw 30,0x10(31); li 3,16; stw 6,0x14(31); stw 4,0x18(31); stb 5,0x1c(31); bl _s80075DEC_0; bl _s80075DEC_1; lwz 9,0x14(31); stw 3,0x24(31); lwz 4,0x84(9); bl _s80075DEC_2; lwz 9,0x24(31); cmpwi 30,0; lhz 11,-21264(13); stw 30,0xc(9); beq 0f; lhz 0,-32202(13); b 1f; 0:; lhz 0,-32204(13); 1:; mullw 4,11,0; rlwinm 4,4,0,16,31; mr 3,31; bl _s80075DEC_3; mr 3,31; bl _s80075DEC_4; mr 3,31; bl _s80075DEC_5; mr 3,31; bl _s80075DEC_6; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80075DEC_0();
extern "C" void _s80075DEC_1();
extern "C" void _s80075DEC_2();
extern "C" void _s80075DEC_3();
extern "C" void _s80075DEC_4();
extern "C" void _s80075DEC_5();
extern "C" void _s80075DEC_6();
extern "C" void f_80075DEC() {}
