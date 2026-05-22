// 0x8037B174 AXSetVoiceDpop (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); addi 30,4,0; stw 29,0x14(1); addi 29,3,0; addi 31,29,394; bl _s8037B174_0; lhz 0,0x0(30); sth 0,0x0(31); lhz 0,0x2(30); sth 0,0x2(31); lhz 0,0x4(30); sth 0,0x4(31); lhz 0,0x6(30); sth 0,0x6(31); lhz 0,0x8(30); sth 0,0x8(31); lhz 0,0xa(30); sth 0,0xa(31); lhz 0,0xc(30); sth 0,0xc(31); lhz 0,0xe(30); sth 0,0xe(31); lhz 0,0x10(30); sth 0,0x10(31); lwz 0,0x1c(29); ori 0,0,256; stw 0,0x1c(29); bl _s8037B174_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037B174_0();
extern "C" void _s8037B174_1();
extern "C" void f_8037B174() {}
