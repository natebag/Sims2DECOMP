// 0x80282730 AptCharacterAnimation::UnmapCharacter(AptCharacter (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xc(3); li 9,0; cmpw 9,0; bge 2f; lwz 3,0x10(3); mr 11,0; 0:; lwz 0,0x0(3); addi 3,3,4; cmpw 0,4; bne 1f; mr 3,9; blr; 1:; addi 9,9,1; cmpw 9,11; blt 0b; 2:; li 3,-1"
extern "C" int f_80282730() {}
