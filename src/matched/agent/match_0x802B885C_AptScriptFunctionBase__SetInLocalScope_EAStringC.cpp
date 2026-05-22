// 0x802B885C AptScriptFunctionBase::SetInLocalScope(EAStringC (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-26960(13); mr 31,4; mr 30,5; cmpwi 0,0; bne 0f; bl _s802B885C_0; 0:; lwz 3,-26960(13); mr 4,31; mr 5,30; addi 3,3,12; bl _s802B885C_1; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B885C_0();
extern "C" void _s802B885C_1();
extern "C" void f_802B885C() {}
