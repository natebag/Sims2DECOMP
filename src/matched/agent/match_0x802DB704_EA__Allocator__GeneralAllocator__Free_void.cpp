// 0x802DB704 EA::Allocator::GeneralAllocator::Free(void (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 3,0x4fc(31); stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DB704_0; 0:; mr 3,31; mr 4,30; bl _s802DB704_1; lwz 3,0x8(1); cmpwi 3,0; beq 1f; bl _s802DB704_2; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802DB704_0();
extern "C" void _s802DB704_1();
extern "C" void _s802DB704_2();
extern "C" void f_802DB704() {}
