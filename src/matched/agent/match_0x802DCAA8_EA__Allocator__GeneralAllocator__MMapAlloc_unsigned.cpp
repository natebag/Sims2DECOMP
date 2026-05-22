// 0x802DCAA8 EA::Allocator::GeneralAllocator::MMapAlloc(unsigned (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,5; mr 3,30; bl _s802DCAA8_0; mr. 3,3; beq 0f; cmpwi 31,0; beq 0f; stw 30,0x0(31); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802DCAA8_0();
extern "C" void f_802DCAA8() {}
