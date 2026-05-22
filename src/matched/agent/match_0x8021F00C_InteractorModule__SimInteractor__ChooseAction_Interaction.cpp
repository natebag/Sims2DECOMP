// 0x8021F00C InteractorModule::SimInteractor::ChooseAction(Interaction (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,4; beq 0f; mr 3,31; bl _s8021F00C_0; cmpwi 3,0; bne 1f; 0:; li 3,0; b 2f; 1:; mr 3,31; bl _s8021F00C_1; lwz 9,0x4(3); mr 4,31; lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8021F00C_0();
extern "C" void _s8021F00C_1();
extern "C" void f_8021F00C() {}
