// 0x80237F70 __static_initialization_and_destruction_0 (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32695; addi 3,3,-29844; bl _s80237F70_0; lfs f0,-28432(13); lis 5,-32695; addi 5,5,-29541; lis 3,-32695; fmuls f0,f0,f0; lis 4,-32704; addi 4,4,-2592; rlwinm 5,5,0,0,25; li 6,56; stfs f0,-23764(13); li 7,512; addi 3,3,-29652; bl _s80237F70_1; lis 3,-32688; lis 4,-32732; lis 5,-32732; lis 6,-32732; lis 8,-32704; lis 9,-32688; addi 3,3,-13080; addi 4,4,-32716; addi 5,5,-32672; addi 6,6,-32624; addi 8,8,-3084; addi 9,9,-13000; li 7,6; bl _s80237F70_2; stw 3,-23760(13); b 1f; 0:; lis 3,-32695; li 4,2; addi 3,3,-29652; bl _s80237F70_3; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80237F70_0();
extern "C" void _s80237F70_1();
extern "C" void _s80237F70_2();
extern "C" void _s80237F70_3();
extern "C" void f_80237F70() {}
