// 0x80013BA4 AwarenessManager::StartPassiveInfluenceAnimation(AnimRef (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 29,4; lwz 0,0x0(31); li 27,0; andi. 9,0,256; bne 3f; lwz 3,0x8(31); li 4,512; bl _s80013BA4_0; cmpwi 3,0; bne 3f; cmpwi 29,0; beq 3f; lis 28,-32693; lwz 4,0x0(29); addi 3,28,11064; bl _s80013BA4_1; cmpwi 3,0; beq 1f; lis 9,-32707; lwz 3,0x8(31); lfs f1,-8948(9); li 4,512; lwz 5,0x0(29); li 6,-1; li 7,0; bl _s80013BA4_2; lwz 0,0x0(31); mr 30,3; andi. 9,0,64; beq 0f; lwz 4,0x0(29); addi 3,28,11064; li 5,1; bl _s80013BA4_3; 0:; stb 27,0xd(30); lis 9,-32707; lfs f1,-8944(9); li 5,1; lwz 3,0x8(31); mr 4,30; li 27,1; bl _s80013BA4_4; lis 9,-32707; lis 11,-32707; lfs f1,-8940(9); mr 4,30; lfs f2,-32300(13); lfs f3,-8936(11); lwz 3,0x8(31); bl _s80013BA4_5; lwz 3,0x8(31); lis 5,-32688; mr 4,30; addi 5,5,-20000; bl _s80013BA4_6; lwz 0,0x0(31); lis 9,-32707; lfs f0,-8932(9); rlwinm 0,0,0,26,24; ori 0,0,256; stfs f0,0x3c(31); b 2f; 1:; lwz 0,0x0(31); andi. 9,0,64; bne 3f; lwz 4,0x0(29); addi 3,28,11064; bl _s80013BA4_7; lwz 0,0x0(31); ori 0,0,64; 2:; stw 0,0x0(31); 3:; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80013BA4_0();
extern "C" void _s80013BA4_1();
extern "C" void _s80013BA4_2();
extern "C" void _s80013BA4_3();
extern "C" void _s80013BA4_4();
extern "C" void _s80013BA4_5();
extern "C" void _s80013BA4_6();
extern "C" void _s80013BA4_7();
extern "C" void f_80013BA4() {}
