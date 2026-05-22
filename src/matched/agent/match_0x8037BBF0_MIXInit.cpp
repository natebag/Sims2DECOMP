// 0x8037BBF0 MIXInit (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32688; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); lis 30,20480; stw 29,0xc(1); addi 29,3,-30144; stw 28,0x8(1); li 28,0; 0:; stw 30,0x4(29); li 31,0; li 5,-960; stw 31,0x8(29); li 4,64; li 0,127; stw 5,0xc(29); mr 3,29; stw 5,0x10(29); stw 31,0x1c(29); stw 4,0x14(29); stw 0,0x18(29); sth 31,0x5c(29); sth 31,0x58(29); sth 31,0x54(29); sth 31,0x50(29); sth 31,0x4c(29); sth 31,0x48(29); sth 31,0x44(29); sth 31,0x40(29); sth 31,0x3c(29); sth 31,0x38(29); bl _s8037BBF0_0; addi 28,28,1; cmpwi 28,64; addi 29,29,96; blt 0b; li 0,1; stw 31,-22072(13); stw 31,-22068(13); stw 0,-22064(13); lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); lwz 29,0xc(1); lwz 28,0x8(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037BBF0_0();
extern "C" void f_8037BBF0() {}
