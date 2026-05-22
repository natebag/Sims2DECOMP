// 0x800EB4F8 cXObjectImpl::CanContributeLight(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,40; li 4,40; bl _s800EB4F8_0; lhz 3,0x0(3); rlwinm 3,3,22,31,31; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800EB4F8_0();
extern "C" void f_800EB4F8() {}
