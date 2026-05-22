// 0x8015BAF4 ObjectDataID::ObjectDataID(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; stw 4,0x0(9); sth 5,0x4(9)"
extern "C" void f_8015BAF4() {}
