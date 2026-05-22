// 0x802C6B1C EFileSystem::FileCreator::operator==(EFileSystem::FileCreator (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(3); li 11,0; lwz 0,0x0(4); cmpw 9,0; bne 0f; lwz 9,0x4(3); lwz 0,0x4(4); cmpw 9,0; bne 0f; lwz 9,0x8(3); lwz 0,0x8(4); cmpw 9,0; bne 0f; lwz 9,0xc(3); lwz 0,0xc(4); cmpw 9,0; bne 0f; lwz 9,0x10(3); lwz 0,0x10(4); xor 11,9,0; subfic 10,11,0; adde 11,10,11; 0:; mr 3,11"
extern "C" int f_802C6B1C() {}
