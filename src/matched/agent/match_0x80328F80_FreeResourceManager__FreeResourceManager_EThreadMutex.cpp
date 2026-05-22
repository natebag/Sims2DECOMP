// 0x80328F80 FreeResourceManager::FreeResourceManager(EThreadMutex (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; bl _s80328F80_0; li 0,0; li 9,800; stw 29,0x1c(30); mr 3,30; stw 0,0xca0(30); stw 9,0xca4(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80328F80_0();
extern "C" void f_80328F80() {}
