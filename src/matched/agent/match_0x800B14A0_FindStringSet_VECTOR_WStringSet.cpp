// 0x800B14A0 FindStringSet(VECTOR<WStringSet> (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x0(3); li 11,0; cmpwi 3,0; beq 0f; lwz 11,-4(3); 0:; li 10,0; cmpwi 11,0; bne 1f; li 3,0; 1:; li 9,0; b 3f; 2:; addi 9,9,1; addi 3,3,12; 3:; cmpw 9,11; bge 4f; lwz 0,0x4(3); cmpw 0,5; bne 2b; lha 0,0x8(3); cmpw 0,4; bne 2b; mr 10,3; 4:; mr 3,10"
extern "C" int f_800B14A0() {}
