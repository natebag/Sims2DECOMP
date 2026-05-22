// 0x802553EC __OSTimeToSystemTime (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); mr 31,3; mr 30,4; bl _s802553EC_0; lis 5,-32768; lwz 4,0x30dc(5); lwz 0,0x30d8(5); addc 30,4,30; adde 31,0,31; bl _s802553EC_1; mr 4,30; mr 3,31; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802553EC_0();
extern "C" void _s802553EC_1();
extern "C" void f_802553EC() {}
