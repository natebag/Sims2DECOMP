// 0x80324D60 EFontManager::AllocateAndLoadResource(EFile (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 28,6; bl _s80324D60_0; li 5,16; li 6,0; li 7,0; li 4,108; bl _s80324D60_1; bl _s80324D60_2; mr 30,3; mr 4,29; stw 28,0x8(30); lwz 9,0x0(30); lha 3,0x48(9); lwz 0,0x4c(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80324D60_0();
extern "C" void _s80324D60_1();
extern "C" void _s80324D60_2();
extern "C" void f_80324D60() {}
