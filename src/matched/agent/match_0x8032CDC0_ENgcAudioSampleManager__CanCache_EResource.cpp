// 0x8032CDC0 ENgcAudioSampleManager::CanCache(EResource (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beq 0f; lwz 9,0x1c(4); li 3,0; lwz 0,-25828(13); cmpw 9,0; beqlr; 0:; li 3,1"
extern "C" int f_8032CDC0() {}
