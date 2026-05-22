// 0x800EB488 cXObjectImpl::GetBuildModeType(void) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,0x8c(3); bl _s800EB488_0; lwz 9,0x38(3); lha 3,0x8a(9); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800EB488_0();
extern "C" void f_800EB488() {}
