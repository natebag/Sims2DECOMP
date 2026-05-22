// 0x802B31F4 AptValueShutdownRemaining(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-22936(13); lwz 9,0x8(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-22916(13); lwz 9,0x8(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802B31F4() {}
