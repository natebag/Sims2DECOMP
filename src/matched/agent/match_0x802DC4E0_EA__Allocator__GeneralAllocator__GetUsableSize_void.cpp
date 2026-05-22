// 0x802DC4E0 EA::Allocator::GeneralAllocator::GetUsableSize(void (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 1f; addi 4,4,-8; lwz 0,0x4(4); rlwinm 3,0,0,0,28; andi. 9,0,2; beq 0f; addi 3,3,-8; blr; 0:; add 9,4,3; lwz 0,0x4(9); andi. 9,0,1; addi 3,3,-4; bnelr; 1:; li 3,0"
extern "C" int f_802DC4E0() {}
