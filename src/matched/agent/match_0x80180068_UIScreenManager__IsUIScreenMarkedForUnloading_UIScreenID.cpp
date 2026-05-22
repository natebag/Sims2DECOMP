// 0x80180068 UIScreenManager::IsUIScreenMarkedForUnloading(UIScreenID) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; bl _s80180068_0; cmpwi 3,-1; bne 0f; addic. 9,31,116; beq 0f; lwz 0,0x4(9); xori 30,0,3; subfic 9,30,0; adde 30,9,30; 0:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80180068_0();
extern "C" void f_80180068() {}
