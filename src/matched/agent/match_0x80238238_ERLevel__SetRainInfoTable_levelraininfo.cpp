// 0x80238238 ERLevel::SetRainInfoTable(levelraininfo (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addis 3,3,3; stw 4,-7080(3)"
extern "C" void f_80238238() {}
