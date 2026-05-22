// 0x802DC91C EA::Allocator::GeneralAllocator::FreeCore(EA::Allocator::GeneralAllocator::CoreBlock (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x10(4); li 9,0; cmpwi 0,0; beq 0f; lwz 0,0x18(4); cmpwi 0,0; beq 0f; lwz 5,0x4(4); mtspr 8,0; lwz 6,0x1c(4); blrl; li 9,1; 0:; mr 3,9; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802DC91C() {}
