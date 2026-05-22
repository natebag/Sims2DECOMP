// 0x800DCB50 cXObjectImpl::IsInWorld(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x6c(3); srawi. 9,0,4; ble 0f; lwz 0,0x68(3); srawi. 9,0,4; bgt 1f; 0:; li 3,0; blr; 1:; li 3,1"
extern "C" int f_800DCB50() {}
