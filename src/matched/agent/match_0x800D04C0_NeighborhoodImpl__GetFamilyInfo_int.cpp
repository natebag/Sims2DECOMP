// 0x800D04C0 NeighborhoodImpl::GetFamilyInfo(int, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; lwz 9,0x0(31); lha 3,0x120(9); lwz 0,0x124(9); add 3,31,3; mtspr 8,0; blrl; mr. 4,3; li 3,0; beq 0f; mr 3,31; mr 5,30; li 6,1; bl _s800D04C0_0; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800D04C0_0();
extern "C" void f_800D04C0() {}
