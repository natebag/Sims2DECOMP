// 0x802642B4 VISetBlack (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,-16744; stw 30,0x18(1); addi 30,3,0; bl _s802642B4_0; stw 30,0x130(31); mr 30,3; lwz 10,0x144(31); lwz 0,0x130(31); stw 0,0x8(1); lhz 3,0xfa(31); lhz 4,0xf6(31); lbz 5,0x0(10); lhz 6,0x2(10); lhz 7,0x4(10); lhz 8,0x6(10); lhz 9,0x8(10); lhz 10,0xa(10); bl _s802642B4_1; mr 3,30; bl _s802642B4_2; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s802642B4_0();
extern "C" void _s802642B4_1();
extern "C" void _s802642B4_2();
extern "C" void f_802642B4() {}
