// 0x801858FC GetTutorialLocks(int) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 3,3,1; li 0,0; cmpwi 3,7; bgt 0f; addi 9,13,-21176; lbzx 0,3,9; 0:; mr 3,0"
extern "C" int f_801858FC() {}
