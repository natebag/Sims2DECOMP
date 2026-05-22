// 0x800EB414 cXObjectImpl::GetRoutingSlot(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,60; lwz 3,0xa0(3); add 3,3,4"
extern "C" int f_800EB414() {}
