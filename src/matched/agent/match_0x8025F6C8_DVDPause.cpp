// 0x8025F6C8 DVDPause (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s8025F6C8_0; lwz 0,-23480(13); li 4,1; stw 4,-23468(13); cmplwi 0,0; bne 0f; stw 4,-23464(13); 0:; bl _s8025F6C8_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8025F6C8_0();
extern "C" void _s8025F6C8_1();
extern "C" void f_8025F6C8() {}
