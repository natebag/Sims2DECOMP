// 0x803230C4 EBinaryManager::AllocateAndLoadResource(EFile (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,6; mr 29,4; mr 28,5; bl _s803230C4_0; li 4,28; li 5,0; bl _s803230C4_1; bl _s803230C4_2; mr 30,3; mr 4,29; stw 27,0x8(30); mr 5,28; bl _s803230C4_3; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803230C4_0();
extern "C" void _s803230C4_1();
extern "C" void _s803230C4_2();
extern "C" void _s803230C4_3();
extern "C" void f_803230C4() {}
