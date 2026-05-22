// 0x802DC520 EA::Allocator::GeneralAllocator::GetTotalCoreSize(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x46c(3); addi 0,3,1100; li 11,0; cmpw 9,0; beq 1f; mr 3,0; 0:; lwz 0,0x4(9); lwz 9,0x20(9); add 11,11,0; cmpw 9,3; bne 0b; 1:; mr 3,11"
extern "C" int f_802DC520() {}
