// 0x802DBBF4 EA::Allocator::GeneralAllocator::Realloc(void (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,4; lwz 3,0x4fc(31); mr 30,5; mr 29,6; stw 3,0x8(1); cmpwi 3,0; beq 0f; bl _s802DBBF4_0; 0:; mr 3,31; mr 4,28; mr 5,30; mr 6,29; bl _s802DBBF4_1; mr 31,3; lwz 3,0x8(1); cmpwi 3,0; beq 1f; bl _s802DBBF4_2; 1:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s802DBBF4_0();
extern "C" void _s802DBBF4_1();
extern "C" void _s802DBBF4_2();
extern "C" void f_802DBBF4() {}
