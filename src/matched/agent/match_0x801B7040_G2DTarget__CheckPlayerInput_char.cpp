// 0x801B7040 G2DTarget::CheckPlayerInput(char (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0xa4(3); cmpwi 0,0; bne 1f; 0:; li 3,0; blr; 1:; lbz 4,0x0(4); addi 0,4,-48; cmplwi 0,1; bgt 0b; extsb 9,4; lwz 3,0x9c(3); addi 9,9,-48; cmpw 9,3; beq 2f; cmpwi 3,2; li 3,0; bnelr; 2:; li 3,1"
extern "C" int f_801B7040() {}
