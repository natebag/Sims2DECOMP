// 0x8015BB6C ObjectDataID::operator==(ObjectDataID (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 11,0; lwz 0,0x0(4); cmpw 9,0; bne 0f; lhz 9,0x4(3); lhz 0,0x4(4); xor 11,9,0; subfic 10,11,0; adde 11,10,11; 0:; mr 3,11"
extern "C" int f_8015BB6C() {}
