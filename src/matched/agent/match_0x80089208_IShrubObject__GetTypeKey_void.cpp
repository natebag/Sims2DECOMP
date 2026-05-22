// 0x80089208 IShrubObject::GetTypeKey(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lmw 29,0xc(1); addi 1,1,24"
extern "C" int f_80089208() {}
