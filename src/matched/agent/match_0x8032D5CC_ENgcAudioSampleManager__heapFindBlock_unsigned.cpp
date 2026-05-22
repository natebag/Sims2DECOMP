// 0x8032D5CC ENgcAudioSampleManager::heapFindBlock(unsigned (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0xd20(3); cmpwi 3,0; beqlr; lwz 0,0x10(3); cmpw 0,4; beqlr; 0:; lwz 3,0x4(3); cmpwi 3,0; beqlr; lwz 0,0x10(3); cmpw 0,4; bne 0b"
extern "C" int f_8032D5CC() {}
