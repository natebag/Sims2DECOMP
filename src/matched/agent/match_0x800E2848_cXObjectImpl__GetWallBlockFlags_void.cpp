// 0x800E2848 cXObjectImpl::GetWallBlockFlags(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); addi 30,3,40; li 4,53; mr 3,30; bl _s800E2848_0; lha 31,0x0(3); cmpwi 31,0; beq 0f; mr 3,30; li 4,1; bl _s800E2848_1; lha 0,0x0(3); slw 31,31,0; srawi 9,31,8; or 31,31,9; rlwinm 31,31,0,24,31; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800E2848_0();
extern "C" void _s800E2848_1();
extern "C" void f_800E2848() {}
