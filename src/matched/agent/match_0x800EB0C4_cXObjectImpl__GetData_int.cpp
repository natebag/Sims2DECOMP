// 0x800EB0C4 cXObjectImpl::GetData(int) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,40; bl _s800EB0C4_0; lha 3,0x0(3); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800EB0C4_0();
extern "C" void f_800EB0C4() {}
