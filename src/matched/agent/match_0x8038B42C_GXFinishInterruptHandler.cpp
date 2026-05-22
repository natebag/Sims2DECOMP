// 0x8038B42C GXFinishInterruptHandler (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 3,1; stw 0,0x4(1); stwu 1,-736(1); stw 31,0x2dc(1); addi 31,4,0; lwz 5,-21992(13); lhz 0,0xa(5); rlwimi 0,3,3,28,28; sth 0,0xa(5); lwz 0,-21924(13); stb 3,-21920(13); cmplwi 0,0; beq 0f; addi 3,1,16; bl _s8038B42C_0; addi 3,1,16; bl _s8038B42C_1; lwz 12,-21924(13); mtspr 8,12; blrl; addi 3,1,16; bl _s8038B42C_2; mr 3,31; bl _s8038B42C_3; 0:; addi 3,13,-21916; bl _s8038B42C_4; lwz 0,0x2e4(1); lwz 31,0x2dc(1); addi 1,1,736; mtspr 8,0"
extern "C" void _s8038B42C_0();
extern "C" void _s8038B42C_1();
extern "C" void _s8038B42C_2();
extern "C" void _s8038B42C_3();
extern "C" void _s8038B42C_4();
extern "C" void f_8038B42C() {}
