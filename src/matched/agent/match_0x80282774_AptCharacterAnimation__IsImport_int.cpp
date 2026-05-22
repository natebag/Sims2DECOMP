// 0x80282774 AptCharacterAnimation::IsImport(int) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x20(3); li 11,0; cmpw 11,0; bge 2f; lwz 9,0x24(3); mr 10,0; addi 3,9,8; 0:; lwz 0,0x0(3); addi 3,3,16; cmpw 0,4; bne 1f; mr 3,11; blr; 1:; addi 11,11,1; cmpw 11,10; blt 0b; 2:; li 3,-1"
extern "C" int f_80282774() {}
