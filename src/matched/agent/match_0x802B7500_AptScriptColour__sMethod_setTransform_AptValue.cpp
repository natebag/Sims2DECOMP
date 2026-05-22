// 0x802B7500 AptScriptColour::sMethod_setTransform(AptValue (752 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); cmpwi 4,0; ble 8f; lis 9,-32694; lwz 30,0x24(3); lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; lwz 9,0x0(30); add 11,11,0; lwz 3,-4(11); andis. 0,9,2048; beq 8f; lwz 9,0x0(3); andis. 0,9,2048; beq 8f; rlwinm 0,9,0,25,31; li 11,0; cmpwi 0,27; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 8f; lis 9,-32694; addi 31,3,12; addi 29,9,-11332; mr 3,31; addi 4,29,488; bl _s802B7500_0; mr. 3,3; beq 1f; bl _s802B7500_1; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de0(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x2c(30); 1:; mr 3,31; addi 4,29,496; bl _s802B7500_2; mr. 3,3; beq 2f; bl _s802B7500_3; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de4(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x3c(30); 2:; mr 3,31; addi 4,29,232; bl _s802B7500_4; mr. 3,3; beq 3f; bl _s802B7500_5; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de0(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x30(30); 3:; mr 3,31; addi 4,29,236; bl _s802B7500_6; mr. 3,3; beq 4f; bl _s802B7500_7; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de4(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x40(30); 4:; mr 3,31; addi 4,29,148; bl _s802B7500_8; mr. 3,3; beq 5f; bl _s802B7500_9; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de0(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x34(30); 5:; mr 3,31; addi 4,29,152; bl _s802B7500_10; mr. 3,3; beq 6f; bl _s802B7500_11; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de4(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x44(30); 6:; mr 3,31; addi 4,29,116; bl _s802B7500_12; mr. 3,3; beq 7f; bl _s802B7500_13; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de0(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x28(30); 7:; mr 3,31; addi 4,29,120; bl _s802B7500_14; mr. 3,3; beq 8f; bl _s802B7500_15; xoris 3,3,32768; stw 3,0x14(1); lis 0,17200; lis 11,-32703; lis 10,-32703; stw 0,0x10(1); lfd f13,0x5dd8(11); lfd f0,0x10(1); lfs f12,0x5de4(10); fsub f0,f0,f13; frsp f0,f0; fmuls f0,f0,f12; stfs f0,0x38(30); 8:; lwz 3,-22936(13); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s802B7500_0();
extern "C" void _s802B7500_1();
extern "C" void _s802B7500_2();
extern "C" void _s802B7500_3();
extern "C" void _s802B7500_4();
extern "C" void _s802B7500_5();
extern "C" void _s802B7500_6();
extern "C" void _s802B7500_7();
extern "C" void _s802B7500_8();
extern "C" void _s802B7500_9();
extern "C" void _s802B7500_10();
extern "C" void _s802B7500_11();
extern "C" void _s802B7500_12();
extern "C" void _s802B7500_13();
extern "C" void _s802B7500_14();
extern "C" void _s802B7500_15();
extern "C" void f_802B7500() {}
