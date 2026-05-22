// 0x8037A6D0 __AXDumpVPB (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; lwz 4,0x18(3); lis 3,-32690; addi 0,3,29248; mulli 3,4,244; add 3,0,3; lhz 0,0xe(3); addi 31,3,0; cmplwi 0,1; bne 0f; mr 3,31; bl _s8037A6D0_0; 0:; li 0,0; sth 0,0x4c(31); mr 3,30; sth 0,0x4a(31); sth 0,0x48(31); sth 0,0x46(31); sth 0,0x44(31); sth 0,0xe(31); sth 0,0x146(30); bl _s8037A6D0_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037A6D0_0();
extern "C" void _s8037A6D0_1();
extern "C" void f_8037A6D0() {}
