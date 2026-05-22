// 0x802DB094 EA::Allocator::GeneralAllocator::ValidateHeap(EA::Allocator::GeneralAllocator::HeapValidationLevel) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,0x494(31); li 3,0; cmpwi 30,0; bne 0f; li 0,1; mr 3,31; stw 0,0x494(31); bl _s802DB094_0; stw 30,0x494(31); 0:; subfic 0,3,0; adde 3,0,3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802DB094_0();
extern "C" void f_802DB094() {}
