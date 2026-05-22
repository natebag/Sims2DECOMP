// 0x803068DC Pause(float) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stw 31,0x1c(1); stw 0,0x2c(1); lwz 11,-26532(13); addi 4,1,8; mr 31,4; fmr f31,f1; lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 3,-26532(13); mr 4,31; lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; fcmpu 0,f1,f31; blt 0b; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x1c(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void f_803068DC() {}
