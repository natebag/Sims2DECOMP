// 0x80250BC8 __OSInitMemoryProtection (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-80(1); stmw 27,0x3c(1); lis 27,-32768; lwz 31,0xf0(27); bl _s80250BC8_0; lis 4,-13312; addi 28,4,16384; li 0,0; sth 0,0x20(28); li 0,255; mr 30,3; sth 0,0x10(28); lis 3,-4096; bl _s80250BC8_1; lis 3,-32731; addi 29,3,2432; mr 4,29; li 3,0; bl _s80250BC8_2; mr 4,29; li 3,1; bl _s80250BC8_3; mr 4,29; li 3,2; bl _s80250BC8_4; mr 4,29; li 3,3; bl _s80250BC8_5; mr 4,29; li 3,4; bl _s80250BC8_6; lis 3,-32700; addi 3,3,-18568; bl _s80250BC8_7; lwz 3,0xf0(27); lwz 0,0x28(27); cmplw 3,0; bge 0f; addis 0,3,-384; cmplwi 0,0; bne 0f; lis 3,-32384; lis 4,384; bl _s80250BC8_8; li 0,2; sth 0,0x28(28); 0:; lis 0,384; cmplw 31,0; bgt 1f; lis 3,-32731; addi 3,3,2736; bl _s80250BC8_9; b 2f; 1:; lis 0,768; cmplw 31,0; bgt 2f; lis 3,-32731; addi 3,3,2864; bl _s80250BC8_10; 2:; lis 3,2048; bl _s80250BC8_11; mr 3,30; bl _s80250BC8_12; lmw 27,0x3c(1); lwz 0,0x54(1); addi 1,1,80; mtspr 8,0"
extern "C" void _s80250BC8_0();
extern "C" void _s80250BC8_1();
extern "C" void _s80250BC8_2();
extern "C" void _s80250BC8_3();
extern "C" void _s80250BC8_4();
extern "C" void _s80250BC8_5();
extern "C" void _s80250BC8_6();
extern "C" void _s80250BC8_7();
extern "C" void _s80250BC8_8();
extern "C" void _s80250BC8_9();
extern "C" void _s80250BC8_10();
extern "C" void _s80250BC8_11();
extern "C" void _s80250BC8_12();
extern "C" void f_80250BC8() {}
