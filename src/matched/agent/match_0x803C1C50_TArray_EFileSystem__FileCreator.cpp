// 0x803C1C50 TArray<EFileSystem::FileCreator, (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 5,0x4(3); li 6,1; bl _s803C1C50_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803C1C50_0();
extern "C" void f_803C1C50() {}
