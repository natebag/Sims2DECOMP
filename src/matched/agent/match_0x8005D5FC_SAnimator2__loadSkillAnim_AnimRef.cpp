// 0x8005D5FC SAnimator2::loadSkillAnim(AnimRef (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr. 29,4; beq 0f; lwz 31,0x0(29); cmpwi 31,0; beq 0f; lis 28,-32693; mr 4,31; addi 3,28,11064; bl _s8005D5FC_0; cmpwi 3,0; bne 0f; lis 3,-32707; mr 4,31; addi 3,3,17844; crxor 6,6,6; bl _s8005D5FC_1; stw 31,0x28(30); mr 3,30; mr 4,29; bl _s8005D5FC_2; mr 4,31; addi 3,28,11064; bl _s8005D5FC_3; lwz 9,-32344(13); li 3,0; li 4,2; addi 9,9,1; stw 9,-32344(13); b 1f; 0:; li 3,0; li 4,1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8005D5FC_0();
extern "C" void _s8005D5FC_1();
extern "C" void _s8005D5FC_2();
extern "C" void _s8005D5FC_3();
extern "C" void f_8005D5FC() {}
