// 0x802DE9E8 IsSpace(char) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,32; beq 0f; cmpwi 3,9; beq 0f; cmpwi 3,10; beq 0f; cmpwi 3,13; beq 0f; cmpwi 3,12; bne 1f; 0:; li 3,1; blr; 1:; li 3,0"
extern "C" int f_802DE9E8() {}
