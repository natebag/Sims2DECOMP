// 0x800EB3F4 cXObjectImpl::GetNumRoutingSlots(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0xa0(3); lis 0,-4370; lwz 3,0xa4(3); ori 0,0,61167; subf 3,9,3; mullw 3,3,0; srawi 3,3,2"
extern "C" int f_800EB3F4() {}
