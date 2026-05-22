// 0x8038B4AC __GXPEInit (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32711; stw 0,0x4(1); addi 4,3,-19616; li 3,18; stwu 1,-8(1); bl _s8038B4AC_0; lis 3,-32711; addi 4,3,-19412; li 3,19; bl _s8038B4AC_1; addi 3,13,-21916; bl _s8038B4AC_2; li 3,8192; bl _s8038B4AC_3; li 3,4096; bl _s8038B4AC_4; lwz 3,-21992(13); li 0,1; lhz 4,0xa(3); rlwimi 4,0,2,29,29; rlwimi 4,0,3,28,28; rlwimi 4,0,0,31,31; rlwimi 4,0,1,30,30; sth 4,0xa(3); lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8038B4AC_0();
extern "C" void _s8038B4AC_1();
extern "C" void _s8038B4AC_2();
extern "C" void _s8038B4AC_3();
extern "C" void _s8038B4AC_4();
extern "C" void f_8038B4AC() {}
