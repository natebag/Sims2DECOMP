// 0x801A0934 CASRoommateTarget::GetSelectedSlot(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x90(3)"
extern "C" int f_801A0934() {}
