// 0x8007A380 RainEffect::UpdateParticleRainSplashLoad(void) (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); mr 28,3; lwz 29,0xc(28); cmpwi 29,0; bne 2f; lwz 0,0x34(28); lis 9,-32702; addi 9,9,15940; lis 3,-32692; rlwinm 0,0,2,0,29; addi 3,3,6092; lwzx 4,9,0; bl _s8007A380_0; cmpwi 3,0; stw 3,0xc(28); li 3,0; beq 3f; addi 3,1,16; bl _s8007A380_1; lwz 9,0xc(28); li 3,196; lwz 30,0x14(9); bl _s8007A380_2; mr 31,3; bl _s8007A380_3; lis 9,-32698; lis 4,-32707; addi 9,9,-21528; addi 4,4,26288; stw 9,0x0(31); mr 6,30; mr 3,31; li 5,0; bl _s8007A380_4; cmpwi 3,-1; bne 1f; cmpwi 31,0; beq 0f; lwz 9,0x0(31); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 0:; stw 29,0x10(28); b 2f; 1:; lwz 4,-22704(13); mr 3,31; li 5,0; bl _s8007A380_5; li 5,1; mr 3,31; lis 4,1024; bl _s8007A380_6; stw 31,0x10(28); addi 4,1,16; mr 3,31; bl _s8007A380_7; mr 3,31; bl _s8007A380_8; mr 29,3; li 0,-1; lwz 9,0x88(29); li 30,0; ori 30,30,65535; li 4,0; lfs f0,0xc8(9); li 5,0; lis 6,-32760; lis 7,-32760; stfs f0,0x2c(28); li 8,0; li 9,0; li 10,0; lwz 11,0x88(29); mr 3,31; addi 6,6,-24500; addi 7,7,-24692; stw 0,0x100(11); ori 4,4,65535; ori 5,5,65535; ori 8,8,65535; lwz 11,0x88(29); ori 9,9,65535; ori 10,10,65535; lfs f0,0xfc(11); stw 30,0xc(1); stfs f0,0x28(28); stw 30,0x8(1); bl _s8007A380_9; 2:; li 3,1; 3:; lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s8007A380_0();
extern "C" void _s8007A380_1();
extern "C" void _s8007A380_2();
extern "C" void _s8007A380_3();
extern "C" void _s8007A380_4();
extern "C" void _s8007A380_5();
extern "C" void _s8007A380_6();
extern "C" void _s8007A380_7();
extern "C" void _s8007A380_8();
extern "C" void _s8007A380_9();
extern "C" void f_8007A380() {}
