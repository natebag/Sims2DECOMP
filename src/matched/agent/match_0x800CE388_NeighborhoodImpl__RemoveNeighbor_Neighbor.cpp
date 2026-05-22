// 0x800CE388 NeighborhoodImpl::RemoveNeighbor(Neighbor (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; lha 30,0x4(31); li 3,246; mr 4,30; bl _s800CE388_0; lwz 9,0x74(29); addi 30,30,-1; rlwinm 30,30,2,0,29; li 0,0; stwx 0,9,30; mr 4,31; lwz 9,0x0(29); lha 3,0x100(9); lwz 0,0x104(9); add 3,29,3; mtspr 8,0; blrl; cmpwi 31,0; beq 0f; mr 3,31; li 4,3; bl _s800CE388_1; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800CE388_0();
extern "C" void _s800CE388_1();
extern "C" void f_800CE388() {}
