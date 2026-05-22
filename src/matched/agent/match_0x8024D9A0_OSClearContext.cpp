// 0x8024D9A0 OSClearContext (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,0; sth 5,0x1a0(3); lis 4,-32768; sth 5,0x1a2(3); lwz 0,0xd8(4); cmplw 3,0; bne 0f; stw 5,0xd8(4); 0:"
extern "C" void f_8024D9A0() {}
