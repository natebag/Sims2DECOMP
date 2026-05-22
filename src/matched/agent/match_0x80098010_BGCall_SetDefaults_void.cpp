// 0x80098010 BGCall_SetDefaults(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-22756(13); li 0,0; lis 4,-32759; lwz 9,0x0(11); addi 4,4,32736; stw 0,-21480(13); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80098010() {}
