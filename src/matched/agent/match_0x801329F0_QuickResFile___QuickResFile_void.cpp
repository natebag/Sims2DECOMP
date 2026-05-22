// 0x801329F0 QuickResFile::~QuickResFile(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; lwz 11,-21508(13); addi 9,9,16768; stw 9,0xc(30); mr 29,4; mr 4,30; lwz 9,0x0(11); lha 3,0x110(9); lwz 0,0x114(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; mr 4,29; bl _s801329F0_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801329F0_0();
extern "C" void f_801329F0() {}
