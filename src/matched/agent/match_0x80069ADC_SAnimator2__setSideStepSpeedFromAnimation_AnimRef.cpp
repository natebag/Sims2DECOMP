// 0x80069ADC SAnimator2::setSideStepSpeedFromAnimation(AnimRef (564 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-272(1); mfspr 0,8; stfd f29,0xf8(1); stfd f30,0x100(1); stfd f31,0x108(1); stmw 26,0xe0(1); stw 0,0x114(1); mr 31,3; mr 30,4; addi 3,1,24; mr 26,3; bl _s80069ADC_0; lwz 0,0x3c(31); andi. 29,0,16; bne 7f; lis 9,-32693; lwz 4,0x0(30); addi 28,9,11064; li 5,0; mr 3,28; li 6,0; bl _s80069ADC_1; mr. 30,3; beq 7f; lwz 11,0x18(30); lis 27,17200; lis 9,-32707; addi 11,11,-1; lfd f30,0x4c70(9); xoris 11,11,32768; lfs f11,0x64(30); stw 11,0xdc(1); lis 9,-32707; lfs f12,0x4c78(9); lis 11,-32707; stw 27,0xd8(1); lis 9,-32707; lfs f29,0x4c7c(11); lfd f0,0xd8(1); lfs f13,0x4c68(9); fsub f0,f0,f30; frsp f0,f0; fdivs f0,f0,f11; fmuls f31,f0,f12; fmuls f31,f31,f29; fcmpu 0,f31,f13; beq 5f; lwz 3,0x94(1); cmpwi 3,0; beq 0f; bl _s80069ADC_2; stw 29,0x94(1); 0:; lwz 3,0x8(31); mr 4,26; stw 30,0x94(1); addi 3,3,820; bl _s80069ADC_3; lwz 9,0x34(30); lwz 10,0xb0(1); lwz 11,0x30(9); addi 10,10,32; cmpwi 11,0; beq 3f; ble 1f; lwz 9,0x44(30); rlwinm 11,11,2,0,29; addi 8,1,8; lwzx 10,9,11; add 9,9,11; lwz 0,0x8(9); lwz 11,0x4(9); stw 10,0x8(1); stw 0,0x8(8); stw 11,0x4(8); b 2f; 1:; lwz 9,0x18(30); addi 30,1,200; lwz 4,0x4(10); addi 9,9,-1; mr 3,30; xoris 9,9,32768; stw 9,0xdc(1); stw 27,0xd8(1); lfd f1,0xd8(1); fsub f1,f1,f30; frsp f1,f1; fmuls f1,f1,f29; bl _s80069ADC_4; lwz 10,0xc8(1); addi 11,1,8; lwz 0,0x8(30); lwz 9,0x4(30); stw 10,0x8(1); stw 0,0x8(11); stw 9,0x4(11); 2:; lfs f0,0xc(1); lis 9,-32707; lfs f13,0x4c80(9); fabs f12,f0; fcmpu 0,f12,f13; ble 3f; lis 9,-32707; lfs f0,0x4c84(9); fmuls f12,f12,f0; fdivs f13,f12,f31; stfs f13,0xa4(31); 3:; lwz 3,0x8(31); mr 4,26; li 30,0; addi 3,3,820; bl _s80069ADC_5; lwz 3,0x94(1); cmpwi 3,0; beq 4f; bl _s80069ADC_6; stw 30,0x94(1); 4:; stw 30,0x94(1); b 6f; 5:; mr 3,28; mr 4,30; li 5,1; bl _s80069ADC_7; 6:; lwz 0,0x3c(31); ori 0,0,16; stw 0,0x3c(31); 7:; addi 3,1,164; bl _s80069ADC_8; lwz 3,0x94(1); cmpwi 3,0; beq 8f; bl _s80069ADC_9; li 0,0; stw 0,0x94(1); 8:; lwz 0,0x114(1); mtspr 8,0; lmw 26,0xe0(1); lfd f29,0xf8(1); lfd f30,0x100(1); lfd f31,0x108(1); addi 1,1,272"
extern "C" void _s80069ADC_0();
extern "C" void _s80069ADC_1();
extern "C" void _s80069ADC_2();
extern "C" void _s80069ADC_3();
extern "C" void _s80069ADC_4();
extern "C" void _s80069ADC_5();
extern "C" void _s80069ADC_6();
extern "C" void _s80069ADC_7();
extern "C" void _s80069ADC_8();
extern "C" void _s80069ADC_9();
extern "C" void f_80069ADC() {}
