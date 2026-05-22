// 0x802DC598 EA::Allocator::GeneralAllocator::FindCoreBlockForAddress(void (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,3,1100; lwz 3,0x46c(3); cmpw 3,0; beq 2f; mr 9,0; 0:; cmplw 4,3; blt 1f; lwz 0,0x4(3); add 0,3,0; cmplw 4,0; bltlr; 1:; lwz 3,0x20(3); cmpw 3,9; bne 0b; 2:; li 3,0"
extern "C" int f_802DC598() {}
