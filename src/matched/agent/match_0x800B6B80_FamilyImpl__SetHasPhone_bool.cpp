// 0x800B6B80 FamilyImpl::SetHasPhone(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x34(3); cmplwi 4,0; clrlwi 0,0,30; stw 0,0x34(3); beqlr; ori 0,0,1; stw 0,0x34(3)"
extern "C" void f_800B6B80() {}
