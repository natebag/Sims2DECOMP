// 0x800F96E4 ObjectModuleImpl::SetTileObjectID(CTilePt (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 28,5; mr 3,30; bl _s800F96E4_0; mr 31,3; mr 3,30; bl _s800F96E4_1; cmplwi 31,63; bgt 0f; cmplwi 3,63; bgt 0f; add 0,31,31; rlwinm 9,3,7,0,24; add 0,0,9; addi 11,29,52; sthx 28,11,0; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800F96E4_0();
extern "C" void _s800F96E4_1();
extern "C" void f_800F96E4() {}
