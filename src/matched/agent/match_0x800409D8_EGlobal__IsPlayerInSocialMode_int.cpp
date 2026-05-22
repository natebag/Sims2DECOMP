// 0x800409D8 EGlobal::IsPlayerInSocialMode(int) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s800409D8_0; mr. 11,3; beq 0f; lwz 9,0x4(11); lha 3,0x330(9); lwz 0,0x334(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800409D8_0();
extern "C" void f_800409D8() {}
