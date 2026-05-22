// 0x8037A9D8 __AXSetPBDefault (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 5,0; sth 5,0x146(3); lis 4,32; addi 4,4,164; sth 5,0x16e(3); addi 0,3,52; stw 4,0x1c(3); stw 5,0x28(3); stw 5,0x24(3); stw 0,0x30(3); sth 5,0x184(3); sth 5,0x182(3); sth 5,0x180(3); sth 5,0x17e(3); sth 5,0x17c(3); sth 5,0x1f2(3)"
extern "C" void f_8037A9D8() {}
