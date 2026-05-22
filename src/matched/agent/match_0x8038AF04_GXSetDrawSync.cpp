// 0x8038AF04 GXSetDrawSync (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s8038AF04_0; li 6,97; lwz 4,-17720(13); lis 5,-13311; rlwinm 0,30,0,16,31; stb 6,-32768(5); oris 7,0,18432; stw 7,-32768(5); rlwimi 7,30,0,16,31; li 0,71; stb 6,-32768(5); rlwimi 7,0,24,0,7; mr 30,3; stw 7,-32768(5); lwz 0,0x5ac(4); cmplwi 0,0; beq 0f; bl _s8038AF04_1; 0:; li 31,0; lis 3,-13311; stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); stw 31,-32768(3); bl _s8038AF04_2; mr 3,30; bl _s8038AF04_3; lwz 3,-17720(13); sth 31,0x2(3); lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038AF04_0();
extern "C" void _s8038AF04_1();
extern "C" void _s8038AF04_2();
extern "C" void _s8038AF04_3();
extern "C" void f_8038AF04() {}
