// 0x80329868 calcWeightSum(int (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,0; cmpw 9,4; bge 1f; mtspr 9,4; 0:; lwz 0,0x0(3); addi 3,3,4; add 9,9,0; bdnz 0b; 1:; cmpwi 9,0; bne 2f; li 9,1; 2:; mr 3,9"
extern "C" int f_80329868() {}
