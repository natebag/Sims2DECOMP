// 0x800695B8 SAnimator2::determineWalkRunStyle(float) (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; bl _s800695B8_0; mr 3,31; bl _s800695B8_1; mr 3,31; bl _s800695B8_2; lbz 0,0x5f9(31); cmpwi 0,0; beq 3f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x1f0(9); lwz 9,0x1f4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 3f; lbz 0,0x5f9(31); cmpwi 0,5; beq 0f; cmpwi 0,9; beq 1f; b 2f; 0:; li 3,2; b 4f; 1:; li 3,3; b 4f; 2:; li 3,0; b 4f; 3:; lwz 11,0x4(31); li 4,17; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x260(9); lwz 0,0x264(9); add 3,10,3; mtspr 8,0; blrl; 4:; cmpwi 3,0; bne 6f; lwz 0,0x18(31); cmpwi 0,2; bne 5f; li 3,4; b 6f; 5:; fmr f1,f31; mr 3,31; bl _s800695B8_3; 6:; lwz 0,0x108(31); cmpw 3,0; beq 7f; stw 3,0x108(31); stw 0,0x10c(31); 7:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s800695B8_0();
extern "C" void _s800695B8_1();
extern "C" void _s800695B8_2();
extern "C" void _s800695B8_3();
extern "C" void f_800695B8() {}
