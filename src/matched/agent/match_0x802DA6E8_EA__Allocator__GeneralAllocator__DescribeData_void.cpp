// 0x802DA6E8 EA::Allocator::GeneralAllocator::DescribeData(void (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 4,4,-8; bl _s802DA6E8_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802DA6E8_0();
extern "C" void f_802DA6E8() {}
