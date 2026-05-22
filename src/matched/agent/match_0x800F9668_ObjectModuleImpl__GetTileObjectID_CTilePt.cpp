// 0x800F9668 ObjectModuleImpl::GetTileObjectID(CTilePt (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 3,30; bl _s800F9668_0; mr 31,3; mr 3,30; bl _s800F9668_1; cmpwi 31,63; bgt 0f; cmpwi 3,63; bgt 0f; cmpwi 31,0; blt 0f; cmpwi 3,0; bge 1f; 0:; li 3,0; b 2f; 1:; rlwinm 9,3,7,0,24; add 0,31,31; add 0,0,9; addi 11,29,52; lhax 3,11,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800F9668_0();
extern "C" void _s800F9668_1();
extern "C" void f_800F9668() {}
