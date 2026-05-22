// 0x802616EC DVDLowWaitCoverClose (44 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; stw 3,-23352(13); lis 3,-13312; stw 0,-23332(13); li 0,0; addi 4,3,24576; stw 0,-23360(13); li 0,2; li 3,1; stw 0,0x4(4)"
extern "C" void f_802616EC() {}
