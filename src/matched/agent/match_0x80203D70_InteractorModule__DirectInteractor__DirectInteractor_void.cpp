// 0x80203D70 InteractorModule::DirectInteractor::DirectInteractor(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80203D70_0; lis 9,-32697; lfs f0,-23848(13); li 0,0; addi 9,9,-32608; li 11,1; stw 9,0x5c(30); stw 11,0x64(30); mr 3,30; stfs f0,0x74(30); stw 0,0x80(30); stw 0,0x70(30); stw 0,0x78(30); stw 0,0x7c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80203D70_0();
extern "C" void f_80203D70() {}
