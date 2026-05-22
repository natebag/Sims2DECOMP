// 0x802A8B00 EAStringC::IsEmpty(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(3); lis 3,-32700; addi 3,3,-6476; xor 3,0,3; subfic 9,3,0; adde 3,9,3"
extern "C" int f_802A8B00() {}
