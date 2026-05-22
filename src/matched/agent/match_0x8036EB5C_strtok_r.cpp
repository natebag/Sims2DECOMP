// 0x8036EB5C strtok_r (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="mr. 3,3; bne 0f; lwz 3,0x0(5); cmpwi 3,0; bne 0f; li 3,0; blr; 0:; lbz 0,0x0(3); mr 11,4; lbz 9,0x0(11); addi 3,3,1; extsb 10,0; addi 11,11,1; extsb 0,9; cmpwi 0,0; beq 2f; 1:; cmpw 10,0; beq 0b; lbz 0,0x0(11); addi 11,11,1; extsb 0,0; cmpwi 0,0; bne 1b; 2:; cmpwi 10,0; bne 3f; stw 10,0x0(5); li 3,0; blr; 3:; addi 8,3,-1; 4:; lbz 0,0x0(3); mr 11,4; addi 3,3,1; li 9,0; extsb 10,0; 5:; lbz 0,0x0(11); addi 11,11,1; extsb 0,0; cmpw 0,10; bne 8f; cmpwi 0,0; bne 6f; li 3,0; b 7f; 6:; stb 9,-1(3); 7:; stw 3,0x0(5); mr 3,8; blr; 8:; cmpwi 0,0; bne 5b; b 4b"
extern "C" void f_8036EB5C() {}
