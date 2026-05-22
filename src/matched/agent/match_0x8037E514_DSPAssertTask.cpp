// 0x8037E514 DSPAssertTask (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s8037E514_0; lwz 4,-22016(13); addi 31,3,0; cmplw 4,30; bne 0f; li 0,1; stw 30,-22032(13); mr 3,31; stw 0,-22036(13); bl _s8037E514_1; mr 3,30; b 3f; 0:; lwz 3,0x4(30); lwz 0,0x4(4); cmplw 3,0; bge 2f; li 0,1; stw 30,-22032(13); stw 0,-22036(13); lwz 0,0x0(4); cmplwi 0,1; bne 1f; bl _s8037E514_2; lis 4,-13312; addi 5,4,20480; lhz 4,0x500a(4); li 0,-169; and 0,4,0; ori 0,0,2; sth 0,0xa(5); bl _s8037E514_3; 1:; mr 3,31; bl _s8037E514_4; mr 3,30; b 3f; 2:; mr 3,31; bl _s8037E514_5; li 3,0; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037E514_0();
extern "C" void _s8037E514_1();
extern "C" void _s8037E514_2();
extern "C" void _s8037E514_3();
extern "C" void _s8037E514_4();
extern "C" void _s8037E514_5();
extern "C" void f_8037E514() {}
