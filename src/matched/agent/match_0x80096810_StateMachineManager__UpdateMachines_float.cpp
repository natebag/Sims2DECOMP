// 0x80096810 StateMachineManager::UpdateMachines(float) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-21500(13); cmpwi 3,0; beq 0f; bl _s80096810_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80096810_0();
extern "C" void f_80096810() {}
