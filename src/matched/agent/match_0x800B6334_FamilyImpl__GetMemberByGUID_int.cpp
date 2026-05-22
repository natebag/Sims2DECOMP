// 0x800B6334 FamilyImpl::GetMemberByGUID(int) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x28(3); lwz 3,0x24(3); cmpw 3,0; beq 1f; mr 9,0; 0:; lwz 0,0x0(3); cmpw 0,4; beqlr; addi 3,3,4; cmpw 3,9; bne 0b; 1:; li 3,0"
extern "C" int f_800B6334() {}
