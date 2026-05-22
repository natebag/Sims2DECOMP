// 0x8020B51C InteractorModule::InteractorManager::ChangeActiveInteractorToNull(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s8020B51C_0; cmpwi 3,0; beq 0f; li 0,1; lbz 9,0x3c(31); slw 0,0,30; rlwinm 0,0,0,24,31; and. 11,9,0; bne 0f; stw 11,0xc(1); or 0,0,9; stb 0,0x3c(31); li 10,-1; lwz 8,0x2c(31); rlwinm 9,30,3,0,28; stw 10,0x8(1); li 3,1; lwz 0,0xc(1); add 11,8,9; stwx 10,8,9; stw 0,0x4(11); b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8020B51C_0();
extern "C" void f_8020B51C() {}
