// 0x800EB580 cXObjectImpl::IsBroken(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,40; li 4,15; bl _s800EB580_0; lha 0,0x0(3); li 3,1; cmpwi 0,0; bne 0f; li 3,0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800EB580_0();
extern "C" void f_800EB580() {}
