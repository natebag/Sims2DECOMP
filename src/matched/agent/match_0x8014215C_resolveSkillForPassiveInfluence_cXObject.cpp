// 0x8014215C resolveSkillForPassiveInfluence(cXObject (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); li 0,0; mr 29,6; stw 0,0x0(29); mr 30,5; mr 28,3; lbz 0,0x5(30); mr 3,4; lha 31,0x0(30); andi. 9,0,4; beq 0f; bl _s8014215C_0; add 0,31,31; lhax 31,3,0; 0:; lbz 0,0x4(30); extsb 0,0; cmpwi 0,1; beq 4f; bgt 1f; cmpwi 0,0; beq 2f; b 7f; 1:; cmpwi 0,2; beq 3f; cmpwi 0,3; beq 6f; b 7f; 2:; mr 3,28; mr 4,31; mr 5,29; bl _s8014215C_1; b 5f; 3:; mr 4,31; mr 5,29; li 3,0; bl _s8014215C_2; b 5f; 4:; mr 4,31; mr 5,29; li 3,0; bl _s8014215C_3; 5:; cmpwi 3,-1; bne 7f; cmpwi 4,-1; bne 7f; li 3,-1; li 4,-1; b 8f; 6:; mr 4,31; mr 5,29; li 3,0; bl _s8014215C_4; cmpwi 3,-1; bne 7f; cmpwi 4,-1; li 3,-1; li 4,-1; beq 8f; 7:; li 3,0; li 4,1; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8014215C_0();
extern "C" void _s8014215C_1();
extern "C" void _s8014215C_2();
extern "C" void _s8014215C_3();
extern "C" void _s8014215C_4();
extern "C" void f_8014215C() {}
