// 0x803920E8 __GXSetBWDials (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 8,-13312; addi 8,8,16384; sth 3,0x12(8); sth 4,0x14(8); sth 5,0x16(8); sth 6,0x18(8); sth 7,0x1a(8)"
extern "C" void f_803920E8() {}
