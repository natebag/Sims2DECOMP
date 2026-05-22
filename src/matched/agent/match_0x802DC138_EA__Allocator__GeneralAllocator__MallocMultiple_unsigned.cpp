// 0x802DC138 EA::Allocator::GeneralAllocator::MallocMultiple(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 3,0x4fc(31); mr 29,5; mr 28,6; mr 27,7; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DC138_0; 0:; mr 4,30; mr 3,31; mr 6,29; mr 7,28; mr 8,27; mr 5,4; bl _s802DC138_1; mr 31,3; lwz 3,0x8(1); cmpwi 3,0; beq 1f; bl _s802DC138_2; 1:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s802DC138_0();
extern "C" void _s802DC138_1();
extern "C" void _s802DC138_2();
extern "C" void f_802DC138() {}
