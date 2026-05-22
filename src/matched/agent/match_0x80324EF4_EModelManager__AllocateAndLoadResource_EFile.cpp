// 0x80324EF4 EModelManager::AllocateAndLoadResource(EFile (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; lis 3,-32692; mr 29,6; li 4,384; li 5,8; addi 3,3,-27556; bl _s80324EF4_0; bl _s80324EF4_1; mr 30,3; mr 4,28; stw 29,0x8(30); bl _s80324EF4_2; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80324EF4_0();
extern "C" void _s80324EF4_1();
extern "C" void _s80324EF4_2();
extern "C" void f_80324EF4() {}
