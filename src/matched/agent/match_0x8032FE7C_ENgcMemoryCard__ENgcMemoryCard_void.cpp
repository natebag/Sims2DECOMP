// 0x8032FE7C ENgcMemoryCard::ENgcMemoryCard(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; mr 11,3; addi 9,9,-14552; li 0,0; stw 9,0x0(11); stw 0,0x4(11); stw 11,-26384(13)"
extern "C" void f_8032FE7C() {}
