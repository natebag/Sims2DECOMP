// 0x8037BB58 __MIXResetChannel (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 6,0; stw 0,0x4(1); lis 0,20480; li 5,-960; stwu 1,-8(1); li 4,64; stw 0,0x4(3); li 0,127; stw 6,0x8(3); stw 5,0xc(3); stw 5,0x10(3); stw 6,0x1c(3); stw 4,0x14(3); stw 0,0x18(3); sth 6,0x5c(3); sth 6,0x58(3); sth 6,0x54(3); sth 6,0x50(3); sth 6,0x4c(3); sth 6,0x48(3); sth 6,0x44(3); sth 6,0x40(3); sth 6,0x3c(3); sth 6,0x38(3); bl _s8037BB58_0; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s8037BB58_0();
extern "C" void f_8037BB58() {}
