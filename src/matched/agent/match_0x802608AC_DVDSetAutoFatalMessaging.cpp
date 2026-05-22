// 0x802608AC DVDSetAutoFatalMessaging (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s802608AC_0; lwz 0,-23384(13); cmplwi 0,0; beq 0f; li 31,1; b 1f; 0:; li 31,0; 1:; cmpwi 30,0; beq 2f; lis 4,-32730; addi 0,4,2080; b 3f; 2:; li 0,0; 3:; stw 0,-23384(13); bl _s802608AC_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802608AC_0();
extern "C" void _s802608AC_1();
extern "C" void f_802608AC() {}
