// 0x8039B7B0 __VMBASESetupExceptionHandlers (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; lis 3,-32710; lis 5,-32768; stw 0,0x14(1); addi 3,3,-18132; addis 6,3,-32768; li 4,4; stw 31,0xc(1); addi 6,6,-768; oris 0,6,18432; addi 3,5,768; stw 30,0x8(1); lwz 30,0x300(5); stw 0,0x300(5); bl _s8039B7B0_0; sync; lis 3,-32768; addi 3,3,768; li 0,0; isync; icbi 3,0; lis 3,-32710; li 4,4; addi 31,3,-17896; stw 30,0x0(31); mr 3,31; bl _s8039B7B0_1; sync; li 0,0; isync; icbi 31,0; lis 3,-32710; li 4,4; addi 31,3,-17892; addis 5,31,-32768; addi 5,5,-772; mr 3,31; neg 0,5; rlwinm 0,0,0,6,31; oris 0,0,18432; stw 0,0x0(31); bl _s8039B7B0_2; sync; li 0,0; isync; icbi 31,0; lis 3,-32710; lis 5,-32768; addi 3,3,-17708; lwz 30,0x400(5); addis 6,3,-32768; li 4,4; addi 6,6,-1024; addi 3,5,1024; oris 0,6,18432; stw 0,0x400(5); bl _s8039B7B0_3; sync; lis 3,-32768; addi 3,3,1024; li 0,0; isync; icbi 3,0; lis 3,-32710; li 4,4; addi 31,3,-17472; stw 30,0x0(31); mr 3,31; bl _s8039B7B0_4; sync; li 0,0; isync; icbi 31,0; lis 3,-32710; li 4,4; addi 31,3,-17468; addis 5,31,-32768; addi 5,5,-1028; mr 3,31; neg 0,5; rlwinm 0,0,0,6,31; oris 0,0,18432; stw 0,0x0(31); bl _s8039B7B0_5; sync; li 0,0; isync; icbi 31,0; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B7B0_0();
extern "C" void _s8039B7B0_1();
extern "C" void _s8039B7B0_2();
extern "C" void _s8039B7B0_3();
extern "C" void _s8039B7B0_4();
extern "C" void _s8039B7B0_5();
extern "C" void f_8039B7B0() {}
