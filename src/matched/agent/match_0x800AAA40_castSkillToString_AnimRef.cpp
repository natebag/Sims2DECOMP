// 0x800AAA40 castSkillToString(AnimRef (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; mr. 4,3; beq 0f; lwz 3,-21432(13); bl _s800AAA40_0; mr 0,3; 0:; mr. 3,0; bne 1f; lis 9,-32706; addi 3,9,-28064; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800AAA40_0();
extern "C" void f_800AAA40() {}
