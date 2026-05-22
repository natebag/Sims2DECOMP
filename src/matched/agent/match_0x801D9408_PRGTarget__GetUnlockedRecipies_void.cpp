// 0x801D9408 PRGTarget::GetUnlockedRecipies(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-21476(13); li 4,1; lwz 9,0x0(11); lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); lha 0,0x148(9); lwz 9,0x14c(9); add 3,3,0; mtspr 8,9; blrl; lwz 9,0x0(3); li 4,0; lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_801D9408() {}
