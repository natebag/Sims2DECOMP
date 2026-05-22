// 0x80145DA0 TileWalls::TileWalls(TileWallStorage (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 11,0x0(4); mr 9,3; li 10,0; stw 11,0x0(9); lbz 0,0x1(4); stw 0,0x4(9); lbz 11,0x2(4); sth 11,0x8(9); lbz 0,0x3(4); sth 0,0xa(9); lbz 11,0x3(4); sth 11,0x10(9); lbz 0,0x3(4); sth 0,0x12(9); lbz 11,0x4(4); sth 11,0x14(9); lbz 0,0x5(4); sth 0,0x16(9); lbz 11,0x7(4); sth 11,0x18(9); lbz 0,0x6(4); sth 0,0x1a(9); lbz 11,0x6(4); sth 11,0x1c(9); lbz 0,0x7(4); sth 0,0x1e(9); lbz 11,0x6(4); sth 11,0x20(9); lbz 0,0x7(4); stw 10,0x34(9); sth 0,0x22(9); stw 10,0x24(9); stw 10,0x28(9); stw 10,0x2c(9); stw 10,0x30(9)"
extern "C" void f_80145DA0() {}
