// 0x8014ABC8 WantFear::Bookmark::Clear(void) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; li 9,0; sth 0,0x8(3); stw 9,0x4(3); sth 0,0x0(3); sth 0,0x2(3)"
extern "C" void f_8014ABC8() {}
