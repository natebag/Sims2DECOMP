// 0x800BC984 HouseImpl::GetFamily(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x14(3)"
extern "C" int f_800BC984() {}
