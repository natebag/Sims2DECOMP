// 0x80096904 StateMachineManager::DrawMachines(ERC (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-21500(13); mr 4,3; cmpwi 0,0; beq 0f; mr 3,0; bl _s80096904_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80096904_0();
extern "C" void f_80096904() {}
