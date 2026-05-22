// 0x80388580 GXCPInterruptHandler (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-736(1); stw 31,0x2dc(1); mr 31,4; lwz 5,-21996(13); lwz 3,-17720(13); lhz 0,0x0(5); stw 0,0xc(3); lwz 0,0x8(3); rlwinm. 0,0,29,31,31; beq 0f; lwz 0,0xc(3); rlwinm. 0,0,31,31,31; beq 0f; lwz 3,-21952(13); bl _s80388580_0; li 0,0; stw 0,-21944(13); li 3,1; li 4,1; bl _s80388580_1; li 3,1; li 4,0; bl _s80388580_2; 0:; lwz 3,-17720(13); lwz 0,0x8(3); rlwinm. 0,0,30,31,31; beq 1f; lwz 0,0xc(3); rlwinm. 0,0,0,31,31; beq 1f; lwz 5,-21936(13); li 3,0; li 4,1; addi 0,5,1; stw 0,-21936(13); bl _s80388580_3; li 3,1; li 4,0; bl _s80388580_4; li 0,1; lwz 3,-21952(13); stw 0,-21944(13); bl _s80388580_5; 1:; lwz 3,-17720(13); lwz 4,0x8(3); rlwinm. 0,4,27,31,31; beq 2f; lwz 0,0xc(3); rlwinm. 0,0,28,31,31; beq 2f; li 0,0; rlwimi 4,0,5,26,26; stw 4,0x8(3); lwz 0,0x8(3); lwz 3,-21996(13); sth 0,0x2(3); lwz 0,-21940(13); cmplwi 0,0; beq 2f; addi 3,1,16; bl _s80388580_6; addi 3,1,16; bl _s80388580_7; lwz 12,-21940(13); mtspr 8,12; blrl; addi 3,1,16; bl _s80388580_8; mr 3,31; bl _s80388580_9; 2:; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s80388580_0();
extern "C" void _s80388580_1();
extern "C" void _s80388580_2();
extern "C" void _s80388580_3();
extern "C" void _s80388580_4();
extern "C" void _s80388580_5();
extern "C" void _s80388580_6();
extern "C" void _s80388580_7();
extern "C" void _s80388580_8();
extern "C" void _s80388580_9();
extern "C" void f_80388580() {}
