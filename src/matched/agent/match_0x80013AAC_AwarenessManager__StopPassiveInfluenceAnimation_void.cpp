// 0x80013AAC AwarenessManager::StopPassiveInfluenceAnimation(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 0,0x0(30); andi. 9,0,64; beq 1f; lwz 31,0x40(30); rlwinm 0,0,0,26,24; stw 0,0x0(30); cmpwi 31,0; beq 1f; lis 29,-32693; lwz 4,0x0(31); addi 3,29,11064; bl _s80013AAC_0; cmpwi 3,0; beq 0f; lwz 4,0x0(31); addi 3,29,11064; li 5,1; bl _s80013AAC_1; b 1f; 0:; lwz 4,0x0(31); addi 3,29,11064; bl _s80013AAC_2; 1:; lwz 0,0x0(30); andi. 9,0,256; beq 2f; lwz 3,0x8(30); li 4,512; bl _s80013AAC_3; cmpwi 3,0; beq 2f; lis 9,-32707; lis 11,-32707; lfs f1,-8956(9); li 4,512; lfs f3,-8952(11); lwz 3,0x8(30); lfs f2,-32300(13); bl _s80013AAC_4; 2:; lwz 0,0x0(30); li 10,0; stw 10,0x40(30); rlwinm 11,0,0,24,22; andi. 9,0,128; stw 11,0x0(30); beq 3f; lis 9,-32707; ori 0,11,8; lfs f0,-8956(9); rlwinm 0,0,0,25,23; stw 0,0x0(30); stw 10,0x1c(30); stfs f0,0x20(30); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80013AAC_0();
extern "C" void _s80013AAC_1();
extern "C" void _s80013AAC_2();
extern "C" void _s80013AAC_3();
extern "C" void _s80013AAC_4();
extern "C" void f_80013AAC() {}
