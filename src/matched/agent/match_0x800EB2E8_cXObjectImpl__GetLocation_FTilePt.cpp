// 0x800EB2E8 cXObjectImpl::GetLocation(FTilePt (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x68(3); lwz 10,0x6c(3); stw 9,0x0(4); stw 10,0x4(4)"
extern "C" void f_800EB2E8() {}
