// 0x8018003C UIScreenManager::IsUIScreenUnloaded(UIScreenID) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8018003C_0; subfic 3,3,-1; subfic 0,3,0; adde 3,0,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8018003C_0();
extern "C" void f_8018003C() {}
