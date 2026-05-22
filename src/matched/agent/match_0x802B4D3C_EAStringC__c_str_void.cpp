// 0x802B4D3C EAStringC::c_str(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); addi 3,3,8"
extern "C" int f_802B4D3C() {}
