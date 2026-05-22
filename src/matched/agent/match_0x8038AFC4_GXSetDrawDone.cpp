// 0x8038AFC4 GXSetDrawDone (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); bl _s8038AFC4_0; li 0,97; lwz 4,-17720(13); lis 6,-13311; lis 5,17664; stb 0,-32768(6); addi 0,5,2; stw 0,-32768(6); mr 30,3; lwz 0,0x5ac(4); cmplwi 0,0; beq 0f; bl _s8038AFC4_1; 0:; li 31,0; lis 3,-13311; stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); bl _s8038AFC4_2; stb 31,-21920(13); mr 3,30; bl _s8038AFC4_3; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038AFC4_0();
extern "C" void _s8038AFC4_1();
extern "C" void _s8038AFC4_2();
extern "C" void _s8038AFC4_3();
extern "C" void f_8038AFC4() {}
