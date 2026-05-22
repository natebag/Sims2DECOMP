// 0x800B63A4 FamilyImpl::GetIndexedMember(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; blt 0f; lwz 9,0x24(3); lwz 0,0x28(3); subf 0,9,0; srawi 0,0,2; cmpw 4,0; blt 1f; 0:; li 3,0; blr; 1:; rlwinm 3,4,2,0,29; add 3,9,3"
extern "C" int f_800B63A4() {}
