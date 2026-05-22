// 0x800C189C Interaction::SetUniqueID(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-32024(13); addi 9,9,1; stw 9,-32024(13); stw 9,0x38(3)"
extern "C" void f_800C189C() {}
