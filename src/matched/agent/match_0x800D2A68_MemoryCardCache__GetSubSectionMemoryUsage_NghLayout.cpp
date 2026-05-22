// 0x800D2A68 MemoryCardCache::GetSubSectionMemoryUsage(NghLayout (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x4(3); li 3,0; cmpwi 11,0; beqlr; rlwinm 9,5,2,0,29; lwzx 11,9,11; cmpwi 11,0; beqlr; cmplwi 5,1; bgt 0f; mulli 9,5,24; lwz 0,0x4(4); add 9,9,0; lwz 3,0x4(9); blr; 0:; lwz 9,0x4(11); lwz 0,0xc(11); add 3,0,9"
extern "C" int f_800D2A68() {}
