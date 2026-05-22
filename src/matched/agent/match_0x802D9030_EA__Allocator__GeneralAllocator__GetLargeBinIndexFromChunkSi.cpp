// 0x802D9030 EA::Allocator::GeneralAllocator::GetLargeBinIndexFromChunkSize(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 9,3,26,6,31; cmplwi 9,32; bgt 0f; addi 3,9,56; blr; 0:; rlwinm 9,3,23,9,31; cmplwi 9,20; bgt 1f; addi 3,9,91; blr; 1:; rlwinm 9,3,20,12,31; cmplwi 9,10; bgt 2f; addi 3,9,110; blr; 2:; rlwinm 9,3,17,15,31; cmplwi 9,4; bgt 3f; addi 3,9,119; blr; 3:; rlwinm 9,3,14,18,31; li 3,126; cmplwi 9,2; bgtlr; addi 3,9,124"
extern "C" int f_802D9030() {}
