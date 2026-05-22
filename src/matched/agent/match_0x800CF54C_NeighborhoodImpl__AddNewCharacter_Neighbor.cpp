// 0x800CF54C NeighborhoodImpl::AddNewCharacter(Neighbor (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-21508(13); mr 30,3; mr 31,4; lwz 9,0x0(11); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,30; bl _s800CF54C_0; mr. 30,3; li 3,-1; beq 0f; mr 3,30; bl _s800CF54C_1; mr 3,30; bl _s800CF54C_2; stw 30,0x0(31); li 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800CF54C_0();
extern "C" void _s800CF54C_1();
extern "C" void _s800CF54C_2();
extern "C" void f_800CF54C() {}
