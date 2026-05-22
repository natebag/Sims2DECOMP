// 0x8038B360 GXTokenInterruptHandler (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-736(1); stw 31,0x2dc(1); stw 30,0x2d8(1); mr 30,4; lwz 0,-21928(13); lwz 3,-21992(13); cmplwi 0,0; lhz 31,0xe(3); beq 0f; addi 3,1,16; bl _s8038B360_0; addi 3,1,16; bl _s8038B360_1; lwz 12,-21928(13); addi 3,31,0; mtspr 8,12; blrl; addi 3,1,16; bl _s8038B360_2; mr 3,30; bl _s8038B360_3; 0:; lwz 3,-21992(13); li 0,1; lhz 4,0xa(3); rlwimi 4,0,2,29,29; sth 4,0xa(3); lwz 0,0x2e4(1); lwz 31,0x2dc(1); lwz 30,0x2d8(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s8038B360_0();
extern "C" void _s8038B360_1();
extern "C" void _s8038B360_2();
extern "C" void _s8038B360_3();
extern "C" void f_8038B360() {}
