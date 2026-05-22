// 0x801487F0 TreeSimImpl::GetStackSize(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,12; bl _s801487F0_0; extsh 3,3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801487F0_0();
extern "C" void f_801487F0() {}
