// 0x802DB10C EA::Allocator::GeneralAllocator::Malloc(unsigned (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 3,0x4fc(31); mr 30,5; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DB10C_0; 0:; mr 3,31; mr 4,29; mr 5,30; bl _s802DB10C_1; mr 31,3; lwz 3,0x8(1); cmpwi 3,0; beq 1f; bl _s802DB10C_2; 1:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802DB10C_0();
extern "C" void _s802DB10C_1();
extern "C" void _s802DB10C_2();
extern "C" void f_802DB10C() {}
