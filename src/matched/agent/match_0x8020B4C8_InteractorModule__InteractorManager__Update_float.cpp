// 0x8020B4C8 InteractorModule::InteractorManager::Update(float) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; lwz 0,0x0(31); cmpwi 0,0; beq 0f; lwz 3,-28512(13); bl _s8020B4C8_0; mr 3,31; fmr f1,f31; bl _s8020B4C8_1; 0:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s8020B4C8_0();
extern "C" void _s8020B4C8_1();
extern "C" void f_8020B4C8() {}
