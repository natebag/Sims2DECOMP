// 0x803927AC __VMPageReplacementLRU (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stw 0,0x34(1); addi 11,1,48; bl _s803927AC_0; lwz 0,-25216(13); li 28,0; lwz 29,-21864(13); li 27,-1; cmpwi 0,0; li 26,-1; li 25,-1; bne 10f; 0:; lwz 3,-21864(13); bl _s803927AC_1; mr. 24,3; beq 9f; bl _s803927AC_2; cmpwi 3,0; beq 9f; mr 3,24; bl _s803927AC_3; mr 30,3; mr 3,24; bl _s803927AC_4; cmpwi 30,0; mr 31,3; bne 1f; cmpwi 31,0; bne 1f; lwz 3,-21864(13); bl _s803927AC_5; cmpwi 3,0; bne 1f; lwz 28,-21864(13); b 11f; 1:; cmpwi 30,0; bne 2f; cmpwi 31,0; beq 2f; cmpwi 27,0; bge 4f; lwz 3,-21864(13); bl _s803927AC_6; cmpwi 3,0; bne 4f; lwz 27,-21864(13); b 4f; 2:; cmpwi 30,0; beq 3f; cmpwi 31,0; bne 3f; cmpwi 26,0; bge 4f; lwz 3,-21864(13); bl _s803927AC_7; cmpwi 3,0; bne 4f; lwz 26,-21864(13); b 4f; 3:; cmpwi 25,0; bge 4f; lwz 3,-21864(13); bl _s803927AC_8; cmpwi 3,0; bne 4f; lwz 25,-21864(13); 4:; cmpwi 30,0; beq 5f; mr 3,24; li 4,0; bl _s803927AC_9; 5:; lwz 3,-21864(13); cmplw 29,3; bne 8f; cmpwi 27,0; blt 6f; mr 28,27; b 11f; 6:; cmpwi 26,0; blt 7f; mr 28,26; b 11f; 7:; cmpwi 25,0; blt 11f; mr 28,25; b 11f; 8:; addi 0,3,1; stw 0,-21864(13); bl _s803927AC_10; lwz 0,-21864(13); cmplw 0,3; blt 0b; li 0,0; stw 0,-21864(13); b 0b; 9:; lwz 28,-21864(13); b 11f; 10:; mr 28,29; 11:; lwz 3,-21864(13); addi 0,3,1; stw 0,-21864(13); bl _s803927AC_11; lwz 0,-21864(13); cmplw 0,3; blt 12f; li 0,0; stw 0,-25216(13); stw 0,-21864(13); 12:; mr 3,28; addi 11,1,48; bl _s803927AC_12; lwz 0,0x34(1); mtspr 8,0; addi 1,1,48"
extern "C" void _s803927AC_0();
extern "C" void _s803927AC_1();
extern "C" void _s803927AC_2();
extern "C" void _s803927AC_3();
extern "C" void _s803927AC_4();
extern "C" void _s803927AC_5();
extern "C" void _s803927AC_6();
extern "C" void _s803927AC_7();
extern "C" void _s803927AC_8();
extern "C" void _s803927AC_9();
extern "C" void _s803927AC_10();
extern "C" void _s803927AC_11();
extern "C" void _s803927AC_12();
extern "C" void f_803927AC() {}
