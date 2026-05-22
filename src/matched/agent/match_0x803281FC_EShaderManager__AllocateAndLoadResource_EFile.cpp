// 0x803281FC EShaderManager::AllocateAndLoadResource(EFile (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; lis 3,-32692; mr 29,6; li 4,108; li 5,8; addi 3,3,-17444; bl _s803281FC_0; bl _s803281FC_1; mr 30,3; mr 4,28; stw 29,0x8(30); lwz 9,0x0(30); lha 3,0x48(9); lwz 0,0x4c(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s803281FC_0();
extern "C" void _s803281FC_1();
extern "C" void f_803281FC() {}
