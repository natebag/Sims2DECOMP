// 0x802F9B20 ERC::IsOpen(void) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x18(3); li 3,1; cmplwi 0,0; bnelr; li 3,0"
extern "C" int f_802F9B20() {}
