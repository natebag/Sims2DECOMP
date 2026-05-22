// 0x8013ECBC LogPersonTracker::LogPersonTracker(cXPerson (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; addi 3,31,20; bl _s8013ECBC_0; lwz 11,0x0(30); lwz 9,0x4(11); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,11,3; blrl; bl _s8013ECBC_1; stw 3,0x0(31); lwz 11,0x0(30); lwz 9,0x4(11); lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,11,3; blrl; li 11,-1; li 0,0; sth 3,0x4(31); stw 11,0x10(31); stw 11,0x8(31); sth 0,0xc(31); lwz 9,0x4(30); lha 3,0x148(9); lwz 0,0x14c(9); add 3,30,3; mtspr 8,0; blrl; mr 11,3; addi 9,31,80; li 10,144; 0:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 0b; lwz 0,0x0(11); mr 3,31; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8013ECBC_0();
extern "C" void _s8013ECBC_1();
extern "C" void f_8013ECBC() {}
