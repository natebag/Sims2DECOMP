// 0x8012953C cXPersonImpl::IsSelected(void) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); lwz 3,0x84(9); rlwinm 3,3,31,31,31"
extern "C" int f_8012953C() {}
