// 0x8020ADBC InteractorModule::InteractorInputManager::InteractorInputManager(int) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 28,3; li 0,0; stw 30,0x4(28); rlwinm 3,30,5,0,26; stw 0,0x0(28); ori 3,3,8; addi 31,30,-1; bl _s8020ADBC_0; addi 29,3,8; cmpwi 30,0; stw 30,-8(29); mr 30,29; beq 1f; 0:; mr 3,30; bl _s8020ADBC_1; addi 30,30,32; cmpwi 31,0; addi 31,31,-1; bne 0b; 1:; stw 29,0x0(28); mr 3,28; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8020ADBC_0();
extern "C" void _s8020ADBC_1();
extern "C" void f_8020ADBC() {}
