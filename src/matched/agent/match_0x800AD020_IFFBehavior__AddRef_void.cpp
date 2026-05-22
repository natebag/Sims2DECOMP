// 0x800AD020 IFFBehavior::AddRef(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 3,0x10(9); addi 3,3,1; stw 3,0x10(9)"
extern "C" void f_800AD020() {}
