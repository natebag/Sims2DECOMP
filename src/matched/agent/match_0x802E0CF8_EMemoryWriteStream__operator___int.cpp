// 0x802E0CF8 EMemoryWriteStream::operator[](int) (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 9,4; cmpwi 4,0; bge 0f; addi 9,4,4095; 0:; lwz 8,0x20(3); srawi 9,9,12; rlwinm 9,9,2,0,29; rlwinm 10,4,0,20,31; lwzx 11,8,9; lbzx 3,11,10"
extern "C" int f_802E0CF8() {}
