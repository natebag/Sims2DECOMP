// 0x80256328 __OSCheckMutexes (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; lwz 31,0x2f4(3); b 3f; 0:; lwz 0,0x8(31); cmplw 0,30; beq 1f; li 3,0; b 4f; 1:; mr 3,31; bl _s80256328_0; cmpwi 3,0; bne 2f; li 3,0; b 4f; 2:; lwz 31,0x10(31); 3:; cmplwi 31,0; bne 0b; li 3,1; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80256328_0();
extern "C" void f_80256328() {}
