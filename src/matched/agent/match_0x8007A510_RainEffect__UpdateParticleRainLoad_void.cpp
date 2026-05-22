// 0x8007A510 RainEffect::UpdateParticleRainLoad(void) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 29,3; lwz 28,0x0(29); cmpwi 28,0; beq 0f; li 3,1; b 3f; 0:; lwz 0,0x34(29); lis 9,-32702; addi 9,9,15928; lis 3,-32692; rlwinm 0,0,2,0,29; addi 3,3,6092; lwzx 4,9,0; bl _s8007A510_0; cmpwi 3,0; stw 3,0x0(29); li 3,0; beq 3f; lis 9,-32707; addi 3,1,8; lfs f1,0x66c4(9); bl _s8007A510_1; lwz 9,0x0(29); li 3,196; lwz 30,0x14(9); bl _s8007A510_2; mr 31,3; bl _s8007A510_3; lis 9,-32698; lis 4,-32707; addi 9,9,-21528; addi 4,4,26300; stw 9,0x0(31); mr 6,30; mr 3,31; li 5,0; bl _s8007A510_4; cmpwi 3,-1; bne 2f; cmpwi 31,0; beq 1f; lwz 9,0x0(31); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 1:; stw 28,0x4(29); li 3,1; b 3f; 2:; lwz 4,-22704(13); mr 3,31; li 5,0; bl _s8007A510_5; mr 3,31; lis 4,1024; li 5,1; bl _s8007A510_6; stw 31,0x4(29); mr 3,31; addi 4,1,8; bl _s8007A510_7; lis 9,-32707; lis 11,-32707; lfs f13,0x66c8(9); li 3,1; lfs f0,0x66cc(11); stfs f13,0x24(29); stfs f0,0x20(29); 3:; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"
extern "C" void _s8007A510_0();
extern "C" void _s8007A510_1();
extern "C" void _s8007A510_2();
extern "C" void _s8007A510_3();
extern "C" void _s8007A510_4();
extern "C" void _s8007A510_5();
extern "C" void _s8007A510_6();
extern "C" void _s8007A510_7();
extern "C" void f_8007A510() {}
