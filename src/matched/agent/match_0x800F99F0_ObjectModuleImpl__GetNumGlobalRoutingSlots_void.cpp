// 0x800F99F0 ObjectModuleImpl::GetNumGlobalRoutingSlots(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x2078(3); lis 0,-4370; lwz 3,0x207c(3); ori 0,0,61167; subf 3,9,3; mullw 3,3,0; srawi 3,3,2"
extern "C" int f_800F99F0() {}
