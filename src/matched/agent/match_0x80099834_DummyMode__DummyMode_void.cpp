// 0x80099834 DummyMode::DummyMode(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lis 9,-32698; mr 11,3; addi 9,9,-7728; li 0,0; stw 9,0x8(11); li 10,2; stw 0,0x8(1); stw 10,0x0(11); stw 10,0x10(1); addi 1,1,24"
extern "C" void f_80099834() {}
