// 0x80205BB0 InteractorModule::DirectInteractor::ChooseAction(Interaction (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,4; li 3,0; beq 0f; mr 3,31; bl _s80205BB0_0; lwz 9,0x4(3); mr 4,31; lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80205BB0_0();
extern "C" void f_80205BB0() {}
