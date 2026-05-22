// 0x80116EE8 cHitMan::AddToUpdateList(cTrack (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 30,3; mr 29,4; bl _s80116EE8_0; lwz 0,0x8(30); li 3,12; stw 0,0x10(1); bl _s80116EE8_1; mr 11,3; stw 29,0x8(11); li 3,1; lwz 9,0x10(1); lwz 10,0x4(9); stw 9,0x0(11); stw 10,0x4(11); stw 11,0x0(10); stw 11,0x4(9); stw 11,0x8(1); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80116EE8_0();
extern "C" void _s80116EE8_1();
extern "C" void f_80116EE8() {}
