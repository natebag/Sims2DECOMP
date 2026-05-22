// 0x80324510 EControllerManager::BitToIndex(unsigned (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,3; li 3,0; rlwinm. 0,9,31,1,31; beqlr; 0:; addi 3,3,1; addi 0,3,1; srw. 11,9,0; bne 0b"
extern "C" int f_80324510() {}
