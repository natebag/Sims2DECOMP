// 0x80189A34 HUDTarget::GetJobBarCount(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 3,0xca(3); cmpwi 3,0; bne 0f; li 3,5; blr; 0:; addi 3,3,2"
extern "C" int f_80189A34() {}
