// 0x8031323C EResPrefetchFile::SetStreamBuffer(EResourceManager (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 30,4; mr 28,6; mr 27,7; mr 26,8; mr 3,5; bl _s8031323C_0; mr 5,3; mr 4,30; mr 3,29; mr 6,28; mr 7,27; mr 8,26; bl _s8031323C_1; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8031323C_0();
extern "C" void _s8031323C_1();
extern "C" void f_8031323C() {}
