// 0x800F9F20 cXObjectImpl::HandleBreakpoint(StackElem (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x0(3); bl _s800F9F20_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800F9F20_0();
extern "C" void f_800F9F20() {}
