// 0x80324904 EDatasetManager::EDatasetManager(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80324904_0; lis 11,-32702; lis 9,-32697; lfs f0,0xca0(11); addi 9,9,-17712; stw 9,0xd1c(30); mr 3,30; stfs f0,0xd20(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80324904_0();
extern "C" void f_80324904() {}
