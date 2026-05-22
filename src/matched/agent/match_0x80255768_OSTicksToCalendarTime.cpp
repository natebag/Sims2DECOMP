// 0x80255768 OSTicksToCalendarTime (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 25,0x1c(1); mr 29,3; mr 30,4; mr 31,5; lis 27,-32768; lwz 0,0xf8(27); mr 3,29; mr 4,30; rlwinm 6,0,30,2,31; li 5,0; bl _s80255768_0; mr 26,3; li 5,0; mr 25,4; xoris 4,26,32768; xoris 3,5,32768; subfc 0,5,25; subfe 3,3,4; subfe 3,4,4; neg 3,3; cmpwi 3,0; beq 0f; lwz 0,0xf8(27); rlwinm 0,0,30,2,31; addc 25,25,0; adde 26,26,5; 0:; li 4,8; mullw 3,26,4; mulhwu 0,25,4; lis 27,-32768; lwz 6,0xf8(27); lis 5,17180; addi 5,5,-8573; rlwinm 6,6,30,2,31; mulhwu 5,5,6; rlwinm 6,5,17,15,31; li 28,0; add 3,3,0; mullw 0,25,28; mullw 4,25,4; add 3,3,0; li 5,0; bl _s80255768_1; li 5,0; li 6,1000; bl _s80255768_2; stw 4,0x24(31); lis 3,4194; addi 5,3,19923; lwz 0,0xf8(27); mr 3,26; mr 4,25; rlwinm 0,0,30,2,31; mulhwu 0,5,0; rlwinm 6,0,26,6,31; li 5,0; bl _s80255768_3; li 5,0; li 6,1000; bl _s80255768_4; stw 4,0x20(31); subfc 30,25,30; subfe 29,26,29; lwz 0,0xf8(27); lis 5,1; addi 25,5,20864; mr 3,29; rlwinm 6,0,30,2,31; mr 4,30; li 5,0; bl _s80255768_5; mr 6,25; li 5,0; bl _s80255768_6; lis 5,11; lwz 0,0xf8(27); addi 5,5,9589; addc 26,4,5; rlwinm 6,0,30,2,31; adde 0,3,28; mr 3,29; mr 4,30; li 5,0; bl _s80255768_7; mr 6,25; li 5,0; bl _s80255768_8; mr 27,4; cmpwi 27,0; bge 1f; addis 27,27,1; addi 26,26,-1; addi 27,27,20864; 1:; mr 3,26; mr 4,31; bl _s80255768_9; lis 3,-30583; addi 5,3,-30583; mulhw 0,5,27; add 4,0,27; srawi 0,4,5; rlwinm 3,0,1,31,31; add 7,0,3; mulhw 0,5,7; add 0,0,7; srawi 5,0,5; srawi 0,0,5; rlwinm 3,0,1,31,31; add 3,0,3; srawi 0,4,5; rlwinm 6,5,1,31,31; mulli 4,3,60; rlwinm 3,0,1,31,31; add 5,5,6; add 0,0,3; stw 5,0x8(31); mulli 0,0,60; subf 3,4,7; stw 3,0x4(31); subf 0,0,27; stw 0,0x0(31); lmw 25,0x1c(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s80255768_0();
extern "C" void _s80255768_1();
extern "C" void _s80255768_2();
extern "C" void _s80255768_3();
extern "C" void _s80255768_4();
extern "C" void _s80255768_5();
extern "C" void _s80255768_6();
extern "C" void _s80255768_7();
extern "C" void _s80255768_8();
extern "C" void _s80255768_9();
extern "C" void f_80255768() {}
