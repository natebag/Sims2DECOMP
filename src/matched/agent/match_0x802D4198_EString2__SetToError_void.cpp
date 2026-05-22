// 0x802D4198 EString2::SetToError(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32700; addi 9,9,-4780; stw 9,0x0(3)"
extern "C" void f_802D4198() {}
