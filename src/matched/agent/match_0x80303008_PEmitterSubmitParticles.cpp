// 0x80303008 PEmitterSubmitParticles (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f30,0x18(1); stfd f31,0x20(1); stw 31,0x14(1); stw 0,0x2c(1); lwz 0,0x50(3); fmr f30,f1; stw 3,0x8(1); andi. 9,0,1; bne 0f; fmr f31,f30; b 1f; 0:; lis 9,-32702; lfs f31,-1952(9); 1:; lwz 9,0x8(1); lwz 0,0x94(9); lwz 31,0xb8(9); cmpwi 0,0; beq 2f; lwz 3,0xa0(9); mtspr 8,0; blrl; 2:; lwz 3,0x8(1); lwz 9,0x88(3); lwz 0,0x108(9); andis. 9,0,8; beq 3f; fmr f1,f31; bl _s80303008_0; b 7f; 3:; andis. 9,0,16; beq 4f; fmr f1,f30; bl _s80303008_1; b 7f; 4:; andis. 9,0,32; bne 5f; andis. 9,0,512; beq 6f; 5:; fmr f1,f31; bl _s80303008_2; b 7f; 6:; fmr f1,f31; bl _s80303008_3; 7:; lwz 9,0x8(1); lwz 0,0x98(9); cmpwi 0,0; beq 8f; lwz 3,0xa0(9); mtspr 8,0; blrl; 8:; lwz 11,0x8(1); lwz 0,0x50(11); andi. 9,0,16384; beq 10f; lwz 9,0x54(11); lwz 0,0x84(9); cmpwi 0,0; bne 10f; lwz 9,0x7c(11); addi 9,9,-1; cmpwi 9,0; stw 9,0x7c(11); bgt 10f; lwz 0,0xa4(11); cmpwi 0,0; beq 9f; lwz 3,0xa8(11); mtspr 8,0; blrl; 9:; lwz 4,0x8(1); mr 3,31; bl _s80303008_4; addi 3,1,8; bl _s80303008_5; 10:; lwz 0,0x2c(1); mtspr 8,0; lwz 31,0x14(1); lfd f30,0x18(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s80303008_0();
extern "C" void _s80303008_1();
extern "C" void _s80303008_2();
extern "C" void _s80303008_3();
extern "C" void _s80303008_4();
extern "C" void _s80303008_5();
extern "C" void f_80303008() {}
