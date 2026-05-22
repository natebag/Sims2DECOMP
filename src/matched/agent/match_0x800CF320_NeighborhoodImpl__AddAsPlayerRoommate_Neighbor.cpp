// 0x800CF320 NeighborhoodImpl::AddAsPlayerRoommate(Neighbor (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0x0(31); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,31,3; mtspr 8,0; blrl; mr 29,3; mr 3,30; bl _s800CF320_0; cmpw 3,29; beq 0f; lwz 9,0x0(31); lwz 0,0x164(9); lha 3,0x160(9); mtspr 8,0; add 3,31,3; blrl; lha 0,0x6c(31); cmpwi 0,0; bne 0f; mr 3,30; bl _s800CF320_1; lwz 9,0x0(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; sth 3,0x6c(31); mr 4,30; lwz 9,0x0(31); lha 3,0x150(9); lwz 0,0x154(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 0f; lwz 9,0x0(31); mr 4,30; mr 5,29; lha 3,0x148(9); lwz 0,0x14c(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800CF320_0();
extern "C" void _s800CF320_1();
extern "C" void f_800CF320() {}
