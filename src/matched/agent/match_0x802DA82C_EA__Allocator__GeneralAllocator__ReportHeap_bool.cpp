// 0x802DA82C EA::Allocator::GeneralAllocator::ReportHeap(bool (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,6; mr 30,3; mr 6,7; mr 26,5; mr 7,8; li 28,0; mr 8,9; mr. 27,4; beq 2f; li 4,0; mr 5,29; bl _s802DA82C_0; mr. 31,3; beq 1f; mr 3,30; mr 4,31; mr 5,29; li 28,1; bl _s802DA82C_1; mr. 3,3; beq 1f; 0:; mr 4,26; mtspr 8,27; blrl; mr 28,3; mr 4,31; mr 3,30; mr 5,29; bl _s802DA82C_2; cmpwi 28,0; beq 1f; cmpwi 3,0; bne 0b; 1:; mr 3,30; mr 4,31; bl _s802DA82C_3; 2:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802DA82C_0();
extern "C" void _s802DA82C_1();
extern "C" void _s802DA82C_2();
extern "C" void _s802DA82C_3();
extern "C" void f_802DA82C() {}
