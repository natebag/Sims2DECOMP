// 0x802B88AC AptScriptFunctionBase::SetWhereExistsInScopeChain(EAStringC (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 0,-26960(13); mr 29,4; mr 28,5; cmpwi 0,0; bne 4f; lwz 3,0x2c(3); cmpwi 3,0; beq 2f; mr 31,3; 0:; addi 30,31,12; mr 4,29; mr 3,30; bl _s802B88AC_0; cmpwi 3,0; bne 1f; lwz 31,0x20(31); cmpwi 31,0; bne 0b; b 6f; 1:; mr 3,30; mr 4,29; mr 5,28; bl _s802B88AC_1; li 3,1; b 7f; 2:; li 3,0; b 7f; 3:; mr 3,30; mr 4,29; mr 5,28; bl _s802B88AC_2; li 3,1; b 7f; 4:; mr 31,0; 5:; addi 30,31,12; mr 4,29; mr 3,30; bl _s802B88AC_3; cmpwi 3,0; bne 3b; lwz 31,0x20(31); cmpwi 31,0; bne 5b; 6:; li 3,0; 7:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802B88AC_0();
extern "C" void _s802B88AC_1();
extern "C" void _s802B88AC_2();
extern "C" void _s802B88AC_3();
extern "C" void f_802B88AC() {}
