// 0x8012B804 cXPersonImpl::SetCurrentActionText(BString2 (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,304; li 5,0; bl _s8012B804_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8012B804_0();
extern "C" void f_8012B804() {}
