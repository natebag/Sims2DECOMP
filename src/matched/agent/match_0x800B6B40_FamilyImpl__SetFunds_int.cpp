// 0x800B6B40 FamilyImpl::SetFunds(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 0,15; ori 0,0,16959; cmpw 4,0; bgt 0f; stw 4,0x14(3); blr; 0:; stw 0,0x14(3)"
extern "C" void f_800B6B40() {}
