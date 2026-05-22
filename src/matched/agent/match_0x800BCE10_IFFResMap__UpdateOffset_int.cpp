// 0x800BCE10 IFFResMap::UpdateOffset(int, (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 5,5; bge 1f; li 3,0; blr; 0:; subf 0,5,0; li 3,1; stw 0,0x0(9); blr; 1:; lwz 9,0x4(3); lwz 3,0x0(3); cmpw 3,9; beq 5f; mr 10,9; 2:; lwz 9,0x0(3); lwz 11,0x4(3); cmpw 9,11; beq 4f; 3:; lwz 0,0x0(9); cmpw 0,4; beq 0b; addi 9,9,88; cmpw 9,11; bne 3b; 4:; addi 3,3,24; cmpw 3,10; bne 2b; 5:; li 3,0"
extern "C" void f_800BCE10() {}
