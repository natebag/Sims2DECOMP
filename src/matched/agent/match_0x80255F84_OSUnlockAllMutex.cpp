// 0x80255F84 __OSUnlockAllMutex (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); li 31,0; stw 30,0x10(1); addi 30,3,0; b 3f; 0:; lwz 5,0x10(4); addi 3,4,0; cmplwi 5,0; bne 1f; stw 31,0x2f8(30); b 2f; 1:; stw 31,0x14(5); 2:; stw 5,0x2f4(30); stw 31,0xc(4); stw 31,0x8(4); bl _s80255F84_0; 3:; lwz 4,0x2f4(30); cmplwi 4,0; bne 0b; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80255F84_0();
extern "C" void f_80255F84() {}
