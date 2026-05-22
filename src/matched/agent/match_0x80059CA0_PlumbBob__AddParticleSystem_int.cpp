// 0x80059CA0 PlumbBob::AddParticleSystem(int) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; lwz 0,0x1f4(31); addi 26,31,492; rlwinm 0,0,2,0,29; lwzx 9,26,0; cmpwi 9,0; bne 0f; lis 3,-32692; li 5,0; li 6,0; addi 3,3,6092; bl _s80059CA0_0; lwz 30,0x1f4(31); mr 27,3; lwz 28,0x14(27); li 3,196; rlwinm 30,30,2,0,29; bl _s80059CA0_1; mr 29,3; bl _s80059CA0_2; stwx 29,26,30; lis 9,-32698; addi 9,9,-21528; lis 4,-32707; lwz 0,0x1f4(31); mr 6,28; stw 9,0x0(29); addi 4,4,16876; rlwinm 0,0,2,0,29; li 5,0; lwzx 3,26,0; bl _s80059CA0_3; lwz 0,0x1f4(31); lis 4,-32717; addi 4,4,-18888; mr 5,27; rlwinm 0,0,2,0,29; lwzx 3,26,0; bl _s80059CA0_4; lwz 0,0x1f4(31); li 5,1; lwz 4,-22708(13); rlwinm 0,0,2,0,29; lwzx 3,26,0; bl _s80059CA0_5; lwz 9,0x1f4(31); addi 9,9,1; stw 9,0x1f4(31); 0:; mr 3,31; li 4,0; bl _s80059CA0_6; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80059CA0_0();
extern "C" void _s80059CA0_1();
extern "C" void _s80059CA0_2();
extern "C" void _s80059CA0_3();
extern "C" void _s80059CA0_4();
extern "C" void _s80059CA0_5();
extern "C" void _s80059CA0_6();
extern "C" void f_80059CA0() {}
