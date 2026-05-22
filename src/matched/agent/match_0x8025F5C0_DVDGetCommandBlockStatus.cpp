// 0x8025F5C0 DVDGetCommandBlockStatus (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s8025F5C0_0; lwz 0,0xc(31); cmpwi 0,3; bne 0f; li 31,1; b 1f; 0:; mr 31,0; 1:; bl _s8025F5C0_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8025F5C0_0();
extern "C" void _s8025F5C0_1();
extern "C" void f_8025F5C0() {}
