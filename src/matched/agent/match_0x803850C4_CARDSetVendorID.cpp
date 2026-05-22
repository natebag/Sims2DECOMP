// 0x803850C4 CARDSetVendorID (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 0,-25336(13); sth 3,-25336(13); mr 3,0"
extern "C" void f_803850C4() {}
