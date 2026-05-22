// 0x802DB900 EA::Allocator::GeneralAllocator::MallocAligned(unsigned (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 27,4; lwz 3,0x4fc(31); mr 30,5; mr 29,6; mr 28,7; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DB900_0; 0:; mr 3,31; mr 4,27; mr 5,30; mr 6,29; mr 7,28; bl _s802DB900_1; mr 31,3; lwz 3,0x8(1); cmpwi 3,0; beq 1f; bl _s802DB900_2; 1:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802DB900_0();
extern "C" void _s802DB900_1();
extern "C" void _s802DB900_2();
extern "C" void f_802DB900() {}
