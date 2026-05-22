// 0x8035C974 EMsgQueue::GetStats(int (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 29,4; mr 28,5; mr 27,6; mr 26,7; bl _s8035C974_0; stw 3,0x0(29); lwz 0,0x48(30); stw 0,0x0(28); lwz 9,0x44(30); stw 9,0x0(27); lwz 0,0x38(30); stw 0,0x0(26); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8035C974_0();
extern "C" void f_8035C974() {}
