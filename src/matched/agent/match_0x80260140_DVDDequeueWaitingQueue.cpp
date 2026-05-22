// 0x80260140 __DVDDequeueWaitingQueue (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80260140_0; lwz 4,0x4(31); lwz 5,0x0(31); cmplwi 4,0; beq 0f; cmplwi 5,0; bne 1f; 0:; bl _s80260140_1; li 3,0; b 2f; 1:; stw 5,0x0(4); stw 4,0x4(5); bl _s80260140_2; li 3,1; 2:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80260140_0();
extern "C" void _s80260140_1();
extern "C" void _s80260140_2();
extern "C" void f_80260140() {}
