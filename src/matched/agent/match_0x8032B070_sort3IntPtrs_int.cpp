// 0x8032B070 sort3IntPtrs(int (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lwz 10,0x4(3); lwz 9,0x0(11); lwz 0,0x0(10); cmpw 9,0; ble 0f; stw 11,0x4(3); stw 10,0x0(3); 0:; lwz 11,0x4(3); lwz 10,0x8(3); lwz 9,0x0(11); lwz 0,0x0(10); cmpw 9,0; ble 1f; stw 11,0x8(3); stw 10,0x4(3); 1:; lwz 10,0x0(3); lwz 11,0x4(3); lwz 9,0x0(10); lwz 0,0x0(11); cmpw 9,0; blelr; stw 11,0x0(3); stw 10,0x4(3)"
extern "C" void f_8032B070() {}
