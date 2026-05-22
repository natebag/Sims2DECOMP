// 0x8032B5D8 ParticleManager::AllocateAndLoadResource(EFile (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,4; mr 27,5; lis 3,-32692; mr 29,6; li 4,60; li 5,8; addi 3,3,6092; bl _s8032B5D8_0; bl _s8032B5D8_1; mr 30,3; mr 4,28; stw 29,0x8(30); mr 5,27; bl _s8032B5D8_2; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8032B5D8_0();
extern "C" void _s8032B5D8_1();
extern "C" void _s8032B5D8_2();
extern "C" void f_8032B5D8() {}
