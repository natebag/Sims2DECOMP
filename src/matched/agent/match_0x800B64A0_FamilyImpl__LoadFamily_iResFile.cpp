// 0x800B64A0 FamilyImpl::LoadFamily(iResFile (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr. 5,5; bge 0f; li 0,-1; addi 3,31,4; stw 0,0x8(31); li 4,0; li 5,-1; bl _s800B64A0_0; li 3,0; b 1f; 0:; stw 5,0x8(31); li 0,0; lwz 9,0x0(31); extsh 4,5; stw 0,0x8(1); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,31,3; blrl; mr 5,3; mr 4,30; mr 3,31; addi 6,1,8; bl _s800B64A0_1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s800B64A0_0();
extern "C" void _s800B64A0_1();
extern "C" void f_800B64A0() {}
