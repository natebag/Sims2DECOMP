// 0x8005A4A4 PlumbBob::StartNegativeRepMomentEffect(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x160(3); cmplwi 0,0; bnelr; lis 9,-32707; li 0,3; lfs f0,0x421c(9); stw 0,0x160(3); stfs f0,0x150(3)"
extern "C" void f_8005A4A4() {}
