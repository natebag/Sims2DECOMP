// 0x800F8178 ObjectModuleImpl::ClearAwarenessOfObject(cXObject (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addi 9,3,8280; lwz 31,0x2058(3); lwz 0,0x4(9); mr 29,4; cmpw 31,0; beq 3f; mr 30,9; 0:; lwz 9,0x0(31); li 11,0; cmpwi 9,0; beq 1f; lwz 11,0x4(9); li 4,2; lwz 9,0x0(11); lwz 3,0x0(9); bl _s800F8178_0; mr 11,3; 1:; cmpwi 11,0; beq 2f; lwz 9,0x4(11); mr 4,29; lha 3,0x2f8(9); lwz 0,0x2fc(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; bne 0b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800F8178_0();
extern "C" void f_800F8178() {}
