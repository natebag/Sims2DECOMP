// 0x802D0ED4 EAHeap::ValidateHeap(EA::Allocator::GeneralAllocator::HeapValidationLevel) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s802D0ED4_0; cmplwi 3,1024; li 3,1; ble 0f; mr 3,31; bl _s802D0ED4_1; mr 3,31; mr 4,30; bl _s802D0ED4_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D0ED4_0();
extern "C" void _s802D0ED4_1();
extern "C" void _s802D0ED4_2();
extern "C" void f_802D0ED4() {}
