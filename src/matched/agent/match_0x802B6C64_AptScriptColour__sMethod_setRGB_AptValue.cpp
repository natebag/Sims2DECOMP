// 0x802B6C64 AptScriptColour::sMethod_setRGB(AptValue (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f30,0x28(1); stfd f31,0x30(1); stmw 30,0x20(1); stw 0,0x3c(1); lis 9,-32694; lwz 31,0x24(3); lwz 11,-16032(9); addi 9,9,-16032; cmpwi 31,0; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); beq 0f; bl _s802B6C64_0; mr 9,3; rlwinm 0,9,16,24,31; lis 30,17200; xoris 0,0,32768; rlwinm 11,9,24,24,31; stw 0,0x1c(1); mr 8,10; xoris 11,11,32768; rlwinm 9,9,0,24,31; stw 30,0x18(1); mr 7,10; xoris 9,9,32768; lis 6,-32703; lfd f1,0x18(1); mr 3,31; stw 11,0x1c(1); li 4,8; lfd f0,0x5dc0(6); li 5,0; stw 30,0x18(1); fsub f1,f1,f0; lfd f30,0x18(1); frsp f1,f1; stw 9,0x1c(1); fsub f30,f30,f0; stw 30,0x18(1); frsp f30,f30; lfd f31,0x18(1); fsub f31,f31,f0; frsp f31,f31; bl _s802B6C64_1; fmr f1,f30; mr 3,31; li 4,9; li 5,0; bl _s802B6C64_2; fmr f1,f31; mr 3,31; li 4,10; li 5,0; bl _s802B6C64_3; lwz 0,0x5c(31); lis 9,-32703; lfs f0,0x5dc8(9); ori 0,0,32768; stw 0,0x5c(31); stfs f0,0x34(31); stfs f0,0x2c(31); stfs f0,0x30(31); 0:; lwz 3,-22936(13); lwz 0,0x3c(1); mtspr 8,0; lmw 30,0x20(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s802B6C64_0();
extern "C" void _s802B6C64_1();
extern "C" void _s802B6C64_2();
extern "C" void _s802B6C64_3();
extern "C" void f_802B6C64() {}
