// 0x800EB344 cXObjectImpl::GetSelFile(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x8c(3); lwz 3,0x0(9); cmpwi 3,0; bne 0f; mr 3,9; bl _s800EB344_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800EB344_0();
extern "C" void f_800EB344() {}
