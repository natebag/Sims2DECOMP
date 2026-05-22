// 0x8015BB34 ObjectDataID::operator<(ObjectDataID (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 11,0; lwz 0,0x0(4); cmplw 9,0; blt 0f; cmpw 9,0; bne 1f; lhz 9,0x4(3); lhz 0,0x4(4); cmplw 9,0; bge 1f; 0:; li 11,1; 1:; mr 3,11"
extern "C" int f_8015BB34() {}
