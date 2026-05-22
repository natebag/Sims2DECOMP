// 0x800D53E4 NghResFile::GetThumbIdFromFamilyAndIndex(int, (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,4; cmpwi 3,1; bne 0f; cmpwi 5,1; bne 0f; li 3,3; blr; 0:; cmpwi 4,4; blelr; addi 3,4,-20; rlwinm 0,3,2,0,29; add 3,0,5; addi 3,3,5"
extern "C" int f_800D53E4() {}
