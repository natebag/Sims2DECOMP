// 0x8038B0A8 GXDrawDone (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); bl _s8038B0A8_0; li 0,97; lis 5,-13311; lis 4,17664; stb 0,-32768(5); addi 0,4,2; stw 0,-32768(5); mr 31,3; bl _s8038B0A8_1; li 0,0; stb 0,-21920(13); mr 3,31; bl _s8038B0A8_2; bl _s8038B0A8_3; mr 31,3; b 1f; 0:; addi 3,13,-21916; bl _s8038B0A8_4; 1:; lbz 0,-21920(13); cmplwi 0,0; beq 0b; mr 3,31; bl _s8038B0A8_5; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038B0A8_0();
extern "C" void _s8038B0A8_1();
extern "C" void _s8038B0A8_2();
extern "C" void _s8038B0A8_3();
extern "C" void _s8038B0A8_4();
extern "C" void _s8038B0A8_5();
extern "C" void f_8038B0A8() {}
