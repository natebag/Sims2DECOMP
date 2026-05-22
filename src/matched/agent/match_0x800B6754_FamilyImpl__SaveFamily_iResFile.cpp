// 0x800B6754 FamilyImpl::SaveFamily(iResFile (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x8(31); cmpwi 0,-1; beq 0f; lwz 9,0x0(31); lha 4,0xa(31); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,31,3; blrl; mr 6,3; lis 5,17985; mr 3,31; mr 4,30; ori 5,5,19785; li 7,18; bl _s800B6754_0; subfic 0,3,0; adde 3,0,3; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B6754_0();
extern "C" void f_800B6754() {}
