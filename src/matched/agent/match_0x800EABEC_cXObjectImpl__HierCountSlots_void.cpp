// 0x800EABEC cXObjectImpl::HierCountSlots(void) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x90(3); lwz 3,0x94(3); subf 3,0,3; srawi 3,3,5"
extern "C" int f_800EABEC() {}
