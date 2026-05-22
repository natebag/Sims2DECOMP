// 0x8019B404 CASFashionTarget::SetVariableSubnav(UIScreenID, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr. 30,6; beq 0f; cmpwi 4,17; bne 0f; mr 4,5; lwz 3,0x8c(31); addi 5,1,8; bl _s8019B404_0; cmpwi 3,0; beq 0f; lwz 5,0x8(1); mr 3,31; mr 4,30; bl _s8019B404_1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8019B404_0();
extern "C" void _s8019B404_1();
extern "C" void f_8019B404() {}
