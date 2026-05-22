// 0x801C1144 M2MTarget::GetMemCardPort(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; lwz 3,0x10c(9); cmplwi 3,65535; bnelr; lwz 3,0x110(9)"
extern "C" int f_801C1144() {}
