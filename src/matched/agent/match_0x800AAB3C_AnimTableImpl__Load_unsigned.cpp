// 0x800AAB3C AnimTableImpl::Load(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-21508(13); mr 30,3; mr 31,5; lwz 9,0x0(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,0x8(3); li 4,0; lwz 3,0x4(9); cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; rlwinm 4,4,3,0,28; mr 5,31; add 4,3,4; bl _s800AAB3C_0; mr. 3,3; bne 1f; li 3,-1; b 2f; 1:; stw 3,0x4(30); li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800AAB3C_0();
extern "C" void f_800AAB3C() {}
