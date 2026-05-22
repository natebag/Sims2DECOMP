// 0x802B8980 AptScriptFunctionBase::GetInScopeChain(EAStringC (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-26960(13); mr 30,4; cmpwi 0,0; bne 2f; lwz 3,0x2c(3); cmpwi 3,0; beq 1f; mr 31,3; 0:; addi 3,31,12; mr 4,30; bl _s802B8980_0; mr. 3,3; bne 5f; lwz 31,0x20(31); cmpwi 31,0; bne 0b; b 4f; 1:; li 3,0; b 5f; 2:; mr 31,0; 3:; addi 3,31,12; mr 4,30; bl _s802B8980_1; mr. 3,3; bne 5f; lwz 31,0x20(31); cmpwi 31,0; bne 3b; 4:; li 3,0; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B8980_0();
extern "C" void _s802B8980_1();
extern "C" void f_802B8980() {}
