// 0x802DB0E8 EA::Allocator::GeneralAllocator::SetAutoHeapValidation(EA::Allocator::GeneralAllocator::HeapValidationLevel, (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 5,0; stw 5,0x48c(3); bne 0f; li 0,1; stw 0,0x48c(3); 0:; li 0,0; stw 4,0x488(3); stw 0,0x490(3)"
extern "C" void f_802DB0E8() {}
