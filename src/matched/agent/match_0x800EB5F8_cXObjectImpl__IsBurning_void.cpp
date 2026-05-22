// 0x800EB5F8 cXObjectImpl::IsBurning(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,40; li 4,8; bl _s800EB5F8_0; lhz 3,0x0(3); rlwinm 3,3,23,31,31; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800EB5F8_0();
extern "C" void f_800EB5F8() {}
