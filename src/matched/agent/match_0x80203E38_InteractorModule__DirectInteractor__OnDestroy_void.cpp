// 0x80203E38 InteractorModule::DirectInteractor::OnDestroy(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80203E38_0; mr 4,30; bl _s80203E38_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80203E38_0();
extern "C" void _s80203E38_1();
extern "C" void f_80203E38() {}
